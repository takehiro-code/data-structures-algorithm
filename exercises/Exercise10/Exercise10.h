#pragma

// Check if the array satisfies the partial ordering property for a min heap
// PRE: 0 <= array size parameter <= size of array;
//	    Since we are given array with index 0, 1, 2 ..., where all nodes are to the left, so we can treat array as a complete tree.
// PARAM: 
//			arr: array
//			size: size of the array
// POST: Return true if partial ordering holds, otherwise return false
bool isMinHeap(int* arr, int size)
{
	int largestLeafIndex = size / 2;
	for (int i = 0; i <= largestLeafIndex; i++) // i: parent index
	{
		int parent = arr[i];
		int leftChildIndex = 2 * i + 1;
		int rightChildIndex = 2 * i + 2;

		// Check if the left child exists
		if (leftChildIndex < size) {
			// if parent is greater than the left child, it violates the partial ordering property for min heap
			if (parent > arr[leftChildIndex]) {
				return false;
			}

			// Left child exists but check if the right child exists
			if (rightChildIndex < size) {
				// if parent is greater than the right child, it violates the partial ordering property for min heap
				if (parent > arr[rightChildIndex]) {
					return false;
				}
			}
		}
	}
	// reaching here means the partial ordering holds
	return true;
}