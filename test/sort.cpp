// compiling instruction
// g++ sort.cpp -std=c++11

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void printArr(int arr[], int low, int high);
void printVec(const vector<int>& vec, int low, int high);
void qs(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void mergesort(vector<int>& v);
void ms(vector<int> & v, int low, int high);
void merge(vector<int>& v, int low, int mid, int high);


void printArr(int arr[], int low, int high) {
	cout << "{";
	for (; low <= high; low++) {
		cout << arr[low] << ", ";
	}
	cout << "}";
}

void printVec(const vector<int> &vec, int low, int high) {
	cout << "{";
	for (; low <= high; low++) {
		cout << vec[low] << ", ";
	}
	cout << "}";
}

// PRE: arr is unsorted
// PARAM: arr is the array you want to sort, n is the number of items in the arr
// POST: arr is sorted and number of partitions is returned
int quicksort(int arr[], int n) {
	//int numPartitions = qs(arr, 0, n);
	qs(arr, 0, n - 1);
}


void qs(int arr[], int low, int high)
{
	if(low < high) 
	{
		int pivot = partition(arr, low, high);

		printArr(arr, low, pivot - 1);
		cout << ",   ";
		printArr(arr, pivot+1, high);
		cout << endl;

		qs(arr, low, pivot - 1);
		qs(arr, pivot + 1, high);
	}
}


int partition(int arr[], int low, int high)
{
	// initial operation
	// choosing the right most end of the item in the subarray as pivot index
	int pivot = high;
	high--; // decrement high index by 1 from pivot
	while (low != high)
	{
		// increment low index until arr[low] > arr[pivot] as long as low < high
		while (arr[low] <= arr[pivot] && low < high) {
			low++;
		}

		// decrement high index until arr[low] < arr[pivot] as long as low < high
		while (arr[high] >= arr[pivot] && low < high) {
			high--;
		}

		// you will get the following 4 possible cases:
		// 1. arr[low] > arr[pivot] > arr[high] --> swap
		// 2. arr[low] >= arr[pivot] > arr[high] --> swap
		// 3. arr[low] > arr[pivot] >= arr[high] --> swap
		// 4. arr[low] == arr[pivot] == arr[high] --> don't swap
		// swap them as long as low < high
		if (!(arr[low] == arr[pivot] && arr[high] == arr[pivot]) && low < high) {
			int temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}

	//one you reach the condition low == high, check the last condition for the pivot
	// note that low > high should not be possible
	if (arr[low] > arr[pivot]) {
		int temp = arr[pivot];
		arr[pivot] = arr[low];
		arr[low] = temp;
		pivot = low; // update pivot
	}

	return pivot; // now low (or high) becomes the pivot
}




// sort v using merge sort
// PARAM: v = vector to be sorted
// POST: values in v are in ascending order
void mergesort(vector<int> & v) {
	ms(v, 0, v.size() - 1);
}

// sorts {low, .. , high} subarray of v
// PARAM: v = vector to be sorted
//		  low = low index of vector slice to be sorted
//		  high = high index of vector slice to be sorted
// POST: values in {low, .., high} of v are in ascending order
void ms(vector<int> & v, int low, int high) 
{
	// implicit base case
	if (low < high) {
		//cout << "diving array by half ..." << endl;
		int mid = (low + high) / 2;
		ms(v, low, mid);
		ms(v, mid + 1, high);
		printVec(v, low, mid);
		cout << ",   ";
		printVec(v, mid + 1, high);
		cout << endl;
		merge(v, low, mid, high);
	}
}


void merge(vector<int>& v, int low, int mid, int high)
{
	int start1 = low;
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = high;
	int i1 = start1;
	int i2 = start2;

	vector<int> temp;

	while (i1 <= end1 && i2 <= end2)
	{
		if (v[i1] < v[i2]) {
			temp.push_back(v[i1]);
			i1++;
		}
		else {
			temp.push_back(v[i2]);
			i2++;
		}
	}

	// copy the rest of the first subarray
	while (i1 <= end1) {
		temp.push_back(v[i1]);
		i1++;
	}

	// copy the rest of the second subarray
	while (i2 <= end1) {
		temp.push_back(v[i2]);
		i2++;
	}

	for (unsigned int itemp = 0; itemp < temp.size(); ++itemp) {
		v[itemp + low] = temp[itemp];
	}
}





int main() 
{
	// quick sort
	cout << "----------------------------------- quick sort ------------------------------------------" << endl;
	//int arr[] = { 31, 12, 07, 23, 93, 02, 11, 18 };
	int arr[] = { 8, 1, 2, 7, 3, 6, 4, 5};
	//int arr[] = { 9, 8, 7, 6, 5, 4 , 2, 1 };
	//int arr[] = { 12,92,43,51,35,21,32,42 };
	//int arr[] = { 2,8,6,5,4,3,7,1 };
	//int arr[] = { 31,22,83,17,70,12,27,67 }; //q6 ??
	int arrSize = 8;

	cout << "Original Array: ";
	printArr(arr, 0, arrSize - 1);
	cout << endl;

	quicksort(arr, arrSize);

	cout << "Result: ";
	printArr(arr, 0, arrSize - 1);
	cout << endl;


	cout << "----------------------------------- merge sort ------------------------------------------" << endl;
	vector<int> vec = { 38, 27, 43, 3, 9, 82, 10};
	cout << "Original Array: ";
	printVec(vec, 0, vec.size() - 1);
	cout << endl;

	mergesort(vec);

	cout << "Result: ";
	printVec(vec, 0, vec.size() - 1);
	cout << endl;

	return 0;
}