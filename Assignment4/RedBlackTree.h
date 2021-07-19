#pragma once

#include <vector>
#include <string>
using std::vector;
using std::string;

// debugging
#include <iostream>
using std::cout;
using std::endl;

// ----------------------------------------------------------------------------------------------------------------------
// Part 1 - Red Black Tree
// ----------------------------------------------------------------------------------------------------------------------


// Red black tree node class
class NodeT
{
public:
	int data;
	NodeT* left;
	NodeT* right;
	NodeT* parent;
	bool isBlack; // true if node is black, false if node is red
	NodeT(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr), isBlack(false) {};
};


// -----------------------------------------------------------------------------------------------
// Class Declarations
// -----------------------------------------------------------------------------------------------

// red black tree class declarations
class RedBlackTree
{
public:
	// default constructor
	RedBlackTree();

	// Copy constructor
	// PRE: calling object not initialized yet
	// POST: Copying the contents of rbTree to the calling object
	RedBlackTree(const RedBlackTree& rbTree);

	// Overloaded assignment operator
	// PRE: calling object may contain contents
	// POST: Copying the contents of rbTree to the calling object
	RedBlackTree& operator=(const RedBlackTree& rbTree);

	// destructor
	// POST: all the memory will be de-allocated
	~RedBlackTree();

	// insert
	bool insert(const int value);
	bool remove(const int value);
	bool search(const int value) const;
	vector<int> search(int value1, int value2) const;
	int closestLess(const int value) const;
	int closestGreater(const int value) const;
	vector<int> values() const;
	int size() const;

	// foe debugging
	void preOrderPrint() const;
	void inOrderPrint() const;

	//template <class Tjwme>
	//friend NodeT<Tjwme>* JWMEgetRoot(const RedBlackTree<Tjwme>& rbt);


private:
	NodeT* root;
	int curSize;

	// private methods
	void copyRedBlackTree(NodeT* node);
	void clear(NodeT* node);
	NodeT* searchNodeAndReturn(const int value) const;
	void inOrderTraversal(NodeT* node, vector<int>& result, const int & smallestValue, const int & largestValue) const;
	NodeT* bstInsert(int value);
	void leftRotate(NodeT* node);
	void rightRotate(NodeT* node);
	NodeT* predecessor(NodeT* node) const;
	NodeT* successor(NodeT* node) const;
	void rbTreeFix(NodeT* node, NodeT* parent);

	// for debugging
	void preOrderPrint(NodeT* nd) const;
	void inOrderPrint(NodeT* nd) const;
};


// -----------------------------------------------------------------------------------------------
// Method Implementations
// -----------------------------------------------------------------------------------------------


// RedBlackTree class definitions

// Default constructor
RedBlackTree::RedBlackTree() 
{
	root = nullptr;
	curSize = 0;
}


// Copy constructor
// PRE: calling object not initialized yet
// POST: Copying the contents of rbTree to the calling object
RedBlackTree::RedBlackTree(const RedBlackTree& rbTree)
{
	// initializing the red black tree attributes for the calling object
	root = nullptr;
	curSize = 0;
	copyRedBlackTree(rbTree.root); // copying operation starting with root
}


// Overloaded assignment operator
// PRE: calling object may contain contents
// POST: Copying the contents of rbTree to the calling object
RedBlackTree& RedBlackTree::operator=(const RedBlackTree& rbTree) 
{
	if (this != &rbTree)
	{
		// need to clean up the calling object before copying
		clear(root); // clean up starting from the calling obejct root node
		copyRedBlackTree(rbTree.root); // copying starting from the parameter object rbTree's root node
	}
	return *this;
}


// destructor
// POST: all the memory will be de-allocated
RedBlackTree::~RedBlackTree() 
{
	clear(root);
}


