#pragma once

const int alphabetLettersNum = 26; //размер алфавита

struct Node {
	char s = ' ';
	bool isEnd = false; //флаг указывающий на конец слова
	Node* childs[alphabetLettersNum];

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


