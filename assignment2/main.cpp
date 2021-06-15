#include "QueueT.h"

void intTest() 
{
    cout << "test qt1 (multiple items) ..." << endl;
    // (front) 1 -> 3 -> 5 -> 7 (back) -> null
    cout << "Expected: (front) 3 -> 5 -> 7 (back) -> null" << endl;
    QueueT qt1;
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
    QueueT qt2;
    qt2.enqueue(1);
    qt2.print();
    cout << "# of items = " << qt2.size() << endl;
    cout << "Empty?: " << qt2.empty() << endl;
    cout << "Front node: " << qt2.getFront()->data << endl;
    cout << endl;


    cout << "test qt3 (empty queue) ..." << endl;
    // (front, back) -> null
    cout << "Expected: (front, back) -> null" << endl;
    QueueT qt3;
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
    QueueT qt4(qt1);
    qt4.print();
    cout << "# of items = " << qt4.size() << endl;
    cout << "Empty?: " << qt4.empty() << endl;
    cout << "Front node: " << qt4.getFront()->data << endl;
    cout << endl;


    cout << "test qt5 ..." << endl;
    cout << "Expected: (front, back) -> null" << endl;
    QueueT qt5(qt3);
    qt5.print();
    cout << "# of items = " << qt5.size() << endl;
    cout << "Empty?: " << qt5.empty() << endl;
    cout << endl;


    cout << "test qt6 ..." << endl;
    cout << "Expected: (front) 3 -> 5 -> 7 (back) -> null" << endl;
    QueueT qt6 = qt1;
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
    QueueT qt7, qt8;
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
    QueueT qt9, qt10, qt11;
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


int main()
{
    cout << "testing Assignment 2 ..." << endl;

    cout << "------------------------------- int testing --------------------------" << endl;
    intTest();


    return 0;
}