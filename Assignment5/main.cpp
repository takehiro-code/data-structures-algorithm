
#include "HashTable.h"
#include "spellcheck.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;

void basicTest();
void copyTest();
void spellcheckBasicTest();
void spellcheckExtensiveTest();
void spellcheckAuto(string relativeFilePath, string checkWord);

void printVector(const vector<string> & vec, string vecName);


// ----------------------------------------------------------------------------------------
//											MAIN
// ----------------------------------------------------------------------------------------


int main()
{
	cout << "Testing Assignment 5 ..." << endl;

	basicTest();
	copyTest();
	spellcheckBasicTest();
	spellcheckExtensiveTest();
	//spellcheckAuto("../../../words_alpha.txt", "fire"); // large data

	//string word = "rateat";
	//for (int i = 1; i < word.size(); i++) {
	//	string testWord = word;
	//	//testWord.erase(testWord.begin() + i);
	//	testWord.insert(testWord.begin() + i, ' ');
	//	cout << testWord.substr(0, i) << " " <<  testWord.substr(i+1, testWord.size() - i - 1) <<endl;
	//}

	//int count = 0;
	//for (int i = 0; i < word.size() + 1; i++) {
	//	for (int j = 0; j < 26; j++) {
	//		string testWord = word;
	//		char alphabetLower = 'a' + j;
	//		testWord.insert(testWord.begin() + i, alphabetLower);
	//		cout << testWord << endl;
	//		count++;
	//	}
	//}
	//cout << count << endl;

	//string word = "hello";
	//for (int i = 0; i < word.size(); i++) {
	//	string testWord = word;
	//	for (int j = 0; j < 26; j++) {
	//		char alphabetLower = 'a' + j;
	//		testWord[i] = alphabetLower;
	//	}
	//}


	//vector<string> vec = { "hello", "wow", "omg" };
	//bool flag = std::find(vec.begin(), vec.end(), "wow") != vec.end();

	////cout << flag << endl;
	//std::sort(vec.begin(), vec.end());

	//for (int i = 0; i < vec.size(); i++) {
	//	cout << vec[i] << endl;
	//}

	return 0;
}

// ----------------------------------------------------------------------------------------
//                                       Test Functions
// ----------------------------------------------------------------------------------------


void basicTest()
{
	cout << " -------------------------- Basic Test ---------------------------------------------" << endl;

	HashTable hs1(1);
	hs1.insert("hello");
	hs1.insert("demon");
	hs1.insert("cat");
	hs1.insert("scary");
	cout << "hs1 = " << endl;
	hs1.printHashTable();

	cout << "Finding dark: " << hs1.find("dark") << endl;
	cout << "Finding hello: " << hs1.find("hello") << endl;
	cout << "Finding cat: " << hs1.find("cat") << endl;
	cout << "Finding mlrs: " << hs1.find("mlrs") << endl;

	HashTable hs2(0);
	hs2.insert("hello");
	hs2.insert("demon");
	hs2.insert("cat");
	hs2.insert("scary");
	cout << "hs2 = " << endl;
	hs2.printHashTable();


	// long string
	HashTable hs3(1);
	hs3.insert("hello");
	hs3.insert(
		"demondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondem\
ondemondemondemondemondemondemondemondemondemondemondemondemondemondemodemondemondemondemondemondemo\
ndemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemonde\
mondemondemondemondemoncatemondemondemondemondemondemondemondemondemondemondemondemondemondemondemonde\
mondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemond\
emondemondemondemondemondemondemondemondemoncatondemondemondemondemondemondemondemondemondemondemondemondemondemon\
demondemondemondemondemondemondemondemondemondemondemondemondemondemondemondcatmondemondemondemondemondemondemondemond\
emondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemonde\
mondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemon\
demondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemondemonde\
catcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatc\
atcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatca\
tcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatca\
ttcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcatt\
catcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatc\
atcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatc\
atcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcat\
catcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcat\
catcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatca\
tcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcat\
catcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatc\
atcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcat\
catcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcat\
catcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcatt\
catcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatc\
atcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcat\
tcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatc\
atcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcat\
tcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcat\
catcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcat\
tcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatc\
atcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatcatcatcattcatcatcatcatcatcatcatcatc\
atcatcattcatcatcatcatcatcatcatcatcatcatcat");
	hs3.insert("cat");\
	hs3.insert("scary");
	cout << "hs3 = " << endl;
	hs3.printHashTable();
}


