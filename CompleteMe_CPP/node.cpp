#include "node.h"

Node::Node(char data, bool is_word)
{
	this->data = data;
	this->word = is_word;
}

void Node::insert_char(char letter, bool is_word)
{
	Node* child = new Node(letter, is_word);
	children.push_back(child);
}

Node* Node::has_child(char letter)
{
	for (int i = 0; i < children.size(); i++)
		if (children[i]->data == letter)
			return children[i];

	return nullptr;
}