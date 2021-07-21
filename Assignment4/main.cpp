#include "RedBlackTree.h"


#include <random>
#include <iostream>
//#include <fstream>
using std::ofstream;
using std::cout;
using std::endl;

void simpleTest();
void randomTest();
void copyTest();
void searchTest();
void intTest();
void charTest();
void stringTest();
void statisticsTest();

void printVector(vector<int> vec);



// ----------------------------------------------------------------------------------
//                                  MAIN
// ----------------------------------------------------------------------------------

int main()
{
    cout << "testing assignment 4 ..." << endl;
    
    simpleTest();
    randomTest();
    copyTest();
    searchTest();
    intTest();
    charTest();
    stringTest();
    statisticsTest();

    return 0;
}


// ----------------------------------------------------------------------------------
//                                  Test Functions
// ----------------------------------------------------------------------------------

void statisticsTest()
{
    cout << " ------------------------------------------ statistics test -----------------------------------------------" << endl;

    statistics("../../../test.txt");
    cout << endl;

    // creating test3.txt
    ofstream file;
    file.open("../../../test3.txt");
    //// random generating numbers to automatically testing every possible cases
    const int range_from = 0;
    const int range_to = 1000;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    for (int i = 100; i < 110; i++) {
        //double rand_num = distr(generator) / 7.837509790;
        double rand_num = i;
        file << (double)rand_num << endl;
    }
    file.close();
    statistics("../../../test2.txt");
    cout << endl;

    statistics("../../../test3.txt");
    cout << endl;

}


void simpleTest()
{
    // Int Tree Tests	
    RedBlackTree<int> rb1;
    if (rb1.insert(42)) cout << "inserted 42" << endl;
    rb1.insert(71);
    rb1.insert(13);
    RedBlackTree<int> rb2(rb1);

    if (rb1.remove(13)) cout << "removed 13" << endl;
    if (rb1.search(42)) cout << "found 42" << endl;

    vector<int> v1 = rb1.search(50, 100); //should contain 71
    vector<int> v2 = rb1.values(); //should contain {42,71}

    cout << "closestLess(12) = " << rb1.closestLess(12) << endl;
    cout << "closestGreater(91) = " << rb1.closestGreater(91) << endl;

    cout << "size = " << rb1.size() << endl; //should be 2
}

void randomTest() 
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
        if (!rb.isRBTreeBlackHeightValid()) {
            cout << "Black Height Properties Violated" << endl;
            break;
        }
    }
    cout << "Number of values before removal: " << rb.size() << endl;

    for (int i = 0; i < 5000; i++) {
        int rand_num = distr(generator);
        rb.remove(rand_num);
        if (!rb.isRBTreeBlackHeightValid()) {
            cout << "Black Height Properties Violated" << endl;
            break;
        }
    }
    cout << "Number of values after removal: " << rb.size() << endl;
    cout << "Black Height: " << rb.getBlackHeight() << endl;

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

    cout << "The following contents are inserted" << endl;
    printVector(rb.values());

    value = 31;
    cout << "Testing rb.insert" << "(" << value << "): " << rb.insert(value) << endl;
    cout << "Testing rb.insert" << "(" << value << "): " << rb.insert(value) << endl;
    cout << "Testing rb.insert" << "(" << value << "): " << rb.insert(value) << endl;
    
    value = 310;
    cout << "Testing rb.remove" << "(" << value << "): " << rb.remove(value) << endl;
    value = 3;
    cout << "Testing rb.remove" << "(" << value << "): " << rb.remove(value) << endl;

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
    value = 32;
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
    value = 14;
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

    cout << "Black Height: " << rb.getBlackHeight() << endl;
    if (!rb.isRBTreeBlackHeightValid()) {
        cout << "Black Height Property violated." << endl;
    }

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
//                                  For debugging
// ----------------------------------------------------------------------------------
//// for debugging - place this in public method in RedBlackTree class
//void preOrderPrint() const;
//void inOrderPrint() const;
//void visualize() const;
//void preOrderPrint(NodeT<T>* node) const;
//void inOrderPrint(NodeT<T>* node) const;
//void visualizeTraversal(NodeT<T>* node, string space, bool flag) const;
//int getBlackHeight() const;
//bool isRBTreeBlackHeightValid() const;
//int computeBlackHeight(NodeT<T>* node) const;


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


template<class T>
int RedBlackTree<T>::getBlackHeight() const
{
    return computeBlackHeight(root);
}

template<class T>
bool RedBlackTree<T>::isRBTreeBlackHeightValid() const
{
    return computeBlackHeight(root) != -1;
}

// helper method
// Returns the number of black nodes in a subtree of the given node
// or -1 if it is not a red black tree.
template<class T>
int RedBlackTree<T>::computeBlackHeight(NodeT<T>* node) const {
    // For an empty subtree the answer is obvious
    if (node == nullptr)
        return 0;
    // Computes the height for the left and right child recursively
    int leftHeight = computeBlackHeight(node->left);
    int rightHeight = computeBlackHeight(node->right);

    int add = node->isBlack == true ? 1 : 0;
    // The current subtree is not a red black tree if and only if
    // one or more of current node's children is a root of an invalid tree
    // or they contain different number of black nodes on a path to a null node.
    if (leftHeight == -1 || rightHeight == -1 || leftHeight != rightHeight)
        return -1;
    else
        return leftHeight + add;
}