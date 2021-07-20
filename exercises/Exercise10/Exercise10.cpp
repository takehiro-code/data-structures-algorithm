// Compiling Instruction:
// g++ Exercise10.cpp -std=c++11

#include "Exercise10.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout << "Testing Exercise 10 ..." << endl;

	//int arr[] = {};
	//int arr[] = { 1 };
	//int arr[] = { 1,1,1,1,1,1,1,1 };
	//int arr[] = { 1,2,3,4,5,6,7,8 };
	int arr[] = { 1,3,2,5,6,9,8,3 };
	//int arr[] = { 9,8,7,6,5,4,3,2,1 };

	int size = 8;
	cout << isMinHeap(arr, size) << endl;

	return 0;
}
