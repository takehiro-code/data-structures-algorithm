#pragma
#include <map>
#include <vector>
#include <string>
#include <fstream>

using std::map;
using std::vector;
using std::string;
using std::ifstream;

//#include <iostream>
//using std::cout;
//using std::endl;

// function declarations
map<string, double> readGradeFile(string fname);
//vector<double> getGrades(const map<string, double>& gradeMap, string start, string end);


// function defintions
// 
// PARAM: fname is the full name of the file
// POST: File content is read into a map, where key-value pairs are sorted according to key. Returning such map.
map<string, double> readGradeFile(string fname) 
{
	map<string, double> gradeMap;
	ifstream gradeFile(fname);

	string name;
	double grade;

	if (gradeFile.is_open()) {
		while (gradeFile >> name >> grade)
		{
			gradeMap.insert({ name, grade });
		}
	}
	gradeFile.close();
	return gradeMap;
}


// NOTE: (*it).first is equivalent to it->first

// print the contents of fitered map values
// PARAM: 
//		gradeMap: a list of key-value pairs of person name and grade value
//		start: lower bound of key from start (including start)
//		end:   upper bound of key up to end (not including end)
// POST: returning a vector from lower bound to upper bound
vector<double> getGrades(const map<string, double>& gradeMap, string start, string end) 
{
	vector<double> vec;

	// for the invalid case, return empty vector
	if (start >= end) {
		return vec;
	}

	// lower bound: a first key that is greater than or equal to start, i.e, key >= start
	// upper bound: a first key that is greater than or equal to end, i.e, key >= end
	// if start or end exceed key, it will return gradeMap.end(); try it with (--it)->first to confirm
	map<string, double>::const_iterator itlow = gradeMap.lower_bound(start);
	map<string, double>::const_iterator itup = gradeMap.upper_bound(end);
	
	//// these are just debug comments
	//cout << "Debug output: " << itlow->first << " " << itlow->second << endl;
	//cout << "Debug output: " << itup->first << " " << itup->second << endl;

	// iterating from lower bound (including itlow) to upper bound (not including itup)
	for (map<string, double>::const_iterator it = itlow;
		it != itup;
		++it)
	{
		// to avoid the key == end to be included
		if (it->first < end) {
			vec.push_back(it->second); // push back the value (grade)
		}
	}
	return vec;
}