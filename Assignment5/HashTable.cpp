
#include "HashTable.h"

// default constructor
// initializing a hash table with arrSize = 101
HashTable::HashTable() 
{
	arrSize = 101;
	arr = new string[arrSize];
	for (int i = 0; i < arrSize; i++) {
		arr[i] = "";
	}
	h2Value = findPrimeGreater(arrSize / 2);
	numItems = 0;
}


// PRE: n > 0
// PARAM: n items to be stored in the hash table
// POST: Initializing a hash table with arrSize (prime number) >= 2*n 
HashTable::HashTable(int n)
{
	if (isPrime(2 * n)) { // this is impossible case ... but just in case to have here according to the requirement (== 2 * n)
		arrSize = 2 * n;
	}
	else {
		arrSize = findPrimeGreater(2 * n); // ( > 2 * n case)
	}

	arr = new string[arrSize];
	for (int i = 0; i < arrSize; i++) {
		arr[i] = "";
	}
	h2Value = findPrimeGreater(arrSize / 2);
	numItems = 0;
}



// copy constructor
// PRE: calling object not initialized yet
// POST: contents in the parameter table are copied into the calling object
HashTable::HashTable(const HashTable& table)
{
	copyHashTable(table);
}


// destructor
HashTable::~HashTable()
{
	delete[] arr;
}

// overloaded assignment operator
// PRE: calling object may already contains the contents
// POST: contents in the parameter table are copied into the calling object only if parameter table is not a calling object
HashTable& HashTable::operator=(const HashTable& table)
{
	if (this != &table)
	{
		// need to delete to clean up the existing contents before copying
		delete[] arr;
		copyHashTable(table);
	}
	return *this;
}


// POST: If word is not in hash table, insert it as long as load factor <= 0.67. 
//		 If load factor > 0.67, create a new hash table with arrSize (prime number) > 2 * (original arrSize)
void HashTable::insert(string word)
{
	// get key index for word on the arr (calling object)
	int keyIndex = findAndReturnIndex(word, arr, arrSize, h2Value);

	// if word is not found, proceed with insert operation
	if (arr[keyIndex] == "") {
		double loadFactorAfterInsert = (double) (numItems + 1) / arrSize;

		// if the load factor after insert is less than or equal to 0.67, we can just insert
		if (loadFactorAfterInsert <= 0.67) {
			arr[keyIndex] = word;
			numItems++;
		}
		// if the load factor after insert is greater than 0.67
		else {
			// Create a new hash table with new arrSize (prime number) > 2 * original arrSize and new attributes
			int newArrSize = findPrimeGreater(2 * arrSize);
			string* newArr = new string[newArrSize];
			for (int i = 0; i < newArrSize; i++) {
				newArr[i] = "";
			}
			int newh2Value = findPrimeGreater(newArrSize / 2);
			int newNumItems = 0;

			// Copy the existing contents into the new hash table
			int newKeyIndex;
			for (int i = 0; i < arrSize; i++) {
				// when the space is non-empty, get key indeces for the existing words on the new array and assign them
				if (arr[i] != "") {
					string existingWord = arr[i];
					newKeyIndex = findAndReturnIndex(existingWord, newArr, newArrSize, newh2Value);
					newArr[newKeyIndex] = existingWord;
					newNumItems++;
				}
			}

			// after copying the existing contents into the new hash table, insert the new word at the new key index
			newKeyIndex = findAndReturnIndex(word, newArr, newArrSize, newh2Value);
			newArr[newKeyIndex] = word;
			newNumItems++;

			// finally, clean up and swap the attributes
			delete[] arr; // de-allocate the memory asscoiated with the old contents
			arr = newArr; // assign the new pointer
			arrSize = newArrSize;
			h2Value = newh2Value;
			numItems = newNumItems;
		}
	}
}


// POST: Return true if the word is in the hash table, otherwise return false.
bool HashTable::find(string word) const
{
	// get key index for word on the arr (calling object)
	int keyIndex = findAndReturnIndex(word, arr, arrSize, h2Value);
	// if the arr at integer key index is free space (empty string), return false
	if (arr[keyIndex] == "") {
		return false;
	}
	else {
		return true;
	}
}


int HashTable::size() const
{
	return numItems;
}


