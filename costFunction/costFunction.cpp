// compiling instruction:
// g++ costFunction.cpp -std=c++11

#include "costFunction.h"
#include "math.h"


// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
void ssort_test(int arr[], int n, int i, int & ops)
{
    if (i < n - 1) {
        // Find and swap smallest remaining
        int next = i + 1;
        int smallest = i;

        while (next < n) {
            if (arr[next] < arr[smallest]) {
                smallest = next;
                ops++;
            }
            next++;
            ops += 3;
        }

        // Swap i with smallest
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        ops += 7;

        ssort_test(arr, n, i + 1, ops);
    }

    if (!(i < n - 1)) {
        ops++;
    }
}



// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
void pattern_test(int n, int i, int & ops)
{
    if (n > 0) {
        pattern_test(n / 2, i, ops);
        // Print i spaces
        cout << string(i, ' '); // NOTE: counts as ONE operation
        ops++;

        // A loop to print n asterisks, each one followed by a space
        int ast = 0;
        while (ast < n) {
            cout << "* ";
            ast++;
            ops += 3;
        }

        cout << endl;
        i += n;

        ops += 4;

        pattern_test(n / 2, i, ops);
    }

    ops++;
}





void testq1() {
    cout << "Example 1:" << endl;
    int arr[] = { 1,2,3,4,5 };
    int n = 5;
    int cost = cartesianProduct(arr, n);
    cout << endl << "cost = " << cost;
    cout << endl << "t(cartesianProduct): 4 * n ^ 2 + 5 * n + 2 = " << 4 * n * n + 5 * n + 2;
    cout << endl << "--------------" << endl << endl;
}


void testq2() {
    cout << "Example 2:" << endl;
    int n = 5;
    int cost = triangle(n);

    cout << endl << "cost = " << cost;
    cout << endl << "t(triangle): 4 * n ^ 2 + 5 * n + 2 = " << 3 * n * n + 13 * n + 3;
    cout << endl << "--------------" << endl << endl;
}


void testq3() {
    cout << "Example 3:" << endl;
    //int arr[] = { 1,1,1,2,3,4,4,5,6 }; // test
    //int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int n;

    cout << "best case:" << endl;
    int arr1[] = { 1,1,1,1,1 }; // best case example
    int n1 = 5; 
    n = n1;
    int cost1 = 0;
    vector<int> v_unique1 = removeDuplicates(arr1, n, cost1);
     //printing
    for (int i = 0; i < v_unique1.size(); i++) {
        cout << v_unique1[i] << endl;
    }
    cout << endl << "cost = " << cost1;
    cout << endl << "t(removeDuplicates, best): 10 * n = " << 10 * n << endl;


    cout << "worst case:" << endl;
    int arr2[] = { 1,2,3,4,5 }; // worst case example
    int n2 = 5;
    n = n2;
    int cost2 = 0;
    vector<int> v_unique2 = removeDuplicates(arr2, n, cost2);
    //printing
    for (int i = 0; i < v_unique2.size(); i++) {
        cout << v_unique2[i] << endl;
    }
    cout << endl << "cost = " << cost2;
    cout << endl << "t(removeDuplicates, worst): 1.5 * n * n + 5.5 * n + 3 = " << 1.5 * n * n + 5.5 * n + 3 << endl;


    cout << endl << "--------------" << endl << endl;

}


void testq4() {
    cout << "Example 4:" << endl;
    int rows = 5;
    int columns = rows;
    int cost = 0;
    int n = rows;

    // create a square matrix // passing a static array is fine
    int mat[] = {
        2, 0, 0, 0, 0,
        0, 2, 0, 0, 0,
        0, 0, 2, 0, 0,
        0, 0, 0, 2, 0,
        0, 0, 0, 0, 2,
    };
    int* result = matrixSelfMultiply(mat, rows, cost);

    //print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << result[rcIndex(i, j, rows)];
        }
        cout << endl;
    }

    cout << endl << "cost = " << cost;
    cout << endl << "t(matrixSelfMultiply): 3 * n * n * n + 6 * n * n + 4 * n + 4 = " << 3 * n * n * n + 6 * n * n + 4 * n + 4 << endl;
    cout << endl << "--------------" << endl << endl;

    delete[] result;
}


void testq5() {
    cout << "Example 5:" << endl;
    //int arr[] = { 1,2,3,4,5, 6 }; // best
    //int arr[] = { 1,1,1,1,1 }; // best
    int arr[] = {10,9,8, 7,6,5,4,3,2,1}; // worst
    int n = 10;
    int cost = ssort(arr, n, 0);

    // test
    //int cost = 0;
    //ssort_test(arr, n, 0, cost);

    //print
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << endl << "cost = " << cost;
    cout << endl << "t(ssort, best): 1.5 * n * n + 5.5 * n - 6 = " << 1.5 * n * n + 5.5 * n - 6 << endl;
    if (n % 2 == 0) {
        cout << endl << "t(ssort, worst, n is even): 1.75 * n * n + 5.5 * n - 6 = " << (float)1.75 * n * n + (float)5.5 * n - 6 << endl;
    }
    else {
        cout << endl << "t(ssort, worst, n is odd): 1.75 * n * n + 5.5 * n - 6.25 = " << (float) 1.75 * n * n + (float)5.5 * n - 6.25 << endl;
    }
    cout << endl << "--------------" << endl << endl;
}


void testq6() {
    cout << "Example 6:" << endl;

    int n = 8;
    int cost = pattern(n, 0);

    // this for testing
    //int cost = 0;
    //pattern_test(n, 0, cost);

    cout << endl << "cost = " << cost;
    cout << endl << "t(pattern):  = " << 17 * n + 3 * n * log2(n) -6 << endl;
    cout << endl << "--------------" << endl << endl;

}



int main()
{
    cout << "testing cost function ..." << endl << endl;

    testq1();
    testq2();
    testq3();
    testq4();
    testq5();
    testq6();




    return 0;
}