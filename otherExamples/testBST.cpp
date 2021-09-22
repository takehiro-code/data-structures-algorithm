
#include "BST.h"

int main()
{
	cout << "testing BST program ..." << endl;
	// create BST tree
	BST tree;

	// test 1: Lecture example
	tree.insert(40);
	tree.insert(20);
	tree.insert(11);
	tree.insert(3);
	tree.insert(17);
	tree.insert(60);
	tree.insert(51);
	tree.insert(54);
	tree.insert(53);
	tree.insert(57);
	tree.insert(72);
	cout << "Test 1" << endl;
	tree.print();
	cout << "Height: " << tree.height() << endl;
	cout << endl;

	// test 2: empty tree
	tree.clear();
	cout << "Test 2" << endl;
	tree.print();
	cout << "Height: " << tree.height() << endl;
	cout << endl;

	// test 3: root node only
	tree.insert(54);
	cout << "Test 3" << endl;
	tree.print();
	cout << "Height: " << tree.height() << endl;
	cout << endl;

	tree.clear();

	// test 4
	tree.clear();
	tree.insert(1);
	tree.insert(2);
	tree.insert(4);
	tree.insert(3);
	tree.insert(5);
	cout << "Test 4" << endl;
	tree.print();
	cout << "Height: " << tree.height() << endl;
	cout << endl;

	// test 5
	tree.clear();
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	cout << "Test 5" << endl;
	tree.print();
	cout << "Height: " << tree.height() << endl;
	cout << endl;

	// test 6
	tree.clear();
	tree.insert(17);
	tree.insert(13);
	tree.insert(9);
	tree.insert(11);
	tree.insert(16);
	tree.insert(27);
	tree.insert(20);
	tree.insert(39);
	cout << "Test 6: Lecture slide bst1.pdf slide 7" << endl;
	tree.print();
	cout << "Height: " << tree.height() << endl;
	cout << endl;

	// test 7
	tree.clear();
	tree.insert(9);
	tree.insert(1);
	tree.insert(7);
	tree.insert(4);
	tree.insert(5);
	cout << "Test 7: Lecture slide bst1.pdf slide 20" << endl;
	tree.print();
	cout << "Height: " << tree.height() << endl;
	cout << endl;

	// test 8
	tree.clear();
	tree.insert(15);
	tree.insert(10);
	tree.insert(8);
	tree.insert(12);
	tree.insert(20);
	tree.insert(17);
	tree.insert(25);
	cout << "Test 8: Perfect Binary Tree" << endl;
	tree.print();
	cout << "Height: " << tree.height() << endl;
	cout << endl;

	// test 9
	tree.clear();
	tree.insert(8);
	tree.insert(4);
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	tree.insert(6);
	tree.insert(5);
	tree.insert(7);
	tree.insert(12);
	tree.insert(10);
	tree.insert(9);
	tree.insert(11);
	tree.insert(14);
	tree.insert(13);
	tree.insert(15);

	cout << "Test 9: Perfect binary tree" << endl;
	tree.print();
	cout << "Height: " << tree.height() << endl;
	cout << endl;

	return 0;
}