#include "NodeList.h"


void NodeList::add(Node* addNode, int idx)
{
	aray[size].node = addNode;
	aray[size].index = idx;
}

pair NodeList::deleteElement()
{
	size--;
	return aray[size + 1];
}
