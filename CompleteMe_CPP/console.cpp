#include "console.h"

Console::Console(Tree* tree)
{
	this->tree = tree;
	this->session = true;
}

void Console::run()
{
	string raw;

	while (session)
	{
		raw = "";
		std::cout << std::endl;
		std::cout << "CONSOLE: ";
		getline(std::cin, raw);
		Command* cmd = new Command(raw);
		serve(cmd);
		free(cmd);
	}

	std::cout << "Session ending..." << std::endl;
}

void Console::serve(Command* cmd)
{
	if (cmd->action == "find") consoleFind(cmd->target);
	else if (cmd->action == "help") consoleHelp();
	else if (cmd->action == "exit") session = false;
	else std::cout << "Invalid command: \"" << cmd->action << "\"" << std::endl;
}

void Console::consoleHelp()
{
	std::cout << "Commands: " << std::endl;
	std::cout << "find <STRING>: Finds a list of words beginning with <STRING>" << std::endl;
	std::cout << "help: displays info" << std::endl;
	std::cout << "exit: Exits the session" << std::endl;
}

void Console::consoleFind(string target)
{
	vector<string> result = tree->find(target);
	for (size_t i = 0; i < result.size(); i++)
		std::cout << result[i] << std::endl;
}