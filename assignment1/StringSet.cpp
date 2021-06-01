#include "StringSet.h"

// default constructor
// PRE: Calling object that is not initialized yet
// PARAM: None
// POST: Allocate memory sset with size of 2, no contents in it yet
StringSet::StringSet()
{
	sset = new string[2];
	maxSize = 2;
	curSize = 0;
}


// copy constructor
// PRE: Calling object that is not initialized yet
// PARAM: StringSet object
// POST: Copy the contents to the calling object
StringSet::StringSet(const StringSet& ss)
{
	copyStringSet(ss);
}

// destructor
// Only de-allocate the sset but no need to set curSize and maxSize to 0 since the these will never be used
StringSet::~StringSet() 
{
	delete[] sset;
}


// PRE: the attributes in the own class may already contain the contents.
// PARAM: Passing another StringSet object, which cannot be modified
// POST: Calling object is either initialized or overwritten by ss
StringSet& StringSet::operator=(const StringSet& ss)
{
	if (this != &ss)
	{
		// need to delete to clean up the existing contents before copying
		delete[] sset;
		copyStringSet(ss);
	}
	return *this;
}


// PRE: unique set of string objects
// PARAM: string you want to insert
// POST: if string already exist in the array, return false. 
// If not, then insert the string at next available index. If sset is full, double the max size.
bool StringSet::insert(string s)
{
	int index = find(s);
	if (index == -1) // string does not exist in the array
	{
		if (curSize < maxSize) 
		{
			sset[curSize] = s; // next available index at sset = curSize = maxIndex + 1
			curSize++;
			return true;
		}
		else
		{
			// create the new attributes in the new memory location
			string *new_sset = new string[2 * maxSize];
			int new_maxSize = 2 * maxSize;
			int new_curSize = curSize; // made new curSize for consistency

			//copy the contents of the calling object's attributes to the new attributes
			for (int i = 0; i < curSize; i++)
			{
				new_sset[i] = sset[i];
			}
			
			// free the memory of original calling object sset
			delete[] sset;

			// assign the pointer to the new sset to the original sset & update other attributes
			sset = new_sset;
			curSize = new_curSize;
			maxSize = new_maxSize;

			// finally, insert the string at the next available index
			sset[curSize] = s;
			curSize++;
			return true;
		}
	}
	else // string already exist in the array
	{
		return false;
	}
}


// PRE: calling object with unique set of string objects in sset
// PARAM: string to find
// POST: matching string will be replaced with the last string (because order does not matter)
void StringSet::remove(string s) 
{
	for (int i = 0; i < curSize; i++) 
	{
		if (sset[i] == s) {
			sset[i] = sset[curSize - 1]; // assign the last string to the element you want to remove
			curSize--; // only decrements the curSize, ignore the memory assigned at the original curSize for now
			return; // assuming no duplicates
		}
	}
}


// PRE: unique set of string objects
// PARAM: string you want to find in the array
// POST: if string is in the array, return the corresponding index. Otherwise -1.
int StringSet::find(string s) const
{
	for (int i = 0; i < curSize; i++) {
		if (sset[i] == s) {
			return i;
		}
	}

	// no string matching in the array
	return -1;
}


// PRE: calling object with set of unique strings
// PARAM: no parameters
// POST: return the number of sset
int StringSet::size() const
{
	return curSize;
}


// PRE: Given 2 StringSet object: calling object and StringSet object ss
// PARAM: StringSet object ss
// POST: Returns the union result of given 2 StringSet objects
StringSet StringSet::unions(const StringSet& ss) const
{
	StringSet res; // initialize returning result

	// first populate the calling object on the res
	for (int i = 0; i < curSize; i++) 
	{
		res.insert(sset[i]);
	}

	// next, insert string to the result if it doesn't already exist in the result
	for (int i = 0; i < ss.curSize; i++) 
	{
		// same string in result NOT found in ss.sset
		if (res.find(ss.sset[i]) == -1) {
			res.insert(ss.sset[i]);
		}
	}
	return res;
}


// PRE: Given the calling object and StringSet object, where both have unique set of strings
// PARAM: StringSet object that cannot be modified
// POST: Returns the intersection of the calling object and StringSet object
StringSet StringSet::intersection(const StringSet& ss) const
{
	StringSet res; // initialize returning result

	// compeltely different way of implementation than union without using insert, remove, find to achieve better performance
	// loop through ss.sset for each sset in the calling object
	for (int i = 0; i < curSize; i++)
	{
		for (int j = 0; j < ss.curSize; j++) 
		{
			// same string in calling object found in ss.sset
			if (sset[i] == ss.sset[j]) {
				res.insert(sset[i]);
				continue; // assuming sset has unique set of string, no need to loop the rest
			}
		}
	}
	return res;
}


// PRE: Given the calling object and StringSet object, where both have unique set of strings
// PARAM: StringSet object that cannot be modified
// POST: Returns the difference of the calling object and StringSet object (calling object - StringSet object param)
StringSet StringSet::difference(const StringSet& ss) const
{
	StringSet res; // initialize returning result

	// first populate the calling object on the res
	for (int i = 0; i < curSize; i++)
	{
		res.insert(sset[i]);
	}

	// next, remove string in the result if it matches with the string in ss.sset, looping through ss.sset
	for (int i = 0; i < ss.curSize; i++)
	{
		// same string in result found in ss.sset
		if (res.find(ss.sset[i]) != -1) {
			res.remove(ss.sset[i]);
		}
	}
	return res;
}


// helper function, being used in multiple methods
// PRE: Calling object that is not initialize yet
// PARAM: StringSet object
// POST: Initialize the calling object from the parameter StringSet object
void StringSet::copyStringSet(const StringSet& ss)
{
	// deep copy ... copy element by element
	maxSize = ss.maxSize;
	curSize = ss.curSize;
	sset = new string[maxSize];
	for (int i = 0; i < maxSize; i++) {
		sset[i] = ss.sset[i];
	}
}