// compiling instruction
// g++ Exercise3.cpp List.cpp -std=c++11
// run the program with memory check: valgrind ./a.out

#include "List.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    cout << "Exercise 3 testing ..." << endl;

    List l1;
    l1.insert(1); // in this List implementation, insert is exactly the same as push operation in Stack
    l1.insert(3);
    l1.insert(5);
    l1.insert(7);
    int removeCount1 = l1.remove(7);

    const vector<int> v1 = {5, 3, 1};
    cout << "Check status: " << l1.check(v1) << endl;
    cout << "Remove count: " << removeCount1 << endl << endl;

    List l2;
    l2.insert(1); 
    l2.insert(2);
    l2.insert(3);
    l2.insert(4);
    l2.insert(3);
    l2.insert(2);
    l2.insert(1);
    l2.insert(4);
    int removeCount2 = l2.remove(3);

    const vector<int> v2 = { 4, 1, 2, 4, 2, 1 };
    cout << "Check status: " << l2.check(v2) << endl;
    cout << "Remove count: " << removeCount2 << endl << endl;

    List l3;
    l3.insert(1);
    l3.insert(2);
    l3.insert(3);
    l3.insert(4);
    l3.insert(3);
    l3.insert(2);
    l3.insert(1);
    l3.insert(4);
    int removeCount3 = l3.remove(42);

    const vector<int> v3 = { 4, 1, 2, 3, 4, 3, 2, 1 };
    cout << "Check status: " << l3.check(v3) << endl;
    cout << "Remove count: " << removeCount3 << endl << endl;

    List l4;
    int removeCount4 = l4.remove(-8);
    const vector<int> v4 = {};
    cout << "Check status: " << l4.check(v4) << endl;
    cout << "Remove count: " << removeCount4 << endl << endl;

    List l5;
    l5.insert(3);
    l5.insert(3);
    l5.insert(3);
    l5.insert(3);
    l5.insert(3);
    l5.insert(3);
    int removeCount5 = l5.remove(3);

    const vector<int> v5 = {};
    cout << "Check status: " << l5.check(v5) << endl;
    cout << "Remove count: " << removeCount5 << endl << endl;

    List l6;
    l6.insert(1); // in this List implementation, insert is exactly the same as push operation in Stack
    l6.insert(3);
    l6.insert(5);
    l6.insert(7);
    int removeCount6 = l6.remove(1);
    removeCount6 = l6.remove(3);
    removeCount6 = l6.remove(5);
    removeCount6 = l6.remove(2788);

    const vector<int> v6 = {7};
    cout << "Check status: " << l6.check(v6) << endl;
    cout << "Remove count: " << removeCount6 << endl;

    return 0;
}