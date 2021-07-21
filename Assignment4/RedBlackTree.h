#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// ----------------------------------------------------------------------------------------------------------------------
// Part 1 - Red Black Tree
// ----------------------------------------------------------------------------------------------------------------------


// Red black tree node class
template <class T>
class NodeT
{
public:
	T data;
	NodeT* left;
	NodeT* right;
	NodeT* parent;
	bool isBlack; // true if node is black, false if node is red
	NodeT(T value) : data(value), left(nullptr), right(nullptr), parent(nullptr), isBlack(false) {};
};


// -----------------------------------------------------------------------------------------------
// Class Declarations
// -----------------------------------------------------------------------------------------------

// red black tree class declarations
template <class T>
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
	bool insert(const T value);
	bool remove(const T value);
	bool search(const T value) const;
	vector<T> search(T value1, T value2) const;
	T closestLess(const T value) const;
	T closestGreater(const T value) const;
	vector<T> values() const;
	int size() const;

	template <class Tjwme>
	friend NodeT<Tjwme>* JWMEgetRoot(const RedBlackTree<Tjwme>& rbt);

	// for debugging
	void preOrderPrint() const;
	void inOrderPrint() const;
	void visualize() const;
	void preOrderPrint(NodeT<T>* node) const;
	void inOrderPrint(NodeT<T>* node) const;
	void visualizeTraversal(NodeT<T>* node, string space, bool flag) const;

private:
	NodeT<T>* root;
	int curSize;

	// private methods
	void copyRedBlackTree(NodeT<T>* node);
	void clear(NodeT<T>* node);
	NodeT<T>* searchNodeAndReturn(const T value) const;
	void inOrderTraversal(NodeT<T>* node, vector<T>& result, const T & smallestValue, const T & largestValue) const;
	NodeT<T>* bstInsert(const T value);
	void leftRotate(NodeT<T>* node);
	void rightRotate(NodeT<T>* node);
	NodeT<T>* predecessor(NodeT<T>* node) const;
	NodeT<T>* successor(NodeT<T>* node) const;
	void rbTreeFix(NodeT<T>* node, NodeT<T>* parent);
};


// -----------------------------------------------------------------------------------------------
// Method Implementations
// -----------------------------------------------------------------------------------------------


// RedBlackTree class definitions

// Default constructor
template <class T>
RedBlackTree<T>::RedBlackTree() 
{
	root = nullptr;
	curSize = 0;
}


// Copy constructor
// PRE: calling object not initialized yet
// POST: Copying the contents of rbTree to the calling object
template <class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T>& rbTree)
{
	// initializing the red black tree attributes for the calling object
	root = nullptr;
	curSize = 0;
	copyRedBlackTree(rbTree.root); // copying operation starting with root
}


// Overloaded assignment operator
// PRE: calling object may contain contents
// POST: Copying the contents of rbTree to the calling object
template <class T>
RedBlackTree<T>& RedBlackTree<T>::operator=(const RedBlackTree<T>& rbTree) 
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
template <class T>
RedBlackTree<T>::~RedBlackTree() 
{
	clear(root);
}