void copyTest()
{
	cout << " -------------------------- Copy Test ---------------------------------------------" << endl;

	HashTable hs1;
	hs1.insert("hello");
	hs1.insert("demon");
	hs1.insert("cat");
	hs1.insert("scary");
	cout << "hs1 = " << endl;
	hs1.printHashTable();


	HashTable hs2 = hs1;
	cout << "hs2 = " << endl;
	hs2.printHashTable();

	HashTable hs3(hs1);
	cout << "hs3 = " << endl;
	hs3.printHashTable();

	HashTable hs4, hs5, hs6(1);
	hs4 = hs5 = hs6 = hs1;

	cout << "hs4 = " << endl;
	hs4.printHashTable();
	cout << "hs5 = " << endl;
	hs5.printHashTable();
	cout << "hs6 = " << endl;
	hs6.printHashTable();

	HashTable hs7;
	hs7.insert("night");
	hs7.insert("sky");
	hs7 = hs6;
	cout << "hs7 = " << endl;
	hs6.printHashTable();

	HashTable hs8;
	hs8 = hs8 = hs4;
	cout << "hs8 = " << endl;
	hs8.printHashTable();
}


void spellcheckBasicTest()
{
	cout << " -------------------------- Spell Check Basic Test ---------------------------------------------" << endl;

	HashTable dict;

	// read the content from the file and insert them into the hash table object
	//ifstream file("../../../wordlist1000.txt");
	ifstream file("../../../test.txt");
	string word;
	if (file.is_open()) {
		while (file >> word)
		{
			dict.insert(word); // no duplicates can be inserted
		}
	}
	else {
		cout << "File cannot be opened ... " << endl;
	}
	file.close();

	cout << "dict = " << endl;
	dict.printHashTable();

	vector<string> vec0 = extraLetter(dict, "chat");
	printVector(vec0, "vec0");

	vector<string> vec1 = extraLetter(dict, "chate");
	printVector(vec1, "vec1");

	vector<string> vec2 = transposition(dict, "atr");
	printVector(vec2, "vec2");

	vector<string> vec3 = missingSpace(dict, "rateat");
	printVector(vec3, "vec3");

	vector<string> vec4 = missingLetter(dict, "poe");
	printVector(vec4, "vec4");

	vector<string> vec5 = incorrectLetter(dict, "thed");
	printVector(vec5, "vec5");
}


void spellcheckExtensiveTest()
{
	cout << " -------------------------- Spell Check Extensive Test ---------------------------------------------" << endl;

	HashTable dict;

	// read the content from the file and insert them into the hash table object
	//ifstream file("../../../wordlist1000.txt");
	ifstream file("../../../wordlist1000.txt");
	string word;
	if (file.is_open()) {
		while (file >> word)
		{
			dict.insert(word); // no duplicates can be inserted
		}
	}
	else {
		cout << "File cannot be opened ... " << endl;
	}
	file.close();

	cout << "dict = " << endl;
	dict.printHashTable();

	vector<string> vec0 = extraLetter(dict, "chat");
	printVector(vec0, "vec0");

	vector<string> vec1 = extraLetter(dict, "chate");
	printVector(vec1, "vec1");

	vector<string> vec2 = transposition(dict, "atr");
	printVector(vec2, "vec2");

	vector<string> vec3 = missingSpace(dict, "rateat");
	printVector(vec3, "vec3");

	vector<string> vec4 = missingLetter(dict, "poe");
	printVector(vec4, "vec4");

	vector<string> vec5 = incorrectLetter(dict, "thed");
	printVector(vec5, "vec5");

	vector<string> vec6 = missingSpace(dict, "reda");
	printVector(vec6, "vec6");

	vector<string> vec7 = missingSpace(dict, "red");
	printVector(vec7, "vec7");
}


void spellcheckAuto(string relativeFilePath, string checkWord)
{
	cout << " -------------------------- Spell Check Basic Test ---------------------------------------------" << endl;

	HashTable dict;

	// read the content from the file and insert them into the hash table object
	//ifstream file("../../../wordlist1000.txt");
	ifstream file(relativeFilePath);
	string word;
	if (file.is_open()) {
		while (file >> word)
		{
			dict.insert(word); // no duplicates can be inserted
		}
	}
	else {
		cout << "File cannot be opened ... " << endl;
	}
	file.close();

	cout << "dict = " << endl;
	dict.printHashTable();

	vector<string> vec0 = extraLetter(dict, checkWord);
	printVector(vec0, "vec0");

	vector<string> vec1 = extraLetter(dict, checkWord);
	printVector(vec1, "vec1");

	vector<string> vec2 = transposition(dict, checkWord);
	printVector(vec2, "vec2");

	vector<string> vec3 = missingSpace(dict, checkWord);
	printVector(vec3, "vec3");

	vector<string> vec4 = missingLetter(dict, checkWord);
	printVector(vec4, "vec4");

	vector<string> vec5 = incorrectLetter(dict, checkWord);
	printVector(vec5, "vec5");
}




// ----------------------------------------------------------------------------------------
// For Debugging
// ----------------------------------------------------------------------------------------

void printVector(const vector<string>& vec, string vecName)
{
	cout << vecName << " = " << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
	cout << endl;
}


void HashTable::printHashTable() const
{
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] != "")
		//if (true)
		{
			cout << i << ": " << arr[i] << endl;
		}
	}
	cout << endl;

	cout << "arrSize = " << maxSize() << endl;
	cout << "# of items in the hash table = " << size() << endl;
	cout << "load factor = " << loadFactor() << endl;
}