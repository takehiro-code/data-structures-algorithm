#include "Stack.h"

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::out_of_range;
using std::bad_alloc;

Stack::Stack()
{
	arrSize = 10;
	top = 0;
	arr = new int[arrSize];
}


Stack::Stack(int n)
{
	arrSize = n;
	top = 0;
	arr = new int[arrSize];
}


// overloaded copy constructor
// need to make the overload copy structor because the default copy constructor made by
// the compiler will copy the same attributes (or member data), where arr memory address is same. 
// --> 1 operation of delete[] will delete both arr in 2 objects
Stack::Stack(Stack& st)
{
	copyStack(st);
}


//overloaded assignment operator
// Need to return Stack instead of void, so that you can do; st1 = st2 = st3;
Stack & Stack::operator=(const Stack & st)
{
	// for the case; st1 = st1, if you delete[] arr; the contents will be destroyed
	if (this != &st)
	{
		delete[] arr; // need this to clean up the existing attribute, especially arr before doing arr = new int[arrSize] in copyStack
		copyStack(st);
	}
	return *this;
}

Stack::~Stack()
{
	cout << " ... Calling destructor ... " << endl;
	// delete arr; // this will de-allocate the 1st element of the array
	delete[] arr;
}


// Mutators
// What to do if stack if full? -->
void Stack::push(int x)
{
	//what if the stack if null? --> use exception handling
	if (empty()) {
		throw out_of_range("Stack is empty");
	}
	arr[top] = x;
	top++;
}

int Stack::pop() 
{
	top--; // or top -= 1
	return arr[top];
}


// Accessors
// return true if stack is empty
bool Stack::empty() const
{
	return top == 0;
}
 

// Return number of values stored in stack
int Stack::size() const
{
	return top;
}


// Print the contents of the stack from bottom to top
void Stack::print() const
{
	for (int i; i < top; i++) {
		cout << arr[i] << endl;
	}
}


// helper function, being used in multiple methods
void Stack::copyStack(const Stack& st)
{
	// deep copy
	arrSize = st.arrSize;
	top = st.top;
	arr = new int[arrSize];
	for (int i = 0; i < top; i++) {
		arr[i] = st.arr[i];
	}

}

