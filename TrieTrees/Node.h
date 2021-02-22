#pragma once

const int alphabetLettersNum = 26; //размер алфавита

struct Node {
	//char s = ' ';
	bool isEnd = false; //флаг указывающий на конец слова
	Node* childs[alphabetLettersNum];
};