// Insert a value to the tree
// PARAM: value - value to be inserted
// POST: Return true after value is inserted. If tree already has value, then don't insert and return false
// NOTE: The following nodes are used,
//			node: node to be inserted (node cannot be nullptr)
//			uncle: uncle of node (uncle could be nullptr)
bool RedBlackTree::insert(const int value) 
{
	// when value is already in the tree, don't insert
	if (search(value)) {
		return false;
	}

	// insert a node with value, and its color is already red
	NodeT* node = bstInsert(value);

	// if node is not a root, then node's parent cannot be a nullptr
	// if node parent is red, then node grand parent cannot be a nullptr
	while (node != root && node->parent->isBlack == false) // if node is not a root and node is red
	{
		// if node's parent is the left child of its grand parent
		if (node->parent == node->parent->parent->left) {
			NodeT* uncle = node->parent->parent->right;

			// seg fault when uncle is nullptr, so use flag and do short circuit evaluation
			bool uncleIsBlack = false;
			if (uncle == nullptr || uncle->isBlack) {
				uncleIsBlack = true;
			}
			if (!uncleIsBlack) // if uncle is red
			{
				node->parent->isBlack = true; // make parent black
				uncle->isBlack = true; // make uncle black
				node->parent->parent->isBlack = false; // make grand parent red
				node = node->parent->parent;
			}
			// if uncle is black
			else {
				if (node == node->parent->right) {
					node = node->parent;
					leftRotate(node);
				}
				node->parent->isBlack = true; // make parent black
				node->parent->parent->isBlack = false; // make grand parent red
				rightRotate(node->parent->parent);
			}
		}
		// if node's parent is the right child of its grand parent --> symmetric to the left child case
		else {
			NodeT* uncle = node->parent->parent->left;

			bool uncleIsBlack = false;
			if (uncle == nullptr || uncle->isBlack) {
				uncleIsBlack = true;
			}
			if (!uncleIsBlack) // if uncle is red
			{
				node->parent->isBlack = true;
				uncle->isBlack = true;
				node->parent->parent->isBlack = false;
				node = node->parent->parent;
			}
			// if uncle is black
			else {
				if (node == node->parent->left) {
					node = node->parent;
					rightRotate(node);
				}
				node->parent->isBlack = true;
				node->parent->parent->isBlack = false;
				leftRotate(node->parent->parent);
			}
		}
	}

	root->isBlack = true; // root should always be black
	
	return true; // value was inserted, so return true
}



// Remove the value in the RedBlackTree
// PARAM: value - value to be removed
// POST: Return true after value is removed. If tree does not contain a value, then return false
// NOTE: The following nodes are used:
//		node: Node to be removed. Actually, the value will be overwritten by toBeRemoved.
//		toBeRemoved: Node to be actually removed. It can be either node itself or predecessor. The value will be copied into node.
//		child: The child node of toBeRemoved.
bool RedBlackTree::remove(const int value)
{
	// search for the value
	NodeT* node = searchNodeAndReturn(value);

	// if value is not in the tree
	if (node == nullptr) {
		return false;
	}

	// node that will be removed. Its content will be copied into the node
	NodeT* toBeRemoved;
	// if node has one or no children
	if (node->left == nullptr || node->right == nullptr) {
		toBeRemoved = node;
	}
	else { // node has two children
		toBeRemoved = predecessor(node);
	}

	// if toBeRemoved has a left child, left child becomes child node
	// if toBeRemoved doesn't have a left child, right child becomes child node regardless of being nullptr
	NodeT* child;
	if (toBeRemoved->left != nullptr) {
		child = toBeRemoved->left;
	}
	else {
		child = toBeRemoved->right;
	}

	// child's parent becomes toBeRemoved's parent (i.e. skipping toBeRemoved node)
	// if child is nullptr, no action needed
	if (child != nullptr) {
		child->parent = toBeRemoved->parent;
	}

	// if toBeRemoved is the root (i.e. node is also a root)
	if (toBeRemoved->parent == nullptr) {
		root = child;
	}
	// if toBeRemoved is not root
	else 
	{
		// conneting child to toBeRemoved node's parent
		if (toBeRemoved == toBeRemoved->parent->left) 
		{
			toBeRemoved->parent->left = child;
		}
		else {
			toBeRemoved->parent->right = child;
		}
	}
	
	if (toBeRemoved != node) {
		node->data = toBeRemoved->data; // data is now copied into the node
	}

	if (toBeRemoved->isBlack) {
		rbTreeFix(child, toBeRemoved->parent);
	}

	// free the memory for the removed node toBeRemoevd, and decrement size of the tree
	delete toBeRemoved;
	curSize--;
	return true;

}


// Search the value in the RedBlackTree
// PARAM: value - value tha we went to search in the tree
// POST: Return true if value is found, otherwise, return false.
bool RedBlackTree::search(const int value) const
{
	NodeT* node = searchNodeAndReturn(value);
	if (node == nullptr) {
		return false;
	}
	else {
		return true;
	}
}


