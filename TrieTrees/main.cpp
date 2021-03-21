#include "TrieTree.h"

int main() {
	TrieTree trieTree;
	
	string data = "THIS IS A SAMPLE STRING.";
	// convert string to back to lower case
	for_each(data.begin(), data.end(), [](char& c) {
		c = ::tolower(c);
	});

	string text;
	getline(cin, text);

	string word;
	std::istringstream iss(text, std::istringstream::in);
	while (iss >> word) {
		int ch = word[word.length()];
		if (ch == '.' || ch == ',' || ch == ':' || ch == '?' || ch == '!')
			word = word.substr(0, word.length() - 1);

		for_each(word.begin(), word.end(), [](char& c) {
			c = ::tolower(c);
		});

		trieTree.add(word);
	}


	trieTree.printGraphic();

	//печать содержимого дерева с подсчетом входных значений 
	trieTree.print();

	

	return 0;
}

/*TrieTree trieTree;
	trieTree.add("code");
	trieTree.add("cook");
	trieTree.add("five");
	trieTree.add("file");
	trieTree.add("fat");
	trieTree.add("file");
	trieTree.add("file");
	trieTree.add("file");
	trieTree.add("cook");*/

	//Node* search = trieTree.searchLetter('o');
	/*trieTree.add("to");
	trieTree.add("tea");
	trieTree.add("ted");
	trieTree.add("ten");
	trieTree.add("it");
	trieTree.add("in");
	trieTree.add("int");
	trieTree.add("into");*/
	/*trieTree.printGraphic();*/