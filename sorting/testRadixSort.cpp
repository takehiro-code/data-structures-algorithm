// compiling instruction:
// g++ testRadixSort.cpp -std=c++11


#include "radixSort.h"

#include <iostream>
using std::cout;
using std::endl;

void printVector(const vector<string>& vec);

int main() 
{	
	cout << "Testing testRadixSort program ... " << endl;

	vector<string> words = { "dog","cat","apt","sue","bob","dam","and","ape","sum","dim" };
	int len = 3;

	printVector(words);
	radixsort(words, len);
	printVector(words);

	words = { "a","h","z","b","a","c","j","x","c","e" };
	len = 1;

	printVector(words);
	radixsort(words, len);
	printVector(words);
	

	words = { "kyoko", "tanaka", "hydro", "apple", "human" };
	len = 5;

	printVector(words);
	radixsort(words, len);
	printVector(words);

	words = {};
	len = 0;

	printVector(words);
	radixsort(words, len);
	printVector(words);

	return 0;
}


void printVector(const vector<string> & vec) 
{
	for (const auto& str: vec) {
		cout << str << endl;
	}
	cout << endl;
}