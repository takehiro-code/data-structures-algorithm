#include "QueueT.h"
#include <string>
using std::string;

void simpleTest()
{
    cout << "SIMPLE TEST" << endl;
    QueueT<int> q1;

    q1.enqueue(2);
    q1.enqueue(4);
    q1.enqueue(6);

    cout << "empty: 0 = " << q1.empty() << endl;
    cout << "print: {2,4,6} = ";
    q1.print();
    cout << endl << "size: 3 = " << q1.size() << endl;

    QueueT<int> q2(q1);
    QueueT<int> q3;
    q3 = q1;

    q1.dequeue();

    cout << "q1 post copy: {4,6} = ";
    q1.print();
    cout << endl << "q2 (copy): {2,4,6} = ";
    q2.print();
    cout << endl << "q3 (op=): {2,4,6} = ";
    q3.print();

    QueueT<int> q4;
    q4.enqueue(5);

    QueueT<int> q5(q1.merge(q4));
    cout << endl << "q5 (merge): {4,5,6} = ";
    q5.print();

    q1.concatenate(q4, 1);
    cout << endl << "q1 (concatenate): {4,6,5} = ";
    q1.print();

    NodeT<int>* front = q1.getFront();
    cout << endl << "front->next->data: 6 = " << front->next->data << endl;
    cout << "END SIMPLE TEST" << endl;
}



void intTest() 
{
    cout << "test qt1 (multiple items) ..." << endl;
    // (front) 1 -> 3 -> 5 -> 7 (back) -> null
    cout << "Expected: (front) 3 -> 5 -> 7 (back) -> null" << endl;
    QueueT<int> qt1;
    qt1.enqueue(1);
    qt1.enqueue(3);
    qt1.enqueue(5);
    qt1.enqueue(7);
    cout << "Removing item from the front: " << qt1.dequeue() << endl;
    qt1.print();
    cout << "# of items = " << qt1.size() << endl;
    cout << "Empty?: " << qt1.empty() << endl;
    cout << "Front node: " << qt1.getFront()->data << endl;
    cout << endl;


    cout << "test qt2 (one item) ..." << endl;
    // (front, back) 1 -> null
    cout << "Expected: (front, back) 1 -> null" << endl;
    QueueT<int> qt2;
    qt2.enqueue(1);
    qt2.print();
    cout << "# of items = " << qt2.size() << endl;
    cout << "Empty?: " << qt2.empty() << endl;
    cout << "Front node: " << qt2.getFront()->data << endl;
    cout << endl;


    cout << "test qt3 (empty queue) ..." << endl;
    // (front, back) -> null
    cout << "Expected: (front, back) -> null" << endl;
    QueueT<int> qt3;
    try {
        qt3.dequeue(); // runtime_error
    }
    catch (runtime_error re) {
        cout << "it's an error!" << endl;
    }
    cout << "# of items = " << qt3.size() << endl;
    cout << "Empty?: " << qt3.empty() << endl;
    cout << endl;


    cout << "test qt4 ..." << endl;
    cout << "Expected: (front) 3 -> 5 -> 7 (back) -> null" << endl;
    QueueT<int> qt4(qt1);
    qt4.print();
    cout << "# of items = " << qt4.size() << endl;
    cout << "Empty?: " << qt4.empty() << endl;
    cout << "Front node: " << qt4.getFront()->data << endl;
    cout << endl;


    cout << "test qt5 ..." << endl;
    cout << "Expected: (front, back) -> null" << endl;
    QueueT<int> qt5(qt3);
    qt5.print();
    cout << "# of items = " << qt5.size() << endl;
    cout << "Empty?: " << qt5.empty() << endl;
    cout << endl;


    cout << "test qt6 ..." << endl;
    cout << "Expected: (front) 3 -> 5 -> 7 (back) -> null" << endl;
    QueueT<int> qt6 = qt1;
    qt6.print();
    cout << "# of items = " << qt6.size() << endl;
    cout << "Empty?: " << qt6.empty() << endl;
    cout << "Front node: " << qt6.getFront()->data << endl;
    cout << endl;


    cout << "test qt6 ..." << endl;
    cout << "Expected: (front, back) -> null" << endl;
    qt6 = qt3;
    qt6.print();
    cout << "# of items = " << qt6.size() << endl;
    cout << "Empty?: " << qt6.empty() << endl;
    cout << endl;


    cout << "test qt7 and qt8 for concatenation ..." << endl;
    cout << "Expected for qt7: (front) 3 -> 5 -> 7 -> 3 -> 5 (back) -> null" << endl;
    cout << "Expected for qt8: (front, back) 7 -> null" << endl;
    QueueT<int> qt7, qt8;
    qt7 = qt1;
    qt8 = qt1;
    qt7.concatenate(qt8, 2);
    qt7.print();
    cout << "# of items = " << qt7.size() << endl;
    cout << "Empty?: " << qt7.empty() << endl;
    cout << endl;

    qt8.print();
    cout << "# of items = " << qt8.size() << endl;
    cout << "Empty?: " << qt8.empty() << endl;
    cout << endl;

    cout << "test qt9, qt10, qt11 for merging ..." << endl;
    //cout << "Expected for qt7: (front) 3 -> 5 -> 7 -> 3 -> 5 (back) -> null" << endl;
    QueueT<int> qt9, qt10, qt11;
    qt10 = qt1;
    qt11.enqueue(4);
    qt11.enqueue(8);
    qt11.enqueue(1);
    qt11.enqueue(9);
    qt11.enqueue(-4);
    qt9 = qt10.merge(qt11);
    qt9.print();
    cout << "# of items = " << qt9.size() << endl;
    cout << "Empty?: " << qt9.empty() << endl;
    cout << "Front node: " << qt9.getFront()->data << endl;
    cout << endl;
}


