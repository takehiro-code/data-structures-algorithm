#include "BST_mod.h"

int main()
{
	BST tree;
	tree.insert(42);
	tree.insert(29);
	tree.insert(16);
	tree.insert(20);
	tree.insert(34);
	tree.insert(63);
	tree.insert(57);
	tree.insert(47);
	tree.insert(81);

	//1 2 4 5 3
	//tree.insert(1);
	//tree.insert(2);
	//tree.insert(4);
	//tree.insert(3);
	//tree.insert(5);

	cout << "Pre-order:" << endl;
	tree.preOrderPrint();
	cout << endl;

	cout << "In-order:" << endl;
	tree.inOrderPrint();
	cout << endl;

	cout << "Post-order:" << endl;
	tree.postOrderPrint();
	cout << endl;


	return 0;
}