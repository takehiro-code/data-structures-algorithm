#pragma

// Quick Sort worse cases:
// 1. Array is sorted already
// 2. Array is reversely sorted
// 3. Array has all same items


// Function declarations
template <class T>
int quicksort(T arr[], int n);

template <class T>
void qs(T arr[], int low, int high, int & numPartitions);

template <class T>
int partition(T arr[], int low, int high);


// PRE: arr is unsorted
// PARAM: arr is the array you want to sort, n is the number of items in the arr
// POST: arr is sorted and number of partitions is returned
template <class T>
int quicksort(T arr[], int n) {

	// initializing the number of partitions
	int numPartitions = 0;
	qs(arr, 0, n - 1, numPartitions); // arr and the number of partitions is changed
	return numPartitions;
}


// Calling a function recursively to partition the subarray
template <class T>
void qs(T arr[], int low, int high, int & numPartitions)
{
	// when low == high, there is only 1 element and no partition can be done further
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		numPartitions++;
		qs(arr, low, pivot - 1, numPartitions);
		qs(arr, pivot + 1, high, numPartitions);
	}
}


// PARAM arr: subarray to be partitioned, low: the first index of subarray, high: the last index of subarray
// POST: Subarray will be partitioned and the pivot will be returned
template <class T>
int partition(T arr[], int low, int high)
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
			T temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}

	//one you reach the condition low == high, check the last condition for the pivot
	// note that low > high should not be possible
	if (arr[low] > arr[pivot]) {
		T temp = arr[pivot];
		arr[pivot] = arr[low];
		arr[low] = temp;
		pivot = low; // update pivot
	}

	return pivot; // now low (or high) becomes the pivot
}