void stringTest()
{
    cout << "test qt1 (multiple items) ..." << endl;
    cout << "Expected: (front) eagle -> pig -> dog (back) -> null" << endl;
    QueueT<string> qt1;
    qt1.enqueue("human");
    qt1.enqueue("eagle");
    qt1.enqueue("pig");
    qt1.enqueue("dog");
    cout << "Removing item from the front: " << qt1.dequeue() << endl;
    qt1.print();
    cout << "# of items = " << qt1.size() << endl;
    cout << "Empty?: " << qt1.empty() << endl;
    cout << "Front node: " << qt1.getFront()->data << endl;
    cout << endl;


    cout << "test qt2 (one item) ..." << endl;
    // (front, back) 1 -> null
    cout << "Expected: (front, back) bear -> null" << endl;
    QueueT<string> qt2;
    qt2.enqueue("bear");
    qt2.print();
    cout << "# of items = " << qt2.size() << endl;
    cout << "Empty?: " << qt2.empty() << endl;
    cout << "Front node: " << qt2.getFront()->data << endl;
    cout << endl;


    cout << "test qt3 (empty queue) ..." << endl;
    // (front, back) -> null
    cout << "Expected: (front, back) -> null" << endl;
    QueueT<string> qt3;
    try {
        qt3.dequeue(); // runtime_error
    }
    catch (runtime_error re) {
        cout << "it's an error!" << endl;
    }
    cout << "# of items = " << qt3.size() << endl;
    cout << "Empty?: " << qt3.empty() << endl;
    cout << endl;


    cout << "test qt4 ..." << endl;
    cout << "Expected: (front) eagle -> pig -> dog (back) -> null" << endl;
    QueueT<string> qt4(qt1);
    qt4.print();
    cout << "# of items = " << qt4.size() << endl;
    cout << "Empty?: " << qt4.empty() << endl;
    cout << "Front node: " << qt4.getFront()->data << endl;
    cout << endl;


    cout << "test qt5 ..." << endl;
    cout << "Expected: (front, back) -> null" << endl;
    QueueT<string> qt5(qt3);
    qt5.print();
    cout << "# of items = " << qt5.size() << endl;
    cout << "Empty?: " << qt5.empty() << endl;
    cout << endl;


    cout << "test qt6 ..." << endl;
    cout << "Expected: (front) eagle -> pig -> dog (back) -> null" << endl;
    QueueT<string> qt6 = qt1;
    qt6.print();
    cout << "# of items = " << qt6.size() << endl;
    cout << "Empty?: " << qt6.empty() << endl;
    cout << "Front node: " << qt6.getFront()->data << endl;
    cout << endl;


    cout << "test qt6 ..." << endl;
    cout << "Expected: (front, back) -> null" << endl;
    qt6 = qt3;
    qt6.print();
    cout << "# of items = " << qt6.size() << endl;
    cout << "Empty?: " << qt6.empty() << endl;
    cout << endl;


    cout << "test qt7 and qt8 for concatenation ..." << endl;
    cout << "Expected for qt7: (front) eagle -> pig -> dog -> eagle -> pig (back) -> null" << endl;
    cout << "Expected for qt8: (front, back) 7 -> null" << endl;
    QueueT<string> qt7, qt8;
    qt7 = qt1;
    qt8 = qt1;
    qt7.concatenate(qt8, 2);
    qt7.print();
    cout << "# of items = " << qt7.size() << endl;
    cout << "Empty?: " << qt7.empty() << endl;
    cout << endl;

    qt8.print();
    cout << "# of items = " << qt8.size() << endl;
    cout << "Empty?: " << qt8.empty() << endl;
    cout << endl;

    cout << "test qt9, qt10, qt11 for merging ..." << endl;
    //cout << "Expected for qt7: (front) 3 -> 5 -> 7 -> 3 -> 5 (back) -> null" << endl;
    QueueT<string> qt9, qt10, qt11;
    qt10 = qt1;
    qt11.enqueue("bird");
    qt9 = qt10.merge(qt11);
    qt9.print();
    cout << "# of items = " << qt9.size() << endl;
    cout << "Empty?: " << qt9.empty() << endl;
    cout << "Front node: " << qt9.getFront()->data << endl;
    cout << endl;
}


