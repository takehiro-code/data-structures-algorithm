#pragma once
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <stack>
#include <queue>
#include <unordered_set>
using std::stack;
using std::queue;
using std::unordered_set;
using std::priority_queue;
using std::cout;
using std::endl;
using std::runtime_error;

// TreeNode class
class TreeNode
{
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : data(value), left(nullptr), right(nullptr) {};
};

class BST
{
public:
	// Constructors
	BST();
	~BST();
	BST(const BST & bst);
	BST & operator=(const BST & bst);

	// Mutators
	void insert(int value);
	void clear();

	// Accessors
	bool find(int value) const;
	void print() const;
	int height() const;
	bool empty() const;

private:
	TreeNode * root;

	void inOrderPrint(TreeNode* nd) const;
	void clear(TreeNode* nd);
	int height(TreeNode* nd, int ht) const;
	void copyBST(TreeNode* nd);
};
