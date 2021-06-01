// Running instruction
// g++ -o ex2 Exercise2.cpp -std=c++11

#include "Exercise2.h"
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

// how to get the size of static array: int size = sizeof(arr) / sizeof(arr[0]);
//sizeof 
// don't use sizeof to get the size of array. Sizeof does not work for dynamic array. You must pass the 
// size of the array to function, so the following printArr function does not work.
// either dynamic or static array, always have a size value.

/*
void printArr(int *arr)
{
	//how do we get the size?
	int arrSize = sizeof(arr) / sizeof(arr[0])
	cout << "arr = { ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << " }" << endl;
}
*/



//static array way
int main() {
	// test
	//int arr[] = { 1,3,5,7 }; // correct
	//int n = 4;
	//int value = 7;

	//int arr[] = { 1,2,3,4,3,2,1,4 }; // correct
	//int n = 8;
	//int value = 3;

	//int arr[] = { 1,2,3,4,3,2,1,4 }; // correct
	//int n = 8;
	//int value = 42;

	//int arr[] = { 3,3,3,3,3,3 }; // correct
	//int n = 6;
	//int value = 3;

	//int arr[] = { 1,1,1,7,6,5 }; //  correct
	//int n = 2;
	//int value = 1;

	//int arr[] = {}; // correct
	//int n = 0;
	//int value = 1;

	//int arr[] = {1, 2, -4, 0, -3, 4, -4};
	//int n = 4;
	//int value = -4;

	int arr[] = { 1,1,1,1,1,1,2,3 };
	const int actualSize = 8;
	int n = 8;
	int value = 1;


	cout << " ... Pre remove call ..." << endl;
	cout << "arr = { ";
	for (int i = 0; i < actualSize; i++) {
		cout << arr[i] << ", ";
	}
	cout << " }" << endl;
	cout << "Array size = " << n << endl;
	cout << "Value you want to remove: " << value << endl;
	cout << endl;

	int removeCount = remove(arr, n, value);

	cout << " ... Post remove call ..." << endl;
	cout << "arr = { ";
	for (int i = 0; i < actualSize; i++) {
		cout << arr[i] << ", ";
	}
	cout << " }" << endl;
	cout << "Array size = " << n << endl;
	cout << "removeCount = " << removeCount << endl << endl;
}


////dynamic array
// https://stackoverflow.com/questions/57661016/how-to-use-curly-bracket-initializer-for-a-dynamically-size-array-and-new
//int main()
//{
//	// test
//	int *arr = new int[4]{ 3, 3, 3, 3 };
//	const int actualSize = 4;
//	int n = 4;
//	int value = 3;
//
//	cout << " ... Pre remove call ..." << endl;
//	cout << "arr = { ";
//	for (int i = 0; i < actualSize; i++) {
//		cout << arr[i] << ", ";
//	}
//	cout << " }" << endl;
//	cout << "Array size = " << n << endl;
//	cout << "Value you want to remove: " << value << endl;
//	cout << endl;
//
//	int removeCount = remove(arr, n, value);
//
//	cout << " ... Post remove call ..." << endl;
//	cout << "arr = { ";
//	for (int i = 0; i < actualSize; i++) {
//		cout << arr[i] << ", ";
//	}
//	cout << " }" << endl;
//	cout << "Array size = " << n << endl;
//	cout << "removeCount = " << removeCount << endl << endl;
//
//	delete[] arr;
//}