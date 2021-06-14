#pragma once
#include <string>
using namespace std;

class SortedList
{
public:
	// Constructors and destructor
	SortedList(void);
	SortedList(int);
	SortedList(const SortedList & list);
	~SortedList(void);

	// Mutators
	int insert(string s);
	bool remove(string s);

	// Accessors
	string next();
	void reset();
	int size();

	// Overloaded assignment operator
	SortedList& operator=(const SortedList & list);

private:
	int current;
	int max;
	int pos;
	string* arr;
	void deepCopy(const SortedList & list);
};


