#pragma once
#include "utills.h"
#include "NodeList.h"
#include "Node.h"

class TrieTree
{
private:
	Node* root;
	NodeList list;
	int height = 0;
public:
	TrieTree() {
		root = new Node();
	}
	void add(string key);
	void print();
	void printGraphic();
	Node* searchLetter(char c);
	void deleteTree();
private:
	void deleteNode(Node* node);
	void searchLetterRec(char c, Node* node, Node* lastForkNode, int lastForkNodeChild);
	void printGraphic(Node* node, int h, char c);
	void addRec(string key, int index, Node* tempNode);
	void recPreOrderWithPrint(Node* node, char c);

};

