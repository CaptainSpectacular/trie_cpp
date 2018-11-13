#include "dictionary.h"
#include <fstream>

Dictionary::Dictionary(string file_name)
{
	this->file_name = file_name;
}

void Dictionary::populate()
{
	std::ifstream file(file_name);
	std::string line;
	while (std::getline(file, line))
		this->words.push_back(line);
}