// Insert a value to the tree
// PARAM: value - value to be inserted
// POST: Return true after value is inserted. If tree already has value, then don't insert and return false
// NOTE: The following nodes are used,
//			node: node to be inserted (node cannot be nullptr)
//			uncle: uncle of node (uncle could be nullptr)
template <class T>
bool RedBlackTree<T>::insert(const T value) 
{
	// when value is already in the tree, don't insert
	if (search(value)) {
		return false;
	}

	// insert a node with value, and its color is already red
	NodeT<T>* node = bstInsert(value);

	// if node is not a root, then node's parent cannot be a nullptr
	// if node parent is red, then node grand parent cannot be a nullptr
	while (node != root && node->parent->isBlack == false) // if node is not a root and node is red
	{
		// if node's parent is the left child of its grand parent
		if (node->parent == node->parent->parent->left) {
			NodeT<T>* uncle = node->parent->parent->right;

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
			NodeT<T>* uncle = node->parent->parent->left;

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
template <class T>
bool RedBlackTree<T>::remove(const T value)
{
	// search for the value
	NodeT<T>* node = searchNodeAndReturn(value);

	// if value is not in the tree
	if (node == nullptr) {
		return false;
	}

	// node that will be removed. Its content will be copied into the node
	NodeT<T>* toBeRemoved;
	// if node has one or no children
	if (node->left == nullptr || node->right == nullptr) {
		toBeRemoved = node;
	}
	else { // node has two children
		toBeRemoved = predecessor(node);
	}

	// if toBeRemoved has a left child, left child becomes child node
	// if toBeRemoved doesn't have a left child, right child becomes child node regardless of being nullptr
	NodeT<T>* child;
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
template <class T>
bool RedBlackTree<T>::search(const T value) const
{
	NodeT<T>* node = searchNodeAndReturn(value);
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
template <class T>
vector<T> RedBlackTree<T>::search(const T value1, const T value2) const
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
template <class T>
T RedBlackTree<T>::closestLess(const T value) const
{
	T result = value;

	NodeT<T>* node = root; // starting from root node to search
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
template <class T>
T RedBlackTree<T>::closestGreater(const T value) const
{
	T result = value;

	NodeT<T>* node = root; // starting from root node to search
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
template <class T>
vector<T> RedBlackTree<T>::values() const
{
	vector<T> result;

	// if the tree is empty, return the empty vector
	if (root == nullptr) {
		return result;
	}

	T smallestValue, largestValue;

	NodeT<T>* node = root; // starting from root node to search
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
template <class T>
int RedBlackTree<T>::size() const
{
	return curSize;
}


// -----------------------------------------------------------------------------------------------
// Helper Methods
// -----------------------------------------------------------------------------------------------


// private helper method for the copying Red black Tree used in copy constructor and overloaded assignment operator
// inserting elements with the pre-order traversal
template <class T>
void RedBlackTree<T>::copyRedBlackTree(NodeT<T>* node)
{
	if (node != nullptr) {
		NodeT<T>* newNode = bstInsert(node->data);
		newNode->isBlack = node->isBlack;
		copyRedBlackTree(node->left);
		copyRedBlackTree(node->right);
	}
}


// Empties tree
// PRE:
// PARAM: node - This should be root during the 1st call
// POST: Removes all nodes from tree, deallocates dynamic memory
template <class T>
void RedBlackTree<T>::clear(NodeT<T>* node)
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
template <class T>
NodeT<T>* RedBlackTree<T>::searchNodeAndReturn(const T value) const
{
	// search for the value
	NodeT<T>* node = root; // starting from root node to search
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
template <class T>
void RedBlackTree<T>::inOrderTraversal(NodeT<T>* node, vector<T>& result, const T& smallestValue, const T& largestValue) const
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
template <class T>
NodeT<T>* RedBlackTree<T>::bstInsert(const T value)
{
	NodeT<T>* newNode = new NodeT<T>(value);
	NodeT<T>* parent = root;
	NodeT<T>* insertionPoint = root;

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
template <class T>
void RedBlackTree<T>::leftRotate(NodeT<T>* node) 
{
	NodeT<T>* rightChild = node->right;
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
template <class T>
void RedBlackTree<T>::rightRotate(NodeT<T>* node)
{
	NodeT<T>* leftChild = node->left;
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
template <class T>
NodeT<T>* RedBlackTree<T>::predecessor(NodeT<T>* node) const 
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
template <class T>
NodeT<T>* RedBlackTree<T>::successor(NodeT<T>* node) const
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
template <class T>
void RedBlackTree<T>::rbTreeFix(NodeT<T>* node, NodeT<T>* parent) 
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
		NodeT<T>* sibling; // can this be nullptr??
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

// PRE: No error could occur associated with a file.
// PARAM: filename - file name of the file that contains either empty or some values.
// POST: Print the formatted console output of statistical result of values from the file
void statistics(string filename) 
{
	// initialize the working red black tree object
	RedBlackTree<double> tree;

	// read the content from the file and insert them into the tree object
	ifstream file(filename);
	double value;
	if (file.is_open()) {
		while (file >> value)
		{
			tree.insert(value); // no duplicates can be inserted
		}
	}
	else {
		cout << "File cannot be opened ... " << endl;
	}
	file.close();

	// Now you have all the contents from the file
	// First, get the number of unique values in the tree
	int numValues = tree.size();

	if (numValues > 0) 
	{
		vector<double> result = tree.values();
		int sizeResult = result.size(); // equivalently, you can use numValues, but I sticked with common way, using .size()

		// find the average
		double average = 0;
		for (int i = 0; i < sizeResult; i++) {
			average += result[i];
		}
		average = average / (double)sizeResult;

		// find the median
		double median;
		if (sizeResult % 2 == 1) // when the number of values are odd
		{
			median = result[sizeResult / 2];
		}
		else { // when the number of values are even
			int leftIndex = (sizeResult - 1) / 2;
			int rightIndex = sizeResult / 2;
			double medianLeft = result[leftIndex];
			double medianRight = result[rightIndex];
			median = (medianLeft + medianRight) / 2;
		}

		double lessThan42 = tree.closestLess(42.0);
		double greaterThan42 = tree.closestGreater(42.0);

		// Printing the results
		cout << "# of unique values:\t" << numValues << endl;
		cout << "Average:\t\t" << average << endl;
		cout << "Median:\t\t\t" << median << endl;

		// if no value found, closestLess() will return the parameter value, so we can post-process the message
		if (lessThan42 < 42.0) {
			cout << "Closest value < 42.0:\t" << lessThan42 << endl;
		}
		else {
			cout << "Closest value < 42.0:\tNo such value found" << endl;
		}

		if (greaterThan42 > 42.0) {
			cout << "Closest value > 42.0:\t" << greaterThan42 << endl;
		}
		else {
			cout << "Closest value > 42.0:\tNo such value found" << endl;
		}
	}
	else {
		// Printing the results
		cout << "# of unique values:\t" << numValues << endl;
		cout << "File is empty ... " << endl;
	}
}