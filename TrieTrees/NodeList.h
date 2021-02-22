#pragma once
#include "Node.h"


const int maxSize = 500;


struct pair {
	Node* node = nullptr;
	int index = 0; 
};

class NodeList
{
private:
	pair aray[maxSize];;
	int size = 0;
public:
	void add(Node* addNode, int idx);
	pair deleteElement();
	int getSize() { return size; };
};

