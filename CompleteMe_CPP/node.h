#pragma once
#include <vector>

using std::vector;

class Node
{
public:
	char data;
	bool word;
	vector<Node*> children;

	Node(char data, bool is_word = false);
	void insert_char(char letter, bool is_word = false);
	Node* has_child(char letter);
};