// Search the values within the specified range [value1, value2] if value1 <= value2 OR 
//												[value2, value1] if value2 > value1 OR
//												[value1, value1] if value1 == value2 in the RedBlackTree
// PARAM: value1 and value2 determines the range [value1, value2] or [value2, value1] or [value1, value1]
// POST: Return the vector of range [value1, value2] or [value2, value1] or [value1, value1]. value1 and value2 are inclusive.
// vector is in ascending order (smallest to largest)
vector<int> RedBlackTree::search(const int value1, const int value2) const
{
	vector<int> result;

	// if value1 or value2 are not contained in the tree, no push_back is performed on the vector result,
	// but traversing the entire tree will occur
	if (value1 <= value2) {
		inOrderTraversal(root, result, value1, value2);
	}
	else {
		inOrderTraversal(root, result, value2, value1);
	}

	return result;
}


// Find a largest possible value that is less than the parameter value
// PARAM: value - value to be compared with the contents in the red black tree
// POST: Return a value that is less the parameter value. 
//		 If there is no value less than the parameter value, return the parameter value itself.
int RedBlackTree::closestLess(const int value) const
{
	int result = value;

	NodeT* node = root; // starting from root node to search
	// while condition is search for value until node becomes nullptr, i.e., end of tree
	while (node != nullptr) 
	{
		// if node's data is greater than or equal to the parameter value, 
		// don't update the result but go to left child to find a smaller value if there is
		if (node->data >= value) {
			node = node->left;
		}
		// if node's data is less than the parameter value, 
		// update the result and go to right child to find a larger value if there is
		else {
			result = node->data;
			node = node->right;
		}
	}
	return result;
}



// Find a smallest possible value that is greater than the parameter value
// PARAM: value - value to be compared with the contents in the red black tree
// POST: Return a value that is greater the parameter value. 
//		 If there is no value greater than the parameter value, return the parameter value itself.
int RedBlackTree::closestGreater(const int value) const
{
	int result = value;

	NodeT* node = root; // starting from root node to search
	// while condition is search for value until node becomes nullptr, i.e., end of tree
	while (node != nullptr)
	{
		// if node's data is less than or equal to the parameter value, 
		// don't update the result but go to right child to find a larger value if there is
		if (node->data <= value) {
			node = node->right;
		}
		// if node's data is greater than the parameter value, 
		// update the result and go to left child to find a smaller value if there is
		else {
			result = node->data;
			node = node->left;
		}
	}
	return result;
}


// Return a vector of all values in ascending order. If tree is empty, returned vector is also empty.
vector<int> RedBlackTree::values() const
{
	vector<int> result;

	// if the tree is empty, return the empty vector
	if (root == nullptr) {
		return result;
	}

	int smallestValue, largestValue;

	NodeT* node = root; // starting from root node to search
	// find a smallest value
	while (node != nullptr) {
		smallestValue = node->data; // update the smallest value
		node = node->left; // go to left child to find a smaller value if there is
	}

	node = root; // Again, starting from root node to search
	// find a largest value
	while (node != nullptr) {
		largestValue = node->data; // update the largest value
		node = node->right; // go to right child to find a larger value if there is
	}

	// traversing the entire tree from smallest value to largest value, and update the vector result 
	inOrderTraversal(root, result, smallestValue, largestValue);
	return result;
}


// Return the size of the tree, i.e., the number of items in the tree
int RedBlackTree::size() const
{
	return curSize;
}


// -----------------------------------------------------------------------------------------------
// Helper Methods
// -----------------------------------------------------------------------------------------------


// private helper method for the copying Red black Tree used in copy constructor and overloaded assignment operator
// inserting elements with the pre-order traversal
void RedBlackTree::copyRedBlackTree(NodeT* node)
{
	if (node != nullptr) {
		NodeT* newNode = bstInsert(node->data);
		newNode->isBlack = node->isBlack;
		copyRedBlackTree(node->left);
		copyRedBlackTree(node->right);
	}
}


// Empties tree
// PRE:
// PARAM: node - This should be root during the 1st call
// POST: Removes all nodes from tree, deallocates dynamic memory
void RedBlackTree::clear(NodeT* node)
{
	if (node != nullptr) {
		clear(node->left);
		clear(node->right);
	
		// deallocate the memory for the ndoe and decrement the size
		delete node;
		curSize--;
	}
}


// Search for the node corresponding to the parameter value and return the node
// PARAM: value - value to be searched for the node
// POST: If found, return the node. If not found, return the nullptr.
NodeT* RedBlackTree::searchNodeAndReturn(const int value) const
{
	// search for the value
	NodeT* node = root; // starting from root node to search
	// while condition is search for value until node becomes nullptr, i.e., end of tree
	while (node != nullptr) {
		if (value == node->data) {
			break;
		}
		else if (value < node->data) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}
	return node;
}


