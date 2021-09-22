// compiling instruction:
// g++ testBST.cpp BST.cpp -std=c++11


#include "BST.h"

int main() {
	cout << "testing BST program ... " << endl;

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

	BST b2(b1);
	cout << "b2: " << endl;
	b2.print();
	cout << endl;

	BST b3 = b1;
	cout << "b3: " << endl;
	b3.print();
	cout << endl;

	BST b4, b5;
	b4 = b5 = b3 = b1;

	cout << "b3: " << endl;
	b3.print();
	cout << endl;

	cout << "b4: " << endl;
	b4.print();
	cout << endl;

	cout << "b5: " << endl;
	b5.print();
	cout << endl;



	return 0;
}