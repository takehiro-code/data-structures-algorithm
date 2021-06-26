#pragma once
#include <cstdlib>
#include <iostream>
#include <stdexcept>
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

	// Mutators
	void insert(int value);
	void clear();

	// Accessors
	bool find(int value) const;
	void inOrderPrint() const;
	void preOrderPrint() const;
	void postOrderPrint() const;
	int height() const;
	bool empty() const;

private:
	TreeNode * root;

	void inOrderPrint(TreeNode* nd) const;
	void preOrderPrint(TreeNode* nd) const;
	void postOrderPrint(TreeNode* nd) const;

	void clear(TreeNode* nd);
	// EXERCISE 7: Helper method (if desired)
};
