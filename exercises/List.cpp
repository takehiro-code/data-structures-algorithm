#include "List.h"
#include <iostream>

using std::cout;
using std::endl;

// To be completed for exercise 3
// ONLY CHANGE BODY OF THIS METHOD
int List::remove(int val)
{
	// initialize the position pointer from head
	Ex3Node *p = head;
	int removeCount = 0; // counter of nodes to be remove

	// special condition; if list does not contain any elements
	if (head == nullptr) {
		return removeCount;
	}

	// loop through all the nodes until the next node is nullptr
	while(p->next != nullptr) 
	{
		//// if the next node is the one to be removed, remove it.
		if (p->next->data == val) 
		{
			Ex3Node* temp = p->next;
			p->next = p->next->next; // update the next pointer with the next next pointer
			delete temp;
			removeCount++;
			// if you removed the element, p is already moved to the next node, so no need to update p
		}
		else {
			// move to the next node
			p = p->next;
		}
	}

	// if the top node match with the value, remove it and update the head pointer
	if (head->data == val)
	{
		Ex3Node* oldHead = head;
		head = head->next;
		delete oldHead;
		removeCount++;
	}
	return removeCount;
}

// Constructors and destructor
// Creates an empty list
List::List()
{
	head = nullptr;
}

List::~List()
{
	deleteList();
}
// Copy constructor and overloaded assignment operator not implemented

// Mutators------------------
// PARAM: val = value to be inserted
// POST: inserts val at the front of the list
void List::insert(int val)
{
	Ex3Node* newNode = new Ex3Node(val, head);
	head = newNode;
}

// int remove - see top of file

// Helper method for destructor
// (and un-implemented overloaded assignment operator)
void List::deleteList()
{
	Ex3Node* temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// Accessors
bool List::check(const vector<int> & v) const
{
	Ex3Node* p = head;
	for (int x : v) {
		if (p == nullptr || p->data != x) {
			return false;
		}
		p = p->next;
	}

	return (p == nullptr); // p != nullptr list contains unchecked values
}

// Prints the contents of the list starting from head
void List::print() const
{
	Ex3Node*p = head;
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
}