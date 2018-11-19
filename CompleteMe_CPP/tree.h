#pragma once
#include "dictionary.h"
#include "node.h"

class Tree
{
	Dictionary* dictionary;
	Node*       root;

public:
	Tree(Dictionary* dic);
	
	void load();
	void insert(string word);
	Node* traverse(string substring);
	vector<string> find(string word, vector<string> suggestions = vector<string>());
};