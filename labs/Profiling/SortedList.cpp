#include "SortedList.h"
#include <iostream>
#include <stdexcept>

// Default constructor
SortedList::SortedList(void)
{
	max = 10;
	arr = new string[max];
	current = 0;
	pos = 0;
}

// Constructor that creates a list of size n
// PARAM: n is the maximum size of the list
SortedList::SortedList(int n)
{
	max = n;
	arr = new string[n];
	current = 0;
	pos = 0;
}

// Copy constructor
SortedList::SortedList(const SortedList & list)
{
	max = list.max;
	current = list.current;
	arr = new string[max];
	pos = 0;
	// Copy contents from other list
	for (int i = 0; i < current; i++) {
		arr[i] = list.arr[i];
	}
}

// Destructor
SortedList::~SortedList(void)
{
	delete[] arr;
}

// Inserts a string into the list
// PARAM: s is the string to be inserted
// POST: s is inserted in the list in alphabetic order
int SortedList::insert(string s)
{
	int count = 0;
	// Throw an error if the array is full
	if (current >= max) {
		throw runtime_error("list is full");
	}
	// Find insertion point for item
	int pos = current; //insertion point
	while (pos > 0 && s < arr[pos - 1]) {
		arr[pos] = arr[pos - 1];
		pos--;
		count++; //just count number of time while loop iterates
	}
	// Insert new string
	arr[pos] = s;
	current++;
	return count;
}

// Removes a string from the list
// PARAM: s is the string to be removed
// POST: s is removed from list while preserving order
bool SortedList::remove(string s)
{
	int pos = 0;
	// Find string to be removed
	while (pos < current && arr[pos] != s) {
		pos++;
	}

	// Move items down if s is found
	if (arr[pos] == s) {
		for (int i = pos; i < current - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		current--;
		return true;
	}
	else {
		return false;
	}
}

// Returns the next string in the list
// POST: Increments pos
string SortedList::next()
{
	string result = "";
	if (pos < current) {
		result = arr[pos];
		pos++;
	}
	return result;
}

// Sets pos to 0
void SortedList::reset()
{
	pos = 0;
}

// Returns size
int SortedList::size()
{
	return current;
}

// Overloaded assignment operator
SortedList & SortedList::operator=(const SortedList & list) {
	// If the LH and RH lists are the same must return
	// immediately to avoid deleting the list before
	// copying it, and to avoid wasting time
	// i.e. where operation is like list1 = list1
	if (this == &list) {
		return *this; //pointer to the queue
	}
	// Delete old array
	delete[] arr;
	// Make new list
	deepCopy(list);
	return *this;
}//operator=

 // Helper function for copy constructor and assignment operator
void SortedList::deepCopy(const SortedList & list) {
	current = list.current;
	max = list.max;
	arr = new string[max];
	for (int i = 0; i < current; i++) {
		arr[i] = list.arr[i];
	}
}//deepCopy
