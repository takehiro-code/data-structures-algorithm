// compiling instruction:
// g++ map.cpp -std=c++11

#include "map.h"
#include <iostream>
using std::cout;
using std::endl;


// printing the map contents
void printMap(const map<string, double> & gmap) 
{
	// referenced: https://stackoverflow.com/questions/14070940/how-can-i-print-out-c-map-values
	for (map<string, double>::const_iterator it = gmap.begin();
		it != gmap.end();
		++it) 
	{
		cout << it->first << " " << it->second << endl;
	}

	if (gmap.empty()) {
		cout << "Map is empty ..." << endl;
	}
	cout << endl;
}


void printVec(const vector<double>& vec) {
	for (auto el : vec) {
		cout << el << endl;
	}
	if (vec.empty()) {
		cout << "Vector is empty ..." << endl;
	}
	cout << endl;
}


int main() {
	cout << "testing map ... " << endl;

	// try test1.txt, test2.txt, testwow.txt, test3.txt
	map<string, double> gmap = readGradeFile("test12.txt");
	printMap(gmap);

	vector<double> vec = getGrades(gmap, "a", "z");
	//vector<double> vec = getGrades(gmap, "k", "m");
	printVec(vec);
	

	return 0;
}