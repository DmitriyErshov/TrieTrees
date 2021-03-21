#include "TrieTree.h"

void TrieTree::add(string key)
{
	addRec(key, 0, root);
	
	//обновление высоты дерева
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
	SetColor(14, 0);
	char c = ' ';
	printGraphic(root, height + 1);
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

				if (node->childs[i]->isEnd) {
					SetColor(9, 0);
				}
				
				cout << c << endl;
				
					
				SetColor(14, 0);
				
			}
		}
	}
}



Node* TrieTree::searchLetter(char c)
{
	searchLetterRec(c, root, nullptr, -1, nullptr, -1, ' ');
	/*for (int i = 0; i < list.getSize(); i++)
	{
		pair tempForDeleting = list.deleteElement();
		Node* temp = tempForDeleting.node;
		temp->childs[tempForDeleting.index] = nullptr;
	}*/
	return nullptr;
}

void TrieTree::deleteTree()
{
	deleteNode(root);
}

void TrieTree::deleteNode(Node* node)
{
	if (node != nullptr) {
		
		for (int i = 0; i < alphabetLettersNum; i++)
		{
			if (node->childs[i] != nullptr) {
				deleteNode(node->childs[i]);
			}
		}
		delete node;
	}
}

void TrieTree::searchLetterRec(char searchedChar, Node* node, Node* lastForkNode, int lastForkNodeChild,
	Node* parentNode, int parentNodeChild, char childChar)
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


		if (childChar == searchedChar) {
			//мы нашли нужную букву и удаляем всё что ниже 
			deleteNode(node);
			parentNode->childs[parentNodeChild] = nullptr;
		}
		else {
			bool wasFounded = false;
			for (int i = 0; i < alphabetLettersNum; i++)
			{
				if (node->childs[i] != nullptr) {
					wasFounded = true;
					if (isFork) {
						lastForkNode = node;
						lastForkNodeChild = i;
					}
					childChar = 'a' + i;
					searchLetterRec(searchedChar, node->childs[i], lastForkNode, lastForkNodeChild, node, i, childChar);

					//если у узла не будет потомков, но при этом isEnd == false, удаляем всё, что ниже fork узла
					if (!node->hasChilds(1) && node->isEnd == false) {
						deleteNode(lastForkNode->childs[lastForkNodeChild]);
						parentNode->childs[parentNodeChild] = nullptr;
						return;
					}
				}
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
		tempNode->counter++;
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

//void TrieTree::nicePrintGraphic()
//{
//	//очередь узлов
//	Queue treeNodes;
//
//	//узел - разделитель потомков
//	Node* nodeDivider = new Node();
//	nodeDivider->s = '*';
//
//	//количество групп потомков разных узлов на предыдущем уровне и на нынешнем
//	int nodesOnLevel1 = 0, nodesOnLevel2 = 0;
//
//
//	//инициализация 
//	for (int i = 0; i < alphabetLettersNum; i++)
//	{
//		if (root->childs[i] != nullptr) {
//			treeNodes.push(root->childs[i]);
//			nodesOnLevel1++;
//			treeNodes.push(nodeDivider);
//		}
//	}
//	treeNodes.push(nullptr);
//
//	Queue nodesForPrint;
//
//	bool flag = false;
//
//	while (!treeNodes.isEmpty()) {
//		//достаём из очереди узел
//		Node* tempNode = treeNodes.front();
//
//		//int nodesOnLevel = treeNodes.size() - 1;
//
//		if (tempNode == nullptr) {
//			cout << endl;
//			if (treeNodes.size() > 1)
//				treeNodes.push(nullptr);
//			nodesOnLevel1 = nodesOnLevel2;
//			nodesOnLevel2 = 0;
//		}
//		else if (tempNode == nodeDivider) {
//			int n = nodesForPrint.size();
//			int k = 80 / nodesOnLevel1;
//
//			while (!nodesForPrint.isEmpty()) {
//				Node* tempNode = nodesForPrint.front();
//				nodesForPrint.pop();
//
//				for (int i = 1; i <= int(k / (n + 1)); i++)
//					cout << ' ';
//
//				if (nodesOnLevel1 == 3) {
//					for (int i = 1; i <= 4; i++)
//						cout << ' ';
//				}
//
//				cout << tempNode->s;
//			}
//			for (int i = 1; i <= int(k / (n + 1)); i++)
//				cout << ' ';
//
//			//cout << '*';
//		}
//		else {
//
//
//			/*for (int i = 1; i <= 50 / nodesOnLevel; i++)
//				cout << ' ';*/
//
//				//cout << tempNode->s;
//			nodesForPrint.push(tempNode);
//
//			for (int i = 0; i < alphabetLettersNum; i++)
//			{
//				if (tempNode->childs[i] != nullptr) {
//					treeNodes.push(tempNode->childs[i]);
//				}
//			}
//			nodesOnLevel2++;
//			treeNodes.push(nodeDivider);
//
//		}
//
//		treeNodes.pop();
//		//добавляем в очередь всех его потомков
//	}
//}