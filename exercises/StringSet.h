#pragma once // prevents multiple compilation

#include <iostream>

class StringSet
{
public:
	StringSet();
	bool insert(std::string s);
	void remove(std::string s);
	int size();
	int find(std::string s);
};