#include <iostream>
#include <string>
#include "dictionary.h"
#include "tree.h"
#include "console.h"

int main()
{
	std::cout << "Initializing..." << std::endl;
	Dictionary* dic = new Dictionary("words.txt");
	dic->populate(); //Load file words into memory
	Tree* tree = new Tree(dic);

	tree->load(); // Create nodes
	std::cout << "Done!" << std::endl;
	std::cout << "Type \"help\" for list of commands." << std::endl;
	free(dic);

	Console* console = new Console(tree);
	console->run();
}