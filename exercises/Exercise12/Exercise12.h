#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

// PRE: strings are unsorted in a vector, string is all lowercase, all the strings are the same length
// PARAM
//		vec: a vector of strings
//		len: length of the characters in string
// POST: strings are sorted in a vector
void radixsort(vector<string>& vec, int len)
{
	// array of vector of string
	const int bucketSize = 26;
	vector<vector<string>> buckets(bucketSize); // 26 buckets for character from 'a' to 'z'

	// sort according to each character, starting from right character and ends on left character
	for (int charPos = len - 1; charPos >= 0; charPos--)
	{
		// if charPos = len - 1 case (right most character), read from vector directly and put string into each bucket
		if (charPos == len - 1) {
			for (const string& str : vec)
			{
				char ch = str[charPos];
				int chint = (int)ch - 'a'; // 'a' is 97, 'z' is 123
				buckets[chint].push_back(str);
			}
		}
		else {
			vector<vector<string>> tempBuckets(bucketSize);

			// traversing buckets
			for (int chint = 0; chint < bucketSize; chint++)
			{
				// i indicates the element position in each bucket
				for (int i = 0; i < buckets[chint].size(); i++)
				{
					string str = buckets[chint][i];
					char ch = str[charPos];
					int chint = (int)ch - 'a'; // 'a' is 97, 'z' is 123
					tempBuckets[chint].push_back(str);
				}
			}
			buckets = tempBuckets;
		}
	}


	vec.clear(); // clear the existing vector
	// traversing buckets and push back into the vector
	for (int chint = 0; chint < bucketSize; chint++)
	{
		// i indicates the element position in each bucket
		for (int i = 0; i < buckets[chint].size(); i++)
		{
			string str = buckets[chint][i];
			vec.push_back(str);
		}
	}
}