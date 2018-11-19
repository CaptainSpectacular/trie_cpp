#pragma once
#include <string>

using std::string;

class Command
{
public:
	string raw;
	string action;
	string target;

	Command(string x);
};