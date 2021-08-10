#pragma once

#include "HashTable.h"
#include <vector>
#include <algorithm>

using std::vector;

// NOTE:
// Each function is in the form of:
// vector<string> functionName(const HashTable & dict, string word)

// PRE and POST condtions for all the funtions as follows.
// PRE: No duplicate words in dict
// POST: vector<string> is in alphabetical (lexicographical) order and no duplicate strings.


// if word not found in dict, delete each character in word to see if the similar word is in dict
vector<string> extraLetter(const HashTable& dict, string word)
{
	vector<string> result;
	if (dict.find(word)) {
		result.push_back(word);
	}
	else {
		for (int i = 0; i < word.size(); i++) {
			string testWord = word;
			testWord.erase(testWord.begin() + i); // erase each character from the string word

			bool foundInDict = dict.find(testWord);
			bool foundInResult = std::find(result.begin(), result.end(), testWord) != result.end();

			if (foundInDict && !foundInResult) {
				result.push_back(testWord);
			}
		}
		// sort the result vector using STL sort from <algorithm> library
		std::sort(result.begin(), result.end());
	}
	return result;
}


// if word not found in dict, swap two adjacent letters in word to see if the similar word is in dict
vector<string> transposition(const HashTable& dict, string word)
{
	vector<string> result;
	if (dict.find(word)) {
		result.push_back(word);
	}
	else {
		for (int i = 0; i < word.size() - 1; i++) {
			string testWord = word;
			
			// swap the two adjacent characters at i and i + 1
			char temp = testWord[i];
			testWord[i] = testWord[i + 1];
			testWord[i + 1] = temp;

			bool foundInDict = dict.find(testWord);
			bool foundInResult = std::find(result.begin(), result.end(), testWord) != result.end();

			if (foundInDict && !foundInResult) {
				result.push_back(testWord);
			}
		}
		// sort the result vector using STL sort from <algorithm> library
		std::sort(result.begin(), result.end());
	}
	return result;
}


// if word not found in dict, insert a space at any position in word to see if the similar word in two substrings are in dict
// Returned vector contains strings that consist of 2 substrings separated by a single space (for similar words case)
vector<string> missingSpace(const HashTable& dict, string word)
{
	vector<string> result;
	if (dict.find(word)) {
		result.push_back(word);
	}
	else {
		// inserting a single space before the i-th character (left side of i-th character)
		// Hence, starts from inserting a space before the i=1 character and ends with inserting a space at before the last character
		for (int i = 1; i < word.size(); i++) {
			string testWord = word;
			testWord.insert(testWord.begin() + i, ' '); // insert a space at each position
			string substr1 = testWord.substr(0, i); // substring before the space
			string substr2 = testWord.substr(i + 1, testWord.size() - i - 1); // substring after the space

			bool bothFoundInDict = dict.find(substr1) && dict.find(substr2);
			bool foundInResult = std::find(result.begin(), result.end(), testWord) != result.end();

			if (bothFoundInDict && !foundInResult) {
				result.push_back(testWord);
			}
		}
		// sort the result vector using STL sort from <algorithm> library
		std::sort(result.begin(), result.end());
	}
	return result;
}


// If word not found in dict, insert a single alphabet at any position in word to see if the similar word is in dict
vector<string> missingLetter(const HashTable& dict, string word)
{
	vector<string> result;
	if (dict.find(word)) {
		result.push_back(word);
	}
	else {
		// inserting a single lower case alphabet before i = 0 character up to after the last character ( i = word.size() )
		for (int i = 0; i < word.size() + 1; i++) {
			for (int j = 0; j < 26; j++) {
				string testWord = word;
				char alphabetLower = 'a' + j;
				testWord.insert(testWord.begin() + i, alphabetLower); // insert a space at each position

				bool FoundInDict = dict.find(testWord);
				bool foundInResult = std::find(result.begin(), result.end(), testWord) != result.end();

				if (FoundInDict && !foundInResult) {
					result.push_back(testWord);
				}
			}
		}
		// sort the result vector using STL sort from <algorithm> library
		std::sort(result.begin(), result.end());
	}
	return result;
}


// If word not found in dict, replace a character with any single alphabet at any i-th position in word to see if the similar word is in dict
vector<string> incorrectLetter(const HashTable& dict, string word)
{
	vector<string> result;
	if (dict.find(word)) {
		result.push_back(word);
	}
	else {
		// replace a character at i = 0 to  i = word.size() - 1
		for (int i = 0; i < word.size() + 1; i++) {
			for (int j = 0; j < 26; j++) {
				string testWord = word;
				char alphabetLower = 'a' + j;
				testWord[i] = alphabetLower;

				bool FoundInDict = dict.find(testWord);
				bool foundInResult = std::find(result.begin(), result.end(), testWord) != result.end();

				if (FoundInDict && !foundInResult) {
					result.push_back(testWord);
				}
			}
		}
		// sort the result vector using STL sort from <algorithm> library
		std::sort(result.begin(), result.end());
	}
	return result;
}