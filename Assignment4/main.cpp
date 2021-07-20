#include "RedBlackTree.h"


#include <random>
#include <iostream>
using std::cout;
using std::endl;

void printVector(vector<int> vec);

// ----------------------------------------------------------------------------------
//                                  Test Functions
// ----------------------------------------------------------------------------------

void random_test() 
{
    cout << " ------------------------------- Random test for insertion and removal-----------------------------------------------" << endl;

    RedBlackTree<int> rb;

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
    rb.inOrderPrint();
    rb.visualize();
}


void copyTest()
{
    cout << " --------------------------------------- copy test -----------------------------------------------" << endl;

    cout << "Copy Test 1: Copying empty trees ..." << endl;
    RedBlackTree<int> rb1;
    RedBlackTree<int> rb2(rb1);
    RedBlackTree<int> rb3 = rb1;

    cout << "rb1: ";
    rb1.preOrderPrint();

    cout << "rb2: ";
    rb2.preOrderPrint();

    cout << "rb3: ";
    rb3.preOrderPrint();


    cout << "Copy Test 2: copying 1 node tree ..." << endl;
    RedBlackTree<int> rb4;
    rb4.insert(4);

    RedBlackTree<int> rb5(rb4);
    RedBlackTree<int> rb6 = rb4;


    cout << "rb4: ";
    rb4.preOrderPrint();

    cout << "rb5: ";
    rb5.preOrderPrint();

    cout << "rb6: ";
    rb6.preOrderPrint();

    cout << "Copy Test 3: copying tree using random library ..." << endl;
    RedBlackTree<int> rb7;
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
    RedBlackTree<int> rb8(rb7);
    RedBlackTree<int> rb9 = rb7;
    
    cout << "rb7: ";
    rb7.preOrderPrint();

    cout << "rb8: ";
    rb8.preOrderPrint();

    cout << "rb9: ";
    rb9.preOrderPrint();


    rb1 = rb2 = rb3 = rb9;
    cout << "rb1: ";
    rb1.preOrderPrint();

    cout << "rb2: ";
    rb2.preOrderPrint();

    cout << "rb3: ";
    rb3.preOrderPrint();
}



void searchTest()
{
    cout << " ------------------------------------------ Search test -----------------------------------------------" << endl;

    int value;
    RedBlackTree<int> rb;

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

    cout << "In-order printing: " << endl;
    rb.inOrderPrint();


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

    smallestValue = -100;
    largestValue = 32;
    cout << "Testing search" << "(" << smallestValue << ", " << largestValue << ") ..." << endl;
    result = rb.search(smallestValue, largestValue);
    printVector(result);

    cout << "Testing search" << "(" << largestValue << ", " << smallestValue << ") ..." << endl;
    result2 = rb.search(largestValue, smallestValue);
    printVector(result2);


    smallestValue = 14;
    largestValue = 100;
    cout << "Testing search" << "(" << smallestValue << ", " << largestValue << ") ..." << endl;
    result = rb.search(smallestValue, largestValue);
    printVector(result);

    cout << "Testing search" << "(" << largestValue << ", " << smallestValue << ") ..." << endl;
    result2 = rb.search(largestValue, smallestValue);
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
    RedBlackTree<int> rbEmpty;

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



void intTest()
{
    cout << " ------------------------------------------ int test -----------------------------------------------" << endl;

    RedBlackTree<int> rb;

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

    rb.remove(40);

    rb.preOrderPrint();
    rb.inOrderPrint();
    rb.visualize();
}



void charTest()
{
    cout << " ------------------------------------------ char test -----------------------------------------------" << endl;
    RedBlackTree<char> rb;
    rb.insert('a');
    rb.insert('g');
    rb.insert('g');
    rb.insert('e');
    rb.insert('x');
    rb.insert('z');
    rb.insert('z');
    //rb.remove('z');

    rb.preOrderPrint();
    rb.visualize();
}

void stringTest()
{
    cout << " ------------------------------------------ string test -----------------------------------------------" << endl;
    RedBlackTree<string> rb;
    rb.insert("hello");
    rb.insert("fngo");
    rb.insert("ss");
    rb.insert("wfafen");
    rb.insert("waffenSS");
    rb.insert("sugoi");
    rb.insert("wow");
    //rb.remove('z');

    rb.preOrderPrint();
    rb.visualize();
}



// ----------------------------------------------------------------------------------
//                                  MAIN
// ----------------------------------------------------------------------------------

int main()
{
    cout << "testing assignment 4 ..." << endl;

    random_test();
    copyTest();
    searchTest();
    intTest();
    charTest();
    stringTest();

    return 0;
}


// ----------------------------------------------------------------------------------
//                                  For debugging
// ----------------------------------------------------------------------------------
template <class T>
void RedBlackTree<T>::preOrderPrint() const
{
    preOrderPrint(root);
    cout << endl;
}

template <class T>
void RedBlackTree<T>::inOrderPrint() const
{
    inOrderPrint(root);
    cout << endl;
}

template <class T>
void RedBlackTree<T>::preOrderPrint(NodeT<T>* node) const
{
    if (node != nullptr) {
        char color;
        if (node->isBlack) {
            color = 'B';
        }
        else {
            color = 'R';
        }
        cout << node->data << "(" << color << ")" << " ";
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
}


template <class T>
void RedBlackTree<T>::inOrderPrint(NodeT<T>* node) const
{
    if (node != nullptr) {
        char color;
        if (node->isBlack) {
            color = 'B';
        }
        else {
            color = 'R';
        }
        inOrderPrint(node->left);
        cout << node->data << "(" << color << ")" << " ";
        inOrderPrint(node->right);
    }
}


void printVector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


template<class T>
void RedBlackTree<T>::visualize() const
{
    visualizeTraversal(root, "\t", true);
}


//put the definition int the private section in your class
template<class T>
void RedBlackTree<T>::visualizeTraversal(NodeT<T>* rootRef, string indent, bool last) const
{
    if (rootRef != nullptr) {

        cout << indent;

        if (last) {
            if (root == rootRef)
            {
                cout << "ROOT----";
            }
            else
            {
                cout << "R----";
            }

            indent += "         ";
        }
        else {
            cout << "L----";
            indent += "|  ";
        }

        string colour = rootRef->isBlack ? "B" : "R";
        cout << rootRef->data << "(" << colour << ")" << endl;

        visualizeTraversal(rootRef->left, indent, false);
        visualizeTraversal(rootRef->right, indent, true);
    }
}