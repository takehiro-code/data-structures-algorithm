// Referenced the code for idea from the Lecture code (our own course, posted on Canvas) stack.h and stack.cpp
// especially for copy constructor, destructor, and the overloaded assignment operator

#pragma once
#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;
using std::runtime_error;

template <class T>
class NodeT
{
public:
	T data;
	NodeT* next; // pointer that points to the next NodeT

	// Constructors
	NodeT(T val) : data(val), next(nullptr) { ; };
	NodeT(T val, NodeT* nd) : data(val), next(nd) { ; };
};


template <class T>
class QueueT
{
public:
	// default constructor
	// PRE: calling object not initialized
	// POST: creates empty QueueT
	QueueT();

	// copy constructor
	// PRE: calling object not initialized
	// POST: Copying the parameter qt into the calling objec
	QueueT(const QueueT<T>& qt);

	// destructor - deallocates the dynamic memory in the queue
	~QueueT();

	// overloaded assignment operator
	// PRE: calling object could be either not initialized or already containing the items
	// POST: The calling object will have copied contents from the passing parameter of queue
	QueueT & operator=(const QueueT& qt);

	// Insert an element to the back of the queue
	// PRE: Quene could be either empty or containing existing elements
	// POST: Parameter val will be inserted to the back of the queue
	void enqueue(T val);

	// Removes an element from the front of the queue.
	// PRE: Quene could be either empty or containing existing elements
	// POST: Empty case: Throws a runtime_error, Non-empty case: remove and returns the front item
	T dequeue();

	// prints the elements of the queue, one value per line, from front to back
	void print() const;

	// check if queue is empty or not
	bool empty() const;

	// returns the number of elements stored in the queue
	int size() const;

	// concatenating a parameter queue to the calling object of queue
	// PRE: Given two queues (calling object and parameter)
	// PARAM: Passing queue and its integer n, the first n values to take and concatenate to the calling object 
	// POST: First n values of parameter queue will be removed and added to the calling object
	void concatenate(QueueT& qt, int n);

	// merging two queues
	// PRE: Given two queues (calling object and parameter)
	// PARAM: Constant reference parameter of queue
	// POST: Returns a merged queue. e.g. calling object = {a,b,c,d,e}, parameter = {r,s,t}, result = {a,r,b,s,c,t,d,e}
	QueueT merge(const QueueT& qt) const;

	// return the front pointer for testing
	NodeT<T>* getFront() { return front; };

private:
	NodeT<T>* front; // pointer that points to the front node of the queue
	NodeT<T>* back; // pointer that points to the back node of the queue
	int sz; // number of items in the queue

	// helper function
	void copyQueueT(const QueueT& qt); // copy the parameter queue into the calling object
	void deleteQueueT(); // delete the calling object of own queue
};


// --------------------------------------------------------------------------------------
// QueueT class definitions
// --------------------------------------------------------------------------------------


// default constructor
// PRE: calling object not initialized
// POST: creates empty QueueT
template <class T>
QueueT<T>::QueueT()
{
	front = nullptr;
	back = nullptr;
	sz = 0;
}


// copy constructor
// PRE: calling object not initialized
// POST: Copying the parameter qt into the calling object
template <class T>
QueueT<T>::QueueT(const QueueT<T>& qt)
{
	copyQueueT(qt);
}


// destructor - deallocates the dynamic memory in the queue
template <class T>
QueueT<T>::~QueueT()
{
	deleteQueueT();
}

// overloaded assignment operator
// PRE: calling object could be either not initialized or already containing the items
// POST: The calling object will have copied contents from the passing parameter of queue
template <class T>
QueueT<T>& QueueT<T>::operator=(const QueueT<T>& qt) 
{
	if (this != &qt) {
		// need to delete to clean up the existing contents before copying
		deleteQueueT();
		copyQueueT(qt);
	}
	return *this;
}