// traversing the entire tree and push back the value if smallestValue <= value <= largestValue
// PARAM: 
//			Node: node to be used to traversing
//			result:  vector result to be updated recursively
//			smallestValue: lower bound of the range
//			largestValue: upper bound of the range
// POST: vector result is updated, containing all the values in the tree in the range [smallestValue, largestValue]
void RedBlackTree::inOrderTraversal(NodeT* node, vector<int>& result, const int& smallestValue, const int& largestValue) const
{
	if (node != nullptr) {
		inOrderTraversal(node->left, result, smallestValue, largestValue);
		if (node->data >= smallestValue && node->data <= largestValue) {
			result.push_back(node->data);
		}
		inOrderTraversal(node->right, result, smallestValue, largestValue);
	}
}


// Modified BST insertion method adapted for Red Black Tree
// PARAM: value - value to be inserted
// POST: Node with value will be inserted to the tree but no recoloring or rotation performed. Inserted node will be returned.
NodeT* RedBlackTree::bstInsert(int value)
{
	NodeT* newNode = new NodeT(value);
	NodeT* parent = root;
	NodeT* insertionPoint = root;

	if (root == nullptr) // if tree is empty 
	{
		newNode->isBlack = true; // make the color black for the root node
		root = newNode;
	}
	else {// for non-empty case
		// Find the parent of the new node
		while (insertionPoint != nullptr) {
			parent = insertionPoint;
			if (value < parent->data) {
				insertionPoint = parent->left;
			}
			else {
				insertionPoint = parent->right;
			}
		}
		// Insert new node as child of parent
		if (value < parent->data) {
			parent->left = newNode;
		}
		else {
			parent->right = newNode;
		}
		
		// finally added parent
		newNode->parent = parent;
	}

	// increment the size
	curSize++;

	return newNode;
}


// Left roate around the node
void RedBlackTree::leftRotate(NodeT* node) 
{
	NodeT* rightChild = node->right;
	node->right = rightChild->left; // right grand left child becomes node's right child

	// if the right grand left child is not null, node becomes the right grand left child's parent 
	if (rightChild->left != nullptr) {
		rightChild->left->parent = node;
	}

	// node's parent becoems the right child's parent
	rightChild->parent = node->parent;

	// if the node is root, right child becomes root
	if (node->parent == nullptr)  
	{
		root = rightChild;
	}
	// if the node is left child of its parent, right child of its node becomes node's parent's left child
	else if (node == node->parent->left) 
	{
		node->parent->left = rightChild;
	}
	// if the node is left child of its parent, right child of its node becomes node's parent's right child
	else {
		node->parent->right = rightChild;
	}

	rightChild->left = node; // node becomes left child of its own right child
	node->parent = rightChild; // right child becomes node's parent
}


// Right roate around the node ... symmetric to the leftRotate
void RedBlackTree::rightRotate(NodeT* node)
{
	NodeT* leftChild = node->left;
	node->left = leftChild->right;

	if (leftChild->right != nullptr) {
		leftChild->right->parent = node;
	}

	leftChild->parent = node->parent;

	if (node->parent == nullptr)
	{
		root = leftChild;
	}
	else if (node == node->parent->right)
	{
		node->parent->right = leftChild;
	}
	else {
		node->parent->left = leftChild;
	}

	leftChild->right = node;
	node->parent = leftChild;
}


// PRE: Assume that node is not nullptr
// PARAM: node to start with searching for the predecessor
// POST: Returning the predecessor node
NodeT* RedBlackTree::predecessor(NodeT* node) const 
{
	if (node == nullptr) { // in case if nullptr is passed as a mistake, just return nullptr
		return node;
	}

	// if left subtree don't exist, just return the own node
	if (node->left == nullptr) {
		return node;
	}
	// left subtree exists
	node = node->left; // first go to left child
	// Second, keep going to the right until node's right child is nullptr
	while (node->right != nullptr) {
		node = node->right;
	}
	return node;
}


// PRE: Assume that node is not nullptr
// PARAM: node to start with searching for the successor
// POST: Returning the successor node
NodeT* RedBlackTree::successor(NodeT* node) const
{
	if (node == nullptr) { // in case if nullptr is passed as a mistake, just return nullptr
		return node;
	}

	// if right subtree doesnt't exist, just return the own node
	if (node->right == nullptr) {
		return node;
	}
	// right subtree exists
	node = node->right; // first go to right child
	// Second, keep going to the left until node's left child is nullptr
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}