int HashTable::maxSize() const
{
	return arrSize;
}


double HashTable::loadFactor() const
{
	return (double)numItems / arrSize;
}


// --------------------------------------------------------------------------------------------------------
//											Helper Methods
// --------------------------------------------------------------------------------------------------------

// Find and return a first prime number greater than integer n
int HashTable::findPrimeGreater(int n)
{
	int result = n + 1; // start from n

	// increment result by 1 until result is prime number
	while (!isPrime(result)) {
		result++;
	}
	return result;
}


// n is prime if n cannot be divided by i = 2 .. n-1
// POST: Return true if n is prime number, otherwise false. O(n) time complexity.
bool HashTable::isPrime(int n)
{
	// special cases
	if (n == 0 || n == 1) {
		return false;
	}

	int i = 2;
	// if n cannot be divisible by i = 2 .. n-1, then n is a prime number
	while (n % i > 0 && i < n)
	{
		i++;
	}

	// if i proceeds up to n, n is a prime number
	if (i == n) {
		return true;
	}
	else {
		return false;
	}
}


// 1st hash function: (integer key index in the hash table) = (integer representation of word) mod arrSizeParam
// POST: return the integer key index from the 1st hash function 
int HashTable::hashFunc1(string word, int arrSizeParam) const
{
	// use Horner's method with applying mod operator to prevent overflow
	int i = 0;
	int factor = word[i] - 96; //ASCII 'a' = 97
	while (i < word.size() - 1)
	{
		int charIntNext = word[i + 1] - 96;
		factor = factor * 32 + charIntNext;
		factor = factor % arrSizeParam; // applying mod operator here
		i++;
	}
	return factor;
}


// 2nd hash function: probeValue = h2ValueParam - ( (integer representation of word) mod h2ValueParam) when there is collision
// the return value, probeValue will be added to the result from hasfFunc1
// POST: return the probe value from the second hash function
int HashTable::hashFunc2(string word, int h2ValueParam) const
{
	// use Horner's method to represent word in integer representation while computing second hash function
	int i = 0;
	int factor = word[i] - 96; //ASCII 'a' = 97
	while (i < word.size() - 1)
	{
		int charIntNext = word[i + 1] - 96;
		factor = factor * 32 + charIntNext;
		factor = factor % h2ValueParam; // applying mod operator here
		i++;
	}
	int probValue = h2ValueParam - factor;
	return probValue;
}


// PARAM:
//		 arrParam: array for the hash table. It may or may not be an attribute of the calling object
//		 arrSizeParam: corresponding array size of the arrParam
//		 h2ValueParam: corresponding h2Value for the arrParam
// POST: Return the integer key index for the corresponding word on the array parameter.
//       If word is not found, the integer key index for the empty string "" is returned.
int HashTable::findAndReturnIndex(string word, string* arrParam, int arrSizeParam, int h2ValueParam) const
{
	int keyIndex = hashFunc1(word, arrSizeParam);

	while (arrParam[keyIndex] != word) {
		// whenever free element is found, search is unsuccessful, return the corresponding index at the free space
		if (arrParam[keyIndex] == "") {
			return keyIndex;
		}
		// arrParam[keyIndex] is not free element but occupied by other word, then increment by the probeValue
		else {
			int probeValue = hashFunc2(word, h2ValueParam);
			keyIndex = keyIndex + probeValue;

			// when keyIndex exceed the arrSizeParam, loop back to the starting index of arrParam
			// since arrSize is prime number that cannot be even (except number 2), it won't go over the same index
			if (keyIndex >= arrSizeParam) {
				keyIndex = keyIndex - arrSizeParam;
			}
		}
	}
	// reaching here whenever arrParam[keyIndex] == word, word is found
	return keyIndex;
}


// helper method for copy constructor and overloaded assignment operator
// PRE: Calling object that is not initialize yet
// PARAM: hash table object
// POST: Initialize the calling object from the parameter HashTable object
void HashTable::copyHashTable(const HashTable& table)
{
	// deep copy ... copy element by element
	arrSize = table.arrSize;
	arr = new string[arrSize];
	for (int i = 0; i < arrSize; i++) {
		arr[i] = table.arr[i];
	}
	h2Value = table.h2Value;
	numItems = table.numItems;
	
}