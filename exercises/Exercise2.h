#pragma once

// use pointer to access the array, which can be either static array or dynamic array
// pass by reference for the size of the array
// shifting the elements or overwriting to the left to remove
// elements greater than n are irrelevant
int remove(int* arr, int& n, int value)
{
	int removeCount = 0;

	for (int i = 0; i < n; i++)
	{
		// once you find the value, overwrite shifting the elements to the left (basically removing the element)
		if (arr[i] == value) 
		{
			//increment remove counter
			removeCount++;

			//shift all the elements from i to n - 1 to left by 1 element
			for (int j = i; j < n - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			n--; // decremement the array size
			i--; // decrement index i by 1 so that we can proceed with the next element because next element is shifted by -1
		}
	}
	return removeCount;
}