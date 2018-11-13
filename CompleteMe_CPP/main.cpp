#include <iostream>
#include <string>
#include "dictionary.h"
#include "tree.h"
#include <chrono>

using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using namespace std::literals::chrono_literals;


int main()
{
	Dictionary* dic = new Dictionary("words.txt");
	dic->populate(); //Load file words into memory

	Tree* tree = new Tree(dic);
	tree->load(); // Create nodes

	free(dic);

	time_point<Clock> start = Clock::now();

	vector<string> found = tree->find("com"); // search for words that
											  // begin with 'com'
	int found_size = found.size();

	for (int i = 0; i < found_size; i++) // display found words.
		std::cout << found[i] << std::endl;

	time_point<Clock> end = Clock::now();
	milliseconds diff = duration_cast<milliseconds>(end - start);
	std::cout << "Time taken: " << diff.count() << "ms" << std::endl;
	std::cout << "Words found: " << found_size << std::endl;
	std::cin.get();
}