// Insert an element to the back of the queue
// PRE: Quene could be either empty or containing existing elements
// POST: Parameter val will be inserted to the back of the queue
template <class T>
void QueueT<T>::enqueue(T val)
{
	// if the queue is empty, insert an element and let front and back point to this node
	if (sz == 0) {
		NodeT<T>* newNodeT = new NodeT<T>(val);
		front = newNodeT;
		back = newNodeT;
	}
	else {
		NodeT<T>* newNodeT = new NodeT<T>(val);
		back->next = newNodeT; // update previous node to point from null to the newly created node
		back = newNodeT; // update back pointer to point from previous node to the newly created node
	}
	sz++;
}


// Removes an element from the front of the queue.
// PRE: Quene could be either empty or containing existing elements
// POST: Empty case: Throws a runtime_error, Non-empty case: remove and returns the front item
template <class T>
T QueueT<T>::dequeue()
{
	if (sz == 0) {
		throw runtime_error("Attempt of removing an item from the empty queue");
	}
	else {
		T removedItem = front->data;
		NodeT<T>* nextNode = front->next;
		delete front;
		front = nextNode;
		sz--;
		return removedItem;
	}
}


// prints the elements of the queue, one value per line, from front to back
template <class T>
void QueueT<T>::print() const
{
	NodeT<T>* p = front; // pointer that points to the current position of the node in queue
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
}


// check if queue is empty or not
template <class T>
bool QueueT<T>::empty() const
{
	if (sz == 0) {
		return true;
	}
	else {
		return false;
	}
}


// returns the number of elements stored in the queue
template <class T>
int QueueT<T>::size() const
{
	return sz;
}


// concatenating a parameter queue to the calling object of queue
// PRE: Calling object is initialized already but could be either empty or non-empty
// PARAM: Passing parameter queue and its integer n, the first n values to take and concatenate to the calling object 
// POST: First n values of parameter of the queue will be removed and added to the calling object
template <class T>
void QueueT<T>::concatenate(QueueT<T>& qt, int n)
{
	if (n < 0 || n > qt.size()) {
		throw runtime_error("Number of values exceeds the queue size");
	}
	else {
		for (int i = 0; i < n; i++) 
		{
			// remove the item from qt at the front and add it to the back of the calling object queue
			T removedItem = qt.dequeue();
			enqueue(removedItem);
		}
	}
}


// merging two queues
// PRE: Given two queues (calling object and parameter)
// PARAM: Constant reference parameter of queue
// POST: Returns a merged queue. e.g. calling object = {a,b,c,d,e}, parameter = {r,s,t}, result = {a,r,b,s,c,t,d,e}
template <class T>
QueueT<T> QueueT<T>::merge(const QueueT<T>& qt) const
{
	QueueT<T> result;

	// position pointers for each queue starting from front node
	NodeT<T>* p_calling = front;
	NodeT<T>* p_param = qt.front;

	// if both of the queues reach nullptr, go out of the loop
	while (p_calling != nullptr || p_param != nullptr) 
	{
		// insert the item from the calling object first if applicable
		if (p_calling != nullptr) {
			result.enqueue(p_calling->data);
			p_calling = p_calling->next;
		}

		// after inserting the item from the calling object, insert the item from the parameter if applicable
		if (p_param != nullptr) {
			result.enqueue(p_param->data);
			p_param = p_param->next;
		}
	}
	return result;
}


// --------------------------------------------------------------------------------------
// Helper functions
// --------------------------------------------------------------------------------------

// helper function used in the copy constructor and overloaded assignment operator
template <class T>
void QueueT<T>::copyQueueT(const QueueT<T>& qt)
{
	// initialize the front and back pointers
	sz = 0;
	front = nullptr;
	back = nullptr;

	// copy the contents to the calling object from front to back
	NodeT<T>* p = qt.front; // position pointer starting from front to back
	while (p != nullptr)
	{
		enqueue(p->data);
		p = p->next;
	}
}


// helper function used in the overloaded assignment operator and destructor
template <class T>
void QueueT<T>::deleteQueueT()
{
	// de-allocates the memory
	while (front != nullptr)
	{
		NodeT<T>* nextNode = front->next;
		delete front;
		front = nextNode;
	}
	
	// reset the class attributes
	sz = 0;
	front = nullptr;
	back = nullptr;
}