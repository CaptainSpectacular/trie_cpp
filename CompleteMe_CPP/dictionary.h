#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Dictionary
{
public:
	vector<string> words;
	string file_name;

	Dictionary(string file_name);

	void populate();
};