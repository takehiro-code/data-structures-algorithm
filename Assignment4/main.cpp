#include "RedBlackTree.h"


#include <random>
#include <iostream>
using std::cout;
using std::endl;

void printVector(vector<int> vec);


void random_test() 
{
    cout << " ------------------------------- Random test for insertion and removal-----------------------------------------------" << endl;

    RedBlackTree rb;

    // random generating numbers to automatically testing every possible cases
    const int range_from = 0;
    const int range_to = 1000;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    for (int i = 0; i < 10000; i++) {
        int rand_num = distr(generator);
        rb.insert(rand_num);
        //cout << rand_num << endl;
    }
    cout << "Number of values before removal: " << rb.size() << endl;

    for (int i = 0; i < 5000; i++) {
        int rand_num = distr(generator);
        rb.remove(rand_num);
        //cout << rand_num << endl;
    }
    cout << "Number of values after removal: " << rb.size() << endl;

    rb.preOrderPrint();
    cout << endl;
}


void copyTest()
{
    cout << " --------------------------------------- copy test -----------------------------------------------" << endl;

    cout << "Copy Test 1: Copying empty trees ..." << endl;
    RedBlackTree rb1;
    RedBlackTree rb2(rb1);
    RedBlackTree rb3 = rb1;

    cout << "rb1: ";
    rb1.preOrderPrint();
    cout << endl;

    cout << "rb2: ";
    rb2.preOrderPrint();
    cout << endl;

    cout << "rb3: ";
    rb3.preOrderPrint();
    cout << endl;


    cout << "Copy Test 2: copying 1 node tree ..." << endl;
    RedBlackTree rb4;
    rb4.insert(4);

    RedBlackTree rb5(rb4);
    RedBlackTree rb6 = rb4;


    cout << "rb4: ";
    rb4.preOrderPrint();
    cout << endl;

    cout << "rb5: ";
    rb5.preOrderPrint();
    cout << endl;

    cout << "rb6: ";
    rb6.preOrderPrint();
    cout << endl;

    cout << "Copy Test 3: copying tree using random library ..." << endl;
    RedBlackTree rb7;
    const int range_from = 0;
    const int range_to = 10;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    for (int i = 0; i < 10; i++) {
        int rand_num = distr(generator);
        rb7.insert(rand_num);
        //cout << rand_num << endl;
    }
    RedBlackTree rb8(rb7);
    RedBlackTree rb9 = rb7;
    
    cout << "rb7: ";
    rb7.preOrderPrint();
    cout << endl;

    cout << "rb8: ";
    rb8.preOrderPrint();
    cout << endl;

    cout << "rb9: ";
    rb9.preOrderPrint();
    cout << endl;


    rb1 = rb2 = rb3 = rb9;
    cout << "rb1: ";
    rb1.preOrderPrint();
    cout << endl;

    cout << "rb2: ";
    rb2.preOrderPrint();
    cout << endl;

    cout << "rb3: ";
    rb3.preOrderPrint();
    cout << endl;
}



