#include "BST_mod.h"

int main()
{
	//BST tree;
	//tree.insert(40);
	//tree.insert(20);
	//tree.insert(11);
	//tree.insert(3);
	//tree.insert(17);
	//tree.insert(60);
	//tree.insert(51);
	//tree.insert(54);
	//tree.insert(53);
	//tree.insert(57);
	//tree.insert(72);


	//1 2 4 5 3
	//tree.insert(1);
	//tree.insert(2);
	//tree.insert(4);
	//tree.insert(3);
	//tree.insert(5);

	//cout << "Pre-order:" << endl;
	//tree.preOrderPrint();
	//cout << endl;

	//cout << "In-order:" << endl;
	//tree.inOrderPrint();
	//cout << endl;

	//cout << "Post-order:" << endl;
	//tree.postOrderPrint();
	//cout << endl;

	
	cout << "testing Exercise8 ... " << endl;

	// testing b1,b2,b3
	BST b1;
	// Test 1: testing multuple elements
	b1.insert(40);
	b1.insert(20);
	b1.insert(11);
	b1.insert(3);
	b1.insert(17);
	b1.insert(60);
	b1.insert(51);
	b1.insert(54);
	b1.insert(53);
	b1.insert(57);
	b1.insert(72);

	cout << "b1: " << endl;
	b1.preOrderPrint();
	cout << endl;

	BST b2(b1);
	cout << "b2: " << endl;
	b2.preOrderPrint();
	cout << endl;

	BST b3 = b1;
	cout << "b3: " << endl;
	b3.preOrderPrint();
	cout << endl;


	// testing b4,b5,b6
	BST b4;

	BST b5(b4);
	cout << "b5: " << endl;
	b5.preOrderPrint();
	cout << endl;

	BST b6 = b4;
	cout << "b6: " << endl;
	b6.preOrderPrint();
	cout << endl;

	BST b7;
	b7.insert(1);
	
	b6 = b7;
	cout << "b6: " << endl;
	b6.preOrderPrint();
	cout << endl;


	BST b8(b7);
	cout << "b8: " << endl;
	b8.preOrderPrint();
	cout << endl;

	BST b9;
	b9 = b7;
	cout << "b9: " << endl;
	b9.preOrderPrint();
	cout << endl;


	return 0;
}