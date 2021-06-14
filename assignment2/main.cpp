#include "QueueT.h"

void intTest() 
{
    cout << "test qt1 ..." << endl;
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


    cout << "test qt2 ..." << endl;
    // (front, back) 1 -> null
    cout << "Expected: (front, back) 1 -> null" << endl;
    QueueT qt2;
    qt2.enqueue(1);
    qt2.print();
    cout << "# of items = " << qt2.size() << endl;
    cout << "Empty?: " << qt2.empty() << endl;
    cout << "Front node: " << qt2.getFront()->data << endl;
    cout << endl;


    cout << "test qt3 ..." << endl;
    // (front, back) -> null
    cout << "Expected: (front, back) -> null" << endl;
    QueueT qt3;
    //qt3.dequeue(); // it will cause memoty leak
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

}


int main()
{
    cout << "testing Assignment 2 ..." << endl;

    cout << "------------------------------- int testing --------------------------" << endl;
    intTest();

    return 0;
}