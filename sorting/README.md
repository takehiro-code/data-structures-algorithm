# Sorting Algorithm

## Selection Sort

Given arr with arrSize = n, starting from i = 1,
1. From element at i = 0 to i = 1, find minimum and swap it with i = 0 element.
2. i++ and go back to step 1 to repeat from element at i = 0 to i = 2.

Repeat the process from i = 1 to i = n

## Insertion Sort

Given arr with arrSize = n, starting from i = 1,
1. From i = 0, compare the item at i = 0 and i = 1. If `arr[0] < arr[1]`, then swap it.
2. i++
3. Compare item at i = 1 and i = 2, if arr[1] < arr[2], swap it if necessary to maintain order. If not swapped, proceeds with lower index, compare item at item at i = 0 and i = 1, if arr[0] < arr[1], swap it if necessary to maintain order.
4. i++ and repeat at i = 3.

Repeat the process from i = 1 to i = n

## Merge Sort

Given arr with arrsize = n,

1. Divide the arr by half.
2. Divide each subarray by half. Repeat this until you get 2 items subarray. E.g., for n = 8, there are 4 two-item subarrays. It could also be for n = 7, there are 3 two-item subarrays and one-item subarray.
3. Sort each subarray (actually compare every single element from one subarray to another subarray). Merge the subarray to the right adjacent subarray. E.g. for n = 7, there will 1 four-item subarray and 1 three-item subarray.
4. Sort and merge until all merged in one array.


## Quick Sort

Given arr with arrSize = n,

1. Choose pivot. For example, right most item.
2. Assign the low index `low = 0` and high index `high = n - 2`.
3. Compare arr[low] and arr[high], if arr[low] is bigger, swap them.
4. (increment low process) Move low index first (`low++;`) and if you found arr[low] > arr[high], then swap it, otherwise move it until you get arr[low] > arr[pivot].
5. (decrement high process) If not swapped yet and arr[low] > arr[pivot], then decrement high (`high--;`) until you found arr[low] > arr[high], then swap it.
6. If `low == high`, then stop the process.
7. Finally, compare arr[low] (or arr[high]) with arr[pivot], if arr[low] > arr[pivot], then swap them and now you have new pivot but it is I just call it as `wall` item, that is fixed in position to divide the array. Now you have two subarray as one subarray up to`arr[wall-1]` and another subarray from `arr[wall+1]`.
8. Choose pivot right most item in each subarray. Repeat 1 to 7 until everything becomes wall items.


