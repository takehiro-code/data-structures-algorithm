#pragma once

#include <string>

using std::string;

class StringSet
{
public:
	// default constructor
	StringSet();

	//copy constructor
	StringSet(const StringSet& ss);

	// destructor
	~StringSet();

	// overloaded assignment operator
	StringSet & operator=(const StringSet& ss);

	// insert the string s in the sset while s is not already in sset
	bool insert(string s);

	// remove the matching string of s
	void remove(string s);

	// return the number of strings currently stored in the sset
	int size() const;

	// find the string s in the sset
	int find(string s) const;

	// return a StringSet object, the union of the calling object and StringSet object parameter
	StringSet unions(const StringSet& ss) const;

	// return a StringSet object, the intersection of the calling object and StringSet object parameter
	StringSet intersection(const StringSet& ss) const;

	// return a StringSet object, the difference of the calling object and StringSet object parameter
	StringSet difference(const StringSet& ss) const;

private:
	string *sset; // dynamic array contains a unique set of string objects
	int curSize; // number of string objects conceptually stored in the array
	int maxSize; // allocated memory size in the array

	// private helper function used in multiple public methods
	void copyStringSet(const StringSet& ss);
};