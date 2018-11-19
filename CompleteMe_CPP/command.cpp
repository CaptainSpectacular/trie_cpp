#include "command.h"
#include <iterator>
#include <sstream>
#include <vector>


using std::vector;

Command::Command(string raw)
{
	this->raw = raw;

	vector<string> split;
	std::istringstream stm(raw);
	std::string token;
	while (stm >> token) split.push_back(token);

	this->action = split.front();
	this->target = split.back();
}