void searchTest()
{
    cout << " ------------------------------------------ Search test -----------------------------------------------" << endl;

    int value;
    RedBlackTree rb;

    rb.insert(10);
    rb.insert(8);
    rb.insert(6);
    rb.insert(12);
    rb.insert(30);
    rb.insert(40);
    rb.insert(33);
    rb.insert(15);
    rb.insert(16);
    rb.insert(18);
    rb.insert(31);

    value = 31;
    cout << "Testing rb.insert" << "(" << value << "): " << rb.insert(value) << endl;
    cout << "Testing rb.insert" << "(" << value << "): " << rb.insert(value) << endl;
    cout << "Testing rb.insert" << "(" << value << "): " << rb.insert(value) << endl;
    
    value = 310;
    cout << "Testing rb.insert" << "(" << value << "): " << rb.remove(value) << endl;
    value = 3;
    cout << "Testing rb.insert" << "(" << value << "): " << rb.remove(value) << endl;

    cout << "Pre-order printing: " << endl;
    rb.preOrderPrint();
    cout << endl;

    cout << "In-order printing: " << endl;
    rb.inOrderPrint();
    cout << endl;


    value = 33;
    cout << "Testing search" << "(" << value << ") ..." << endl;
    if (rb.search(value)) {
        cout << "value: " << value << " is found" << endl;
    }
    else {
        cout << "value: " << value << " is not found" << endl;
    }

    value = 100;
    cout << "Testing search" << "(" << value << ") ..." << endl;
    if (rb.search(value)) {
        cout << "value: " << value << " is found" << endl;
    }
    else {
        cout << "value: " << value << " is not found" << endl;
    }

    int smallestValue = 10;
    int largestValue = 31;
    cout << "Testing search" << "(" << smallestValue << ", " << largestValue << ") ..." << endl;
    vector<int> result = rb.search(smallestValue, largestValue);
    printVector(result);

    cout << "Testing search" << "(" << largestValue << ", " << smallestValue << ") ..." << endl;
    vector<int> result2 = rb.search(largestValue, smallestValue);
    printVector(result2);

    value = 1;
    cout << "Testing closestLess" << "(" << value << ")  = " << rb.closestLess(value) << endl;
    value = 6;
    cout << "Testing closestLess" << "(" << value << ")  = " << rb.closestLess(value) << endl;
    value = 12;
    cout << "Testing closestLess" << "(" << value << ")  = " << rb.closestLess(value) << endl;
    value = 33;
    cout << "Testing closestLess" << "(" << value << ")  = " << rb.closestLess(value) << endl;
    value = 100;
    cout << "Testing closestLess" << "(" << value << ")  = " << rb.closestLess(value) << endl;

    value = 1;
    cout << "Testing closestGreater" << "(" << value << ")  = " << rb.closestGreater(value) << endl;
    value = 6;
    cout << "Testing closestGreater" << "(" << value << ")  = " << rb.closestGreater(value) << endl;
    value = 12;
    cout << "Testing closestGreater" << "(" << value << ")  = " << rb.closestGreater(value) << endl;
    value = 33;
    cout << "Testing closestGreater" << "(" << value << ")  = " << rb.closestGreater(value) << endl;
    value = 40;
    cout << "Testing closestGreater" << "(" << value << ")  = " << rb.closestGreater(value) << endl;
    value = 100;
    cout << "Testing closestGreater" << "(" << value << ")  = " << rb.closestGreater(value) << endl;

    cout << "Testing rb.values(): " << endl;
    vector<int> result3 = rb.values();
    printVector(result3);

    cout << "Creating empty tree ..." << endl;
    RedBlackTree rbEmpty;

    cout << "Testing rbEmpty.values() for the empty tree: " << endl;
    vector<int> result4 = rbEmpty.values();
    printVector(result4);

    cout << "Testing rb.size()  = " << rb.size() << endl;
    rb.remove(33);
    rb.remove(12);
    rb.remove(100);
    cout << "Testing rb.size()  = " << rb.size() << endl;

    cout << "Testing rbEmpty.size()  = " << rbEmpty.size() << endl;


}

int main()
{
    cout << "testing assignment 4 ..." << endl;

    //RedBlackTree rb;
    //rb.insert(10);
    //rb.insert(8);
    //rb.insert(6);
    //rb.insert(12);
    //rb.insert(30);
    //rb.insert(40);
    //rb.insert(33);
    //rb.insert(15);
    //rb.insert(16);
    //rb.insert(18);
    //rb.insert(31);
    //rb.remove(12);

    //rb.insert(10);
    //rb.insert(6);
    //rb.insert(15);
    //rb.insert(30);
    //rb.insert(8);
    //rb.remove(6);

    //rb.insert(31);
    //rb.insert(31);
    //rb.insert(31);
    //rb.remove(310);
    //rb.remove(3);


    //rb.preOrderPrint();
    //cout << endl;

    random_test();
    copyTest();
    searchTest();

    return 0;
}


// ----------------------------------------------------------------------------------
//                                  For debugging
// ----------------------------------------------------------------------------------
void RedBlackTree::preOrderPrint() const
{
    preOrderPrint(root);
}

void RedBlackTree::inOrderPrint() const
{
    inOrderPrint(root);
}

void RedBlackTree::preOrderPrint(NodeT* nd) const
{
    if (nd != nullptr) {
        char color;
        if (nd->isBlack) {
            color = 'B';
        }
        else {
            color = 'R';
        }
        cout << nd->data << "(" << color << ")" << " ";
        preOrderPrint(nd->left);
        preOrderPrint(nd->right);
    }
}

void RedBlackTree::inOrderPrint(NodeT* nd) const
{
    if (nd != nullptr) {
        char color;
        if (nd->isBlack) {
            color = 'B';
        }
        else {
            color = 'R';
        }
        inOrderPrint(nd->left);
        cout << nd->data << "(" << color << ")" << " ";
        inOrderPrint(nd->right);
    }
}


void printVector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}