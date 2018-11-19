#pragma once
#include <string>
#include <iostream>
#include "command.h"
#include "tree.h"

using std::string;

class Console
{
	Tree* tree;
	bool session;
public:
	Console(Tree* tree);

	void run();
	void serve(Command* command);
	void consoleHelp();
	void consoleFind(string target);
};