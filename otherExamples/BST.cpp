#include "BST.h"

// Returns the height of the tree - number of levels - 1
int BST::height() const
{
	// initialize height as -1
	int height = traverse(root, -1);
	return height;
}

// Helper method (if any)

// height should be pass-by-value so that it updates individually in different branch
int BST::traverse(TreeNode* nd, int height) const
{
	if (nd != nullptr)
	{
		// before go to the its childs, increment update height for the current node height
		height++;
		int heightLeft = traverse(nd->left, height);
		int heightRight = traverse(nd->right, height);

		// when returning to the node after traversing left subtree and right subtree, post-check which height is higher
		if (heightLeft < heightRight) {
			height = heightRight;
		}
		else {
			height = heightLeft;
		}
	}
	return height;
}


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
void BST::print() const
{
	inOrderPrint(root);
}

// Returns true iff tree is empty
// PRE:
// POST: Returns root == nullptr
bool BST::empty() const
{
	return root == nullptr;
}


// Helper Methods ----------------------------

// Performs an in-order traversal of tree
// PRE:
// POST: Prints contents of tree in order
void BST::inOrderPrint(TreeNode* nd) const
{
	if (nd != nullptr) {
		inOrderPrint(nd->left);
		cout << nd->data << endl;
		inOrderPrint(nd->right);
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