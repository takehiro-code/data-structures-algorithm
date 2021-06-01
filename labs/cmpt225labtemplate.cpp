// compiling instruction:
// g++ cmpt225labtemplate.cpp -std=c++11 

// cmpt225labtemplate.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

template <class T>
void selectionSort(T arr[], int n);

template <class T>
int getSmallest(T arr[], int start, int end);

template <class T>
int getSmallestRec(T arr[], int start, int end);

template <class T>
void swap(T arr[], int i, int j);

template <class T>
void print(T arr[], int n);


int main()
{
	int n = 10;
	int iarr[] = { 3,5,9,2,1,7,8,4,0,6 };
	selectionSort<int>(iarr, n);
	print<int>(iarr, n);

	cout << endl;
	string sarr[] = { "skunk", "hedgehog", "aardvark", "zebra", "rat", "cat", "hippopotamus", "hamster", "manatee", "red panda" };
	selectionSort<string>(sarr, n);
	print<string>(sarr, n);
	cout << endl;

	return 0;
}

// PRE: length of arr = n
// PARAM: arr = array of integers of length n
// POST: sorts arr in ascending order
template <class T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int smallest = getSmallestRec(arr, i, n);
		swap(arr, i, smallest);
	}
}

// PRE: 0 <= start < end <= length of arr
// PARAM: arr = array of integers
//        start = start index of sub-array
//        end = end index of sub-array + 1
// POST: returns index of smallest value in arr{start:end}
template <class T>
int getSmallest(T arr[], int start, int end) {
	int smallest = start;
	for (int i = start + 1; i < end; ++i) {
		if (arr[i] < arr[smallest]) {
			smallest = i;
		}
	}
	return smallest;
}


template <class T>
int getSmallestRec(T arr[], int start, int end) 
{
	// there is no "end" index!! index starts from 0 to end-1 !!
	if (start == end - 1) {
		return start;
	}

	int smallest = getSmallestRec(arr, start + 1, end);
	if (arr[start] < arr[smallest]) {
		return start;
	}
	else {
		return smallest;
	}
}




// PRE: i, j < length of arr
// PARAM: arr = array of integers of length n, i and j are indexes
// POST: swaps arr[i] with arr[j]
template <class T>
void swap(T arr[], int i, int j) {
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// PRE: length of arr = n
// PARAM: arr = array of integers of length n
// POST: prints arr[0:n]
template <class T>
void print(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}