void charTest() {
    QueueT<char> qt1, qt2, qt3;
    cout << "Expected: {a,r,b,s,c,t,d,e}" << endl;
    qt1.enqueue('a');
    qt1.enqueue('b');
    qt1.enqueue('c');
    qt1.enqueue('d');
    qt1.enqueue('e');

    qt2.enqueue('r');
    qt2.enqueue('s');
    qt2.enqueue('t');

    qt3 = qt1.merge(qt2);
    qt3.print();
    cout << "# of items = " << qt3.size() << endl;
    cout << "Empty?: " << qt3.empty() << endl;
    cout << "Front node: " << qt3.getFront()->data << endl;
    cout << endl;
}


void floatTest() {
    QueueT<float> qt1, qt2;
    qt1.enqueue(1.5);
    qt1.enqueue(2.5);
    qt1.enqueue(3.35);
    qt1.enqueue(-9.2);
    qt1.enqueue(3.35);
    qt1.enqueue(3.35);
    qt1.enqueue(-3.35);

    
    cout << "Removing: " << qt1.dequeue() << endl;
    cout << "Removing: " << qt1.dequeue() << endl;
    cout << "Removing: " << qt1.dequeue() << endl;

    qt2.enqueue(3.14);
    qt2.concatenate(qt1, 4);

    try {
        qt2.concatenate(qt1, 40);
    }
    catch (runtime_error re){
        cout << "error occur!!" << endl;
    }
    qt2.print();
    cout << "# of items = " << qt2.size() << endl;
    cout << "Empty?: " << qt2.empty() << endl;
    cout << "Front node: " << qt2.getFront()->data << endl;
    cout << endl;

}


int main()
{
    cout << "testing Queue program ..." << endl;

    cout << "------------------------------- simple testing --------------------------" << endl;
    simpleTest();

    cout << "------------------------------- int testing --------------------------" << endl;
    intTest();

    cout << "------------------------------- string testing --------------------------" << endl;
    stringTest();

    cout << "------------------------------- char testing --------------------------" << endl;
    charTest();

    cout << "------------------------------- float testing --------------------------" << endl;
    floatTest();

    return 0;
}