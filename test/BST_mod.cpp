#include "BST_mod.h"


// EXERCISE 8 --------------------------
// Copy constructor
BST::BST(const BST& bst)
{
	// same as default constructor, where we must initialize the attributes: root
	root = nullptr;
	copyBST(bst.root);
}

// Overloaded assignment operator
BST& BST::operator=(const BST& bst)
{
	if (this != &bst)
	{
		// need to delete to clean up the existing contents before copying
		clear();
		copyBST(bst.root);
	}
	return *this;
}

// Helper method (if any)

// private method for copying
// inserting elements with the pre-order traversal
void BST::copyBST(TreeNode* nd)
{
	if (nd != nullptr) {
		insert(nd->data);
		copyBST(nd->left);
		copyBST(nd->right);
	}
}



// EXERCISE 7 --------------------------

int BST::height() const
{
	if (root == nullptr) {
		return -1;
	}
	return height(root, -1);
}

// Returns the height of the tree - number of levels - 1
// PRE:
// PARAM: nd = current node (starts with root), ht = current height
// POST: Returns tree height
int BST::height(TreeNode* nd, int ht) const
{
	if (nd == nullptr) {
		return ht;
	}
	else {
		int htLeft = height(nd->left, ht + 1);
		int htRight = height(nd->right, ht + 1);
		return ((htLeft > htRight) ? htLeft : htRight);
	}
}


// END EXERCISE 7 --------------------------

// Default Constructor
// PRE:
// POST: root set to NULL
BST::BST()
{
	root = nullptr;
}

// De-allocates dynamic memory associated with tree
// PRE:
// POST: Value is inserted, in order, in tree
BST::~BST()
{
	clear();
}

// Insert value in tree maintaining bst property
// PRE:
// PARAM: value = value to be inserted
// POST: value is inserted, in order, in tree
void BST::insert(int value)
{
	TreeNode* newNode = new TreeNode(value);
	TreeNode* parent = root;
	TreeNode* next = root;

	if (empty()) {
		root = newNode;
	}
	else { //non-empty
		   // Find parent of new node
		while (next != nullptr) {
			parent = next;
			if (value < parent->data) {
				next = parent->left;
			}
			else {
				next = parent->right;
			}
		}
		// Insert new node
		if (value < parent->data) {
			parent->left = newNode;
		}
		else {
			parent->right = newNode;
		}
	}
}

// Empties tree
// PRE:
// POST: Removes all nodes from tree, deallocates dynamic memory
void BST::clear()
{
	clear(root);
	root = nullptr;
}

// Searches tree for target
// PRE:
// PARAM: target = value to be found
// POST: Returns true iff target is in tree
bool BST::find(int value) const
{
	TreeNode* p = root;
	while (p != nullptr) {
		if (value == p->data) {
			return true;
		}
		else if (value < p->data) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	return false;
}

// Prints contents of tree pre, in, post order
// PRE:
// POST: Prints contents of tree three times:
//       pre order, in order and post order
void BST::inOrderPrint() const
{
	inOrderPrint(root);
}

void BST::preOrderPrint() const
{
	preOrderPrint(root);
}

void BST::postOrderPrint() const
{
	postOrderPrint(root);
}


// Returns true iff tree is empty
// PRE:
// POST: Returns root == nullptr
bool BST::empty() const
{
	return root == nullptr;
}


// Helper Methods ----------------------------

// Performs an in-order, pre-order, post-order traversal of tree
// PRE:
// POST: Prints contents of tree in order such that:

void BST::inOrderPrint(TreeNode* nd) const
{
	if (nd != nullptr) {
		inOrderPrint(nd->left);
		cout << nd->data << endl;
		inOrderPrint(nd->right);
	}
}

void BST::preOrderPrint(TreeNode* nd) const
{
	if (nd != nullptr) {
		cout << nd->data << endl;
		preOrderPrint(nd->left);
		preOrderPrint(nd->right);
	}
}

void BST::postOrderPrint(TreeNode* nd) const
{
	if (nd != nullptr) {
		postOrderPrint(nd->left);
		postOrderPrint(nd->right);
		cout << nd->data << endl;
	}
}

// Helper method for clear()
// PRE:
// POST: Removes all nodes from tree, deallocates dynamic memory
void BST::clear(TreeNode* nd)
{
	if (nd != nullptr) {
		clear(nd->left);
		clear(nd->right);
		delete nd;
	}
}