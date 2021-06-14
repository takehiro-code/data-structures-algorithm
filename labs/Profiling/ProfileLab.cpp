// ProfileLab.cpp : Defines the entry point for the console application.
//
#include "SortedList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

void profileList(string fname);
SortedList readFile(string infile);
void barometer();
void insertCost(string infile);

int main()
{
	//profileList("animals_rand.txt");
	barometer();
	cout << endl << endl;
	return 0;
}

// Reads a file into a list and then prints list
// PARAM: fname is the name of the file to be opened
void profileList(string fname)
{
	SortedList list = readFile(fname);
}

// Opens a file and reads the contents into a SortedList
// The function does not remove non-alpha characters
// PARAM: fname is the name of the file to be opened
// PRE: the file contains words separated by white space
SortedList readFile(string infile)
{
	SortedList result(200);
	string s;

	ifstream ist(infile.c_str()); // open file
								  // Check if file opened correctly
	if (ist.fail())
		throw runtime_error("file not found");

	// Read file into list
	while (ist >> s) {
		cout << "insert " << s << ": ";
		result.insert(s);
		cout << endl;
	}

	return result;
}

// Opens a file and reads the contents into a SortedList
// Displays the number of operations performed for each insert
// PARAM: fname is the name of the file to be opened
// PRE: the file contains words separated by white space
void insertCost(string infile)
{
	SortedList list(200);
	string s;

	ifstream ist(infile.c_str()); // open file
								  // Check if file opened correctly
	if (ist.fail())
		throw runtime_error("file not found");

	// Read file into list
	int ops = 0;
	int total = 0;

	// Read file into list
	cout << "Inserting " << " words from " << infile << endl;
	while (ist >> s) {
		ops = list.insert(s);
		total += ops;
		if ((list.size() - 1) % 10 == 0) { //print in columns
			cout << endl;
		}
		cout << right << setw(5) << ops;
	}
	cout << endl << endl << "Inserted " << list.size() << " words" << endl;
	cout << "Total iterations = " << total << endl;
}

// Calling function for insertCost for lab activity
void barometer()
{
	insertCost("animals_rand.txt");
	cout << "-----------------------------------------------" << endl << endl;
	insertCost("animals_sort.txt");
	cout << "-----------------------------------------------" << endl << endl;
	insertCost("animals_rev.txt");
	cout << "-----------------------------------------------" << endl << endl;
}




