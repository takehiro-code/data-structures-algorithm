// compiling instruction
// g++ Deque.cpp Exercise4.cpp -std=c++11
// run the program with memory check: valgrind ./a.out

#include "Deque.h"
#include <iostream>

using std::cout;
using std::endl;


int main() {
    cout << "Exercise 4 testing ..." << endl << endl;

    cout << "Test 1 ..." << endl;
    Deque dq1;
    dq1.insert_front(1);
    dq1.insert_front(3);
    dq1.insert_front(5);
    dq1.insert_front(7);
    dq1.printForwards();
    cout << endl;

    Deque dq1_copy(dq1);
    dq1_copy.printForwards();
    cout << endl;
    
    dq1.remove_back();
    dq1_copy.remove_back();

    dq1.printBackwards();
    cout << endl;
    dq1_copy.printBackwards();
    cout << endl;

    cout << "Test 2 ..." << endl;
    Deque dq2;
    dq2.printForwards();
    cout << endl;

    Deque dq2_copy(dq2);
    dq2_copy.printForwards();
    cout << endl;

    cout << "Test 3 ..." << endl;
    Deque dq3;
    dq3.insert_front(1);
    dq3.insert_front(2);
    dq3.insert_front(3);
    dq3.insert_front(3);
    dq3.insert_front(4);
    dq3.insert_front(5);
    dq3.insert_front(6);
    dq3.insert_front(7);
    dq3.insert_front(1);
    dq3.insert_back(-1);
    dq3.printForwards();
    cout << endl;

    Deque dq3_copy(dq3);
    dq3_copy.printForwards();
    cout << endl;


}

//// non-recursive way
//while (original != nullptr) 
//{
//	//this->insert_front(original->data); // non-recursively --> you can use this
//	Ex4Node* newNode = new Ex4Node(original->data, nullptr, front);
//	front = newNode;
//	if (back == nullptr) {
//		back = front;
//	}
//	else {
//		front->next->previous = front;
//	}
//	original = original->previous;
//}