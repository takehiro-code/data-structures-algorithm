#pragma

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

// --------------------------------------------------------------------------------------------------
// Example 1
// --------------------------------------------------------------------------------------------------
// PARAM: arr is array to print the Cartesian product of, n is size of arr
// POST: print the set of every possible ordered set of itself arr x arr, and return the number of operation counts
int cartesianProduct(int arr[], int n)
{
    int i = 0;
    int ops = 1; // cost for the above statement
    while (i < n) {
        int j = 0;
        while (j < n) {
            cout << "{" << arr[i] << "," << arr[j] << "}";
            j++;
            cout << " ";
            ops += 4; // comparision and above 3 lines
        }

        cout << endl;
        i++;

        // comparison (i < n) and terminationg comparison (j < n)
        // also 3 lines of code: int j = 0; cout << endl; i++;
        ops += 5;
    }
    ops++; // terminating comparison for (i < n)
    return ops; // not counted for ops
}



// --------------------------------------------------------------------------------------------------
// Example 2
// --------------------------------------------------------------------------------------------------
// PARAM: x is
// POST: Prints a triangle of numbers
int triangle(int x)
{
    int i = 0;
    int ops = 1; // initialized the operation count to 1 (include int i = 0;)
    while (i < x) {
        int j = 0;
        while (j <= i) {
            cout << j << " ";
            j++;
            
            // comparison while (j <= i), cout << j << " "; and j++;
            ops += 3;
        }

        cout << endl;
        i++;

        // comparison while (i < x) and terminaing comparison while (i < x)
        // also int j = 0; cout << endl; i++;
        ops += 5;
    }

    // terminating comparison while (i < x)
    ops++;

    while (i > 0) {
        i--;
        int j = 0;
        while (j <= i) {
            cout << j << " ";
            j++;
            
            // comparison while (j <= i), cout << j << " "; j++;
            ops += 3;
        }
        cout << endl;

        // comparison while (i < 0) and terminating comparison while (j <= i)
        // also i--; int j = 0; cout << endl;
        ops += 5;
    }

    // terminating comparison while (i < 0)
    ops++;
    return ops;
}

// --------------------------------------------------------------------------------------------------
// Example 3
// --------------------------------------------------------------------------------------------------
// PARAM: arr is array from which duplicates are to be removed, n is size of arr
// POST: Return the vector<int> that contains the unique set of elements. Also, ops is upadted.
vector<int> removeDuplicates(int arr[], int n, int & ops)
{
    vector<int> result;
    int i = 0;
    ops = 2; // initialized to 2 that includes above 2 line of code
    while (i < n) {
        int iResult = 0;
        bool duplicate = false;

        // whenever the duplicate is true, it goes out of the loop
        while (iResult < (int)result.size() && !duplicate) { //note 4
            if (arr[i] == result[iResult]) {
                duplicate = true;
                ops++; // if statement is true --> duplicate = true; 1 operation
            }

            iResult++;

            // comparison for while loop, if statement, iResult++;
            ops += 3;
        }

        // if there is duplicate, don't push_back yet. If no duplicate, do push_back
        if (!duplicate) {
            result.push_back(arr[i]); //note 4
            ops++; // above line of code
        }

        i++;

        // comparison while (i < n), int iResult = 0; bool duplicate = false; --> 3 operations
        // terminating comparison of while (iResult < (int)result.size() && !duplicate) --> 1 operation
        // if(!duplicate) --> 1 operation
        // i++; --> 1 operation
        ops += 6;
    }

    // terminating comparison while (i < n)
    ops++;
    return result;
}

// --------------------------------------------------------------------------------------------------
// Example 4
// --------------------------------------------------------------------------------------------------
// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns)
{
    return r * columns + c;
}

// PRE: m represents a square matrix of size rows * rows
// PARAM: rows represents the number of both rows and columns
// POST: Returns a pointer to an array (matrix) of the same size as m
// NOTE: values are indexed r0c0,r0c1,c,r0cn-1,r1c0,c
int* matrixSelfMultiply(int* m, int rows, int & ops)
{
    // Create result array
    int columns = rows;
    int* result = new int[rows * columns];
    int r = 0;

    // initialized to operations count 3 from above lines
    ops += 3;
    
    while (r < rows) {
        int c = 0;
        while (c < columns) { //columns = rows
            int next = 0;
            int iNext = 0;

            while (iNext < rows) {
                next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)];
                iNext++;

                // comparison while(iNext < rows + 2 lins of code above
                ops += 3;
            }

            result[rcIndex(r, c, columns)] = next;
            c++;

            // comparison while (c < columns), terminating comparison while (iNext < rows)
            // int next = 0; int iNext = 0; result[rcIndex(r, c, columns)] = next; c++;
            ops += 6;
        }
        r++;

        // comparison while(r < rows), terminating comparison while (c < columns)
        // also int c = 0; r++;
        ops += 4;

    }

    // terminating comparison while (r < rows)
    ops++;
    return result;
}


// --------------------------------------------------------------------------------------------------
// Example 5
// --------------------------------------------------------------------------------------------------
// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
// POST: arr will be sorted and ops will be returned
int ssort(int arr[], int n, int i)
{
    // initialize the number of operations
    int ops = 0;

    if (i < n - 1) {
        // Find and swap smallest remaining
        int next = i + 1;
        int smallest = i;

        while (next < n) {
            if (arr[next] < arr[smallest]) {
                smallest = next; // for best case, this will not be executed but for the worst case
                ops++;
            }
            next++;
            
            // while comparison, if statement, next++;
            ops += 3;
        }

        // Swap i with smallest
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        // two line of code after if statement. Note that if statement is already included at the end
        // terminating comparison while (next < n)
        // 3 lines of code for the swapping
        ops += 6;

        // don't count this recursive call itself but return and add up to the ops count
        ops += ssort(arr, n, i + 1);
    }

    // for the if statement
    ops++;

    return ops;
}


// --------------------------------------------------------------------------------------------------
// Example 6
// --------------------------------------------------------------------------------------------------
// to count the operations, to be careful counting, we will count one by one instead of chunk
// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
int pattern(int n, int i)
{
    // intialized the operation count to 0
    int ops = 0;

    if (n > 0) {
        ops += pattern(n / 2, i);
        // Print i spaces
        cout << string(i, ' '); // NOTE: counts as ONE operation

        // A loop to print n asterisks, each one followed by a space
        int ast = 0;
        while (ast < n) {
            cout << "* ";
            ast++;
            ops += 3; // comparison of (ast < n) and above 2 lines
        }

        cout << endl;
        i += n;

        // 5 operations as follows.
        // cout << string(i, ' '); int ast = 0; terminating comparison (ast < n); cout << endl; i+= n;
        ops += 5;

        ops += pattern(n / 2, i);
    }

    // from the above if statement
    ops++;
    return ops;
}