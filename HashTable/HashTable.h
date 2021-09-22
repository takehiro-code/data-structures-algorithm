#pragma once

#include <string>

using std::string;

class HashTable
{
public:
	// default constructor
	HashTable();

	// constructor to create a hash table with n items (not yet stored); arrSize (prime number) >= 2*n
	HashTable(int n);

	// copy constructor
	HashTable(const HashTable& table);

	// destructor
	~HashTable();

	// overloaded assignment operator
	HashTable& operator=(const HashTable& table);

	// POST: If word is not in hash table, insert it as long as load factor <= 0.67. 
	//		 If load factor > 0.67, create a new hash table with arrSize (prime number) > 2 * (original arrSize)
	void insert(string word);

	// POST: Return true if the word is in the hash table, otherwise return false.
	bool find(string word) const;

	// Return the number of items stored in the array
	int size() const;

	// Return the underlying array size
	int maxSize() const;

	// Return the load factor ( = numItems / arrSize) in double
	double loadFactor() const;

	// for debugging
	void printHashTable() const;

private:
	string* arr; // pointer to the dynamic array that contains strings
	int arrSize; // size of the underlying array
	int h2Value; // prime number used as a part of second hash function
	int numItems; // # of items stored in the hash table


	// Find and return a prime number greater than n
	int findPrimeGreater(int n);

	// Check if n is a prime number. Return value is bool.
	bool isPrime(int n);

	// 1st hash function: keyIndex =  word mod arrsize
	int hashFunc1(string word, int arrSizeParam) const;

	// 2nd hash function: probeValue = h2Value - (word mod h2Value)
	int hashFunc2(string word, int h2ValueParam) const;

	// Find the word in the hash table and return the corresponding integer key index on array parameter arrParam.
	int findAndReturnIndex(string word, string* arrParam, int arrSizeParam, int h2ValueParam) const;

	// helper method for copy constructor and overloaded assignment operator 
	void copyHashTable(const HashTable& table);
};