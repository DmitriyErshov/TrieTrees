#include "TrieTree.h"

int main() {
	TrieTree trieTree;
	trieTree.add("code");
	trieTree.add("cook");
	trieTree.add("five");
	trieTree.add("file");
	trieTree.add("fat");

	//Node* search = trieTree.searchLetter('o');
	//trieTree.add("to");
	//trieTree.add("tea");
	//trieTree.add("ted");
	//trieTree.add("ten");
	//trieTree.add("it");
	//trieTree.add("in");
	//trieTree.add("int");
	//trieTree.add("into");
	trieTree.printGraphic();
	
	trieTree.searchLetter('f');

	cout << "____________________________________________________________" << endl;
	trieTree.printGraphic();
	

	return 0;
}