#pragma once
#include <stdexcept> 
class ArrayClass
{
public:
	// Constructors and Destructors

	// Default constructor
	// POST: Creates an ArrayClass object with an array of size 2
	ArrayClass();

	// Destructor
	// POST: De-allocates dynamic memory associated with object
	~ArrayClass();

	// Accessors (getters) and mutators (setters)

	// Sets the value of the next free element
	// PRE: 
	// POST: Sets index n to value, doubles size of arr if n == arrSize, increments n
	// PARAM: value = value to be set
	void insert(int value);

	// Returns the sum of the values stored in the array
	// PRE:
	// POST: Returns sum of the first n elements of arr 
	int sum() const;

	// Returns the number of elements stored in the array
	// PRE:
	// POST: Returns n
	int size() const;

	// Sets the value of the noted index
	// PRE: 0 <= i < n
	// POST arr[i] = value
	// PARAM: i = index of element to be set, value = new value
	void set(int i, int value);

	// Gets the value at the noted index
	// PRE: 0 <= i < n
	// POST returns arr[i]
	// PARAM: i = index of element to be returned
	int get(int i) const;

private:
	int* arr;
	int arrSize;
	int n;
};
