#pragma once

const int alphabetLettersNum = 26; //размер алфавита

struct Node {
	//char s = ' ';
	int counter = 0; //счетчик слов
	bool isEnd = false; //флаг указывающий на конец слова
	Node* childs[alphabetLettersNum];

	//есть ли определенное число потомков
	bool hasChilds(int coundChilds) {
		int childsCount = 0;
		for (int i = 0; i < alphabetLettersNum; i++)
		{
			if (childs[i] != nullptr) {
				childsCount++;
				if (childsCount == coundChilds) {
					return true;
				}
			}
		}
		return false;
	}
};