// Red black tree fixing process during the node removal in the red black tree
// PRE: Red Black Tree properties are violated
// PARAM: 
//		node: child of the removed node, which could be nullptr
//		parent: node's parent (which cannot be a nullptr)
// POST: Red Black Tree is fixed and its properties are maintained
void RedBlackTree::rbTreeFix(NodeT* node, NodeT* parent) 
{
	// use boolean flag for the nullptr
	bool nodeIsBlack = false;
	// if node is black (could be nullptr), perform fixing process
	// Use short circuit evaluation to avoid segmentation fault
	if (node == nullptr || node->isBlack) {
		nodeIsBlack = true;
	}
	while (node != root && nodeIsBlack)
	{
		NodeT* sibling; // can this be nullptr??
		// if node is a left child, sibling is right child and vice versa
		if (node == parent->left) {
			sibling = parent->right;

			if (sibling->isBlack == false) { // if sibling is red
				sibling->isBlack = true; // make sibling black
				parent->isBlack = false; // make parent red
				leftRotate(parent);
				sibling = parent->right;
			}

			// sibling's two childs are both black OR either is nullptr.
			// Use flags to deal with nullptr
			// Use short circuit evaluation to avoid segmentation fault
			bool nodeLeftIsBlack = false;
			bool nodeRightIsBlack = false;
			if (sibling->left == nullptr || sibling->left->isBlack) {
				nodeLeftIsBlack = true;
			}
			if (sibling->right == nullptr || sibling->right->isBlack) {
				nodeRightIsBlack = true;
			}
			if (nodeLeftIsBlack && nodeRightIsBlack)
			{
				sibling->isBlack = false; // make sibling red
				node = parent; // update node
				parent = node->parent; // update parent (note that parent cannot be a nullptr)
			}
			// sibling's two childs are not both black, OR either of them is red or nullptr
			else {
				// if sibling's right child is black or nullptr, then sibling's left child is red (should not be a nullptr)
				if (sibling->right == nullptr || sibling->right->isBlack) {
					sibling->left->isBlack = true; // making sibling's left child black (sibling's left child cannot be a nullptr)
					sibling->isBlack = false;
					rightRotate(sibling);
					sibling = parent->right;
				}
				sibling->isBlack = parent->isBlack; // makiing sibling color same as parent color
				parent->isBlack = true; // maing parent black
				if (sibling->right != nullptr) { // if sibling's right child is nullptr, no need to make it black
					sibling->right->isBlack = true;
				}
				leftRotate(parent);
				node = root;
				parent = node->parent; // update parent (note that parent cannot be a nullptr)
			}
		}

		// symmetric to the case when the node is left child
		// when the node is right child, sibling is left child
		else {
			sibling = parent->left;

			if (sibling->isBlack == false) {
				sibling->isBlack = true;
				parent->isBlack = false;
				rightRotate(parent);
				sibling = parent->left;
			}

			bool nodeLeftIsBlack = false;
			bool nodeRightIsBlack = false;
			if (sibling->left == nullptr || sibling->left->isBlack) {
				nodeLeftIsBlack = true;
			}
			if (sibling->right == nullptr || sibling->right->isBlack) {
				nodeRightIsBlack = true;
			}
			if (nodeLeftIsBlack && nodeRightIsBlack)
			{
				sibling->isBlack = false;
				node = parent; // update node
				parent = node->parent; // update parent (not that parent cannot be a nullptr)
			}
			else {
				if (sibling->left == nullptr || sibling->left->isBlack) {
					sibling->right->isBlack = true;
					sibling->isBlack = false;
					leftRotate(sibling);
					sibling = parent->left;
				}
				sibling->isBlack = parent->isBlack;
				parent->isBlack = true;
				if (sibling->left != nullptr) {
					sibling->left->isBlack = true;
				}
				rightRotate(parent);
				node = root;
				parent = node->parent; // update parent (not that parent cannot be a nullptr)
			}
		}

		// check if node is black, and udpate it before the while loop condition
		nodeIsBlack = false;
		if (node == nullptr || node->isBlack) {
			nodeIsBlack = true;
		}
	}
	// in case if the node is still nullptr, don't make it black
	if (node != nullptr) {
		node->isBlack = true;
	}
}




// ----------------------------------------------------------------------------------------------------------------------
// Part 2 - Statistics Function (not a method of RedBlackTree class)
// ----------------------------------------------------------------------------------------------------------------------

//void statistics(string filename) 
//{
//
//}