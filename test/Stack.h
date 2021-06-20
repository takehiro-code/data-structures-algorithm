#pragma once

class Stack
{
public:
	//default constructor
	Stack();

	//int constructor - set max stack size to n
	Stack(int n);

	// Destructor
	// Responsible for de-allocating the memory
	// Compiler will make empty destructor by default
	// Don't use alloc, malloc, free, which are all used by C
	~Stack();
	
	// overloaded copy constructor
	Stack(Stack& st);

	// overloaded assignment operator
	Stack & operator=(const Stack & st);

	// Mutators
	// push x at the top of the stack
	void push(int x);

	// pop the element at the top of the stack and return
	int pop();

	// Accessors
	bool empty() const;

	int size() const;

	void print() const;

private:
	int* arr;
	int top; //index of element at the top where the new element can be inserted
	int arrSize;

	//helper function, only accessible inside of class
	void copyStack(const Stack& st);
};