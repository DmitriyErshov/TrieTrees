#pragma once
#include "utills.h"
#include "NodeList.h"
#include "Node.h"
#include "frontend.h"
#include "QueueArray.h"

class TrieTree
{
private:
	Node* root;
	int height = 0;
public:
	TrieTree() {
		root = new Node();
	}
	void add(string key);
	void print();
	void printGraphic();
	//void nicePrintGraphic();
	Node* searchLetter(char c);
	void deleteTree();
private:
	void deleteNode(Node* node);
	void searchLetterRec(char searchedChar, Node* node, Node* lastForkNode, int lastForkNodeChild, Node* parentNode, int parentNodeChild, char childChar);
	void printGraphic(Node* node, int h);
	void addRec(string key, int index, Node* tempNode);
	void recPreOrderWithPrint(Node* node, char c);

};

