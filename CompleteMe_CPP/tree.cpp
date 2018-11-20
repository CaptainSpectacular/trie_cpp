#include "tree.h"

Tree::Tree(Dictionary* dic)
{
	this->dictionary = dic;
	this->root = new Node(' ');
}

void Tree::load()
{
	for (int i = 0; i < dictionary->words.size(); i++)
		insert(dictionary->words[i]);
}

void Tree::insert(string word)
{
	Node* ptr = root;
	for (int i = 0; i < word.length(); i++)
	{
		Node* child = ptr->has_child(word[i]);
		if (child)
			ptr = child;

		else
		{
			if (word.length() - i == 1)
				ptr->insert_char(word[i], true);
			
			else
			{
				ptr->insert_char(word[i]);
				ptr = ptr->has_child(word[i]);
			}
		}

		
		if (ptr == nullptr)
		{
			std::cout << "An error occured while inserting word '" << word << "'." << std::endl;
			return;
		}
	}
}

Node* Tree::traverse(string substring)
{
	Node* ptr = root;
	for (int i = 0; i < substring.length(); i++)
	{
		Node* child = ptr->has_child(substring[i]);
		if (child)
			ptr = child;

		else
			return nullptr;
	}

	return ptr;
}

vector<string> Tree::find(string word, vector<string> suggestions)
{
	Node* ptr = traverse(word);
	if (ptr == nullptr)
	{
		std::cout << "No words found." << std::endl;
		return suggestions;
	}

	if (ptr->word)
		suggestions.push_back(word);
		
	for (Node* child : ptr->children)
		suggestions = find(word + child->data, suggestions);

	return suggestions;
}