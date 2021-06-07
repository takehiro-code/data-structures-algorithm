#include "Deque.h"
#include <iostream>
using std::cout;
using std::endl;

// To be completed for exercise 4
// Helper method for Deque(Deque) and op=
// ONLY CHANGE BODY OF THESE TWO METHODS
void Deque::copyDeque(const Deque & dq)
{
	// initialize n, front, back
	n = dq.n;
	front = nullptr;
	back = nullptr;

	copyNode(dq.back, front);

}

// Recursive helper method for copyDeque
void Deque::copyNode(Ex4Node* original, Ex4Node* copy)
{
	 //base case
	if (original == nullptr) {
		return;
	}
	// recusive case
	else 
	{
		// identical to insert_front
		copy = new Ex4Node(original->data, nullptr, front);
		front = copy;
		if (back == nullptr) {
			back = front;
		}
		else {
			front->next->previous = front;
		}
		copyNode(original->previous, copy);
	}
}

// DO NOT CHANGE ANYTHING BELOW THIS LINE
// --------------------------------------

Deque::Deque()
{
	front = back = nullptr;
	n = 0;
}

Deque::Deque(const Deque & dq)
{
	copyDeque(dq);
}

Deque & Deque::operator=(const Deque & dq)
{
	if (this != &dq) {
		removeAll();
		copyDeque(dq);
	}
	return *this;
}

Deque::~Deque()
{
	//cout << "... in destructor ..."; // debug print
	removeAll();
}

void Deque::insert_front(int val)
{
	Ex4Node* newNode = new Ex4Node(val, nullptr, front);
	front = newNode;
	// Deque was empty
	if (back == nullptr) {
		back = front;
	}
	else {
		front->next->previous = front;
	}
	n++;
}

void Deque::insert_back(int val)
{
	// Deque is empty
	if (back == nullptr) {
		back = new Ex4Node(val);
		front = back;
	}
	else {
		back->next = new Ex4Node(val);
		back->next->previous = back;
		back = back->next;
	}
	n++;
}

int Deque::remove_front()
{
	// Deque is empty
	if (front == nullptr) {
		throw runtime_error("remove_front failed - empty");
	}
	int result = front->data;
	Ex4Node* temp = front;
	front = front->next;
	if (front == nullptr) {
		back = nullptr;
	}
	else {
		front->previous = nullptr;
	}

	n--;
	delete temp;
	return result;
}

int Deque::remove_back()
{
	// Deque is empty
	if (back == nullptr) {
		throw runtime_error("remove_back failed - empty");
	}

	int result = back->data;
	Ex4Node* temp = back;
	back = back->previous;
	if (back == nullptr) {
		front = nullptr;
	}
	else {
		back->next = nullptr;
	}

	n--;
	delete temp;
	return result;
}

int Deque::size() const
{
	return n;
}

bool Deque::empty() const
{
	return front == nullptr && back == nullptr;
}

void Deque::removeAll()
{
	Ex4Node* temp = front;
	while (front != nullptr) {
		front = temp->next;
		delete temp;
		temp = front;
	}
	n = 0;
	front = back = nullptr;
}

void Deque::printForwards() const
{
	Ex4Node* p = front;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
}

void Deque::printBackwards() const
{
	Ex4Node* p = back;
	while (p != nullptr) {
		cout << p->data << " ";
		//cout << p->data << ": p->previous = " << p->previous << endl; //debug print
		p = p->previous;
	}
}