#include "ArrayClass.h"

// Default constructor
// POST: Creates an ArrayClass object with an array of size 2
// PARAM:
ArrayClass::ArrayClass()
{
	arrSize = 2;
	arr = new int[arrSize];
	n = 0;
}

// Destructor
// POST: De-allocates dynamic memory associated with object
ArrayClass::~ArrayClass()
{
	delete[] arr;;
}

// Returns the number of elements stored in the array
// PRE: Creates an ArrayClass object with an array of size 2
// POST: Retruns n
int ArrayClass::size() const
{
	return n;
}

// Sets the value of the next free element
// PRE:
// POST: Sets index n to value, doubles size of arr if n == arrSize, increments n 
// PARAM: value = value to be set
void ArrayClass::insert(int value)
{
	if (n == arrSize) {
		arrSize *= 2;
		int* temp = arr;
		arr = new int[arrSize];
		for (int i = 0; i < n; i++) {
			arr[i] = temp[i];
		}
		delete[] temp;
	}

	arr[n++] = value;
}

// Returns the sum of the contents of the array
// PRE:
// POST: Returns sum of the first n elements of a
int ArrayClass::sum() const
{
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += arr[i];
	}
	return result;
}

// Sets the value of the noted index
// PRE: 0 <= i < n
// POST arr[i] = value
// PARAM: i = index of element to be set, value = new value
void ArrayClass::set(int i, int value)
{
	if (i < 0 || i >= n)
	{
		throw std::out_of_range("set(i) out of range");
	}
	arr[i] = value;
}

// Gets the value at the noted index
// PRE: 0 <= i < n
// POST returns arr[i]
// PARAM: i = index of element to be returned
int ArrayClass::get(int i) const
{
	if (i < 0 || i >= n)
	{
		throw std::out_of_range("get(i) out of range");
	}
	return arr[i];
}
