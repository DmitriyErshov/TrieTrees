#include "TrieTree.h"

void TrieTree::add(string key)
{
	addRec(key, 0, root);

	if (key.length() > height) {
		height = key.length();
	}
}

void TrieTree::print()
{
	char c = ' ';
	recPreOrderWithPrint(root, c);
}

void TrieTree::printGraphic()
{
	char c = ' ';
	printGraphic(root, height + 1);
}

Node* TrieTree::searchLetter(char c)
{
	searchLetterRec(c, root, nullptr, -1);
	for (int i = 0; i < list.getSize(); i++)
	{
		pair tempForDeleting = list.deleteElement();
		Node* temp = tempForDeleting.node;
		temp->childs[tempForDeleting.index] = nullptr;
	}
	return nullptr;
}

void TrieTree::deleteTree()
{
	deleteNode(root);
}

void TrieTree::deleteNode(Node* node)
{
	if (node != nullptr) {
		//проверим что узел являеся развилкой
		for (int i = 0; i < alphabetLettersNum; i++)
		{
			if (node->childs[i] != nullptr) {
				deleteNode(node->childs[i]);
			}
		}
		delete node;
	}
}

void TrieTree::searchLetterRec(char searchedChar, Node* node, Node* lastForkNode, int lastForkNodeChild, char childChar)
{

	if (node != nullptr) {
		//проверим что узел являеся развилкой
		bool isFork = false;
		int childsCount = 0;
		for (int i = 0; i < alphabetLettersNum; i++)
		{
			if (node->childs[i] != nullptr) {
				childsCount++;
				if (childsCount == 2) {
					isFork = true;
					break;
				}
					
			}
		}


		//if (node->s == c) {
		//	//удаляем всё что ниже 
		//	deleteNode(node);
		//	node = nullptr;
		//	//добавляем forkNode в список на расстрел
		//	list.add(lastForkNode, lastForkNodeChild);
		//	return;
		//}
		//else {
		//	bool wasFounded = false;
		//	for (int i = 0; i < alphabetLettersNum; i++)
		//	{
		//		if (node->childs[i] != nullptr) {
		//			wasFounded = true;
		//			if (isFork) {
		//				lastForkNode = node;
		//				lastForkNodeChild = i;
		//			}
		//			return searchLetterRec(c, node->childs[i], lastForkNode, lastForkNodeChild);
		//		}
		//	}

		//}
	}
	
}

void TrieTree::printGraphic(Node* node, int h)
{
	if (node != NULL)
	{
		for (int i = 0; i < alphabetLettersNum; i++)
		{
			if (node->childs[i] != nullptr) {
				char c = 'a' + i;
				printGraphic(node->childs[i], h + 1);

				for (int i = 1; i <= h; i++)
					cout << '\t';

				cout << c << endl;
			}
			
		}
	}
}

void TrieTree::addRec(string key, int index, Node* tempNode)
{
	int insertIndex = key[index] - 'a';

	//проверяем достигнут ли конец ключа
	if (index + 1 == key.length()) {
		tempNode->childs[insertIndex] = new Node();
		//tempNode->childs[insertIndex]->s = key[index];
		tempNode->childs[insertIndex]->isEnd = true;
		return;
	}
	else {
		bool wasFounded = false;
		//ищем букву в 
		/*int i;
		for (i = 0; i < alphabetLettersNum; i++)
		{
			if (tempNode->childs[i] != nullptr && tempNode->childs[i]->s == key[index]) {
				wasFounded = true;
				break;
			}
		}*/
		if (tempNode->childs[insertIndex] != nullptr) {
			addRec(key, index + 1, tempNode->childs[insertIndex]);
		}
		else {
			tempNode->childs[insertIndex] = new Node();
			//tempNode->childs[insertIndex]->s = key[index];
			addRec(key, index + 1, tempNode->childs[insertIndex]);
		}

		//if (!wasFounded) {
		//	tempNode->childs[insertIndex] = new Node();
		//	//tempNode->childs[insertIndex]->s = key[index];
		//	addRec(key, index + 1, tempNode->childs[insertIndex]);
		//}
		//else {
		//	addRec(key, index + 1, tempNode->childs[i]);
		//}
	}
}

void TrieTree::recPreOrderWithPrint(Node* node, char c)
{
	if (node != nullptr) {
		cout << c << " ";
		for (int i = 0; i < alphabetLettersNum; i++)
		{
			if (node->childs[i] != nullptr) {
				c = 'a' + i;
				recPreOrderWithPrint(node->childs[i], c);
			}
		}
	}
}