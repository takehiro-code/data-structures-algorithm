# Assignment 5

Template class of Hash Table class implementation for string. The real hash function in C++ STL unordered map or Python dictionary is more sophiscated than our implmentation. 

- insert and search operation is O(1) on average. Exception is when doublign the size of table when load factor is greater than 0.67. For such case, O(n).

## Files
- HashTable.h
- HashTable.cpp
- spellchecker.h


## HashTable template class

Private Attributes:
- string* arr: dynamic array that contains strings or free space.
- int arrSize : size of the array
- int h2Value: a prime number used as a part of second hash function h2
, i.e., (h2Value – (string_value % h2Value) ). This will be calculated on the constructor and insertion when doubling the size. h2Value is the first prime number greater than array_size / 2.
- int numItem: current number of items in the hash table

Private methods:
- copyHashTable
- findPrimeGreater
- isPrime
- stringToIntKey

## Spell Check Functions



