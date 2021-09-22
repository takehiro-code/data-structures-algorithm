// compiling instruction
// g++ testQuickSort.cpp -std=c++11

#include "quickSort.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// pasing static array and print from index low to index high
template <class T>
void printArr(T arr[], int low, int high) {
	cout << "{";
	for (; low <= high; low++) {
		cout << arr[low] << ", ";
	}
	cout << "}";
}


int main() 
{
	cout << "testing quickSort ..." << endl;

	// quick sort
	int arr[] = { 31, 12, 07, 23, 93, 02, 11, 18 };
	//int arr[] = { 8, 1, 2, 7, 3, 6, 4, 5 };
	//int arr[] = { 9, 8, 7, 6, 5, 4 , 2, 1 };
	//int arr[] = { 12,92,43,51,35,21,32,42 };
	//int arr[] = { 2,8,7,7,7,7,7,7 };
	//int arr[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	//// other than int array
	//string arr[] = { "hello", "bear", "apple", "ball", "human", "person", "quiz", "exam" };
	//float arr[] = { 1.3, 3.14, -3.56, 3.40, 0.0, 9.99, 10.2, -100.3 };
	//char arr[] = { 'a', 'z', 'g', 'g', 'b', 'y', 'k', 'm' };

	int arrSize = 8;

	cout << "Original Array: ";
	printArr(arr, 0, arrSize - 1);
	cout << endl;

	int numPartitions = quicksort(arr, arrSize);

	cout << "Result: ";
	printArr(arr, 0, arrSize - 1);
	cout << endl;

	cout << "# Partition calls = " << numPartitions << endl;

	return 0;
}