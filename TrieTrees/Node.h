#pragma once

const int alphabetLettersNum = 26; //������ ��������

struct Node {
	char s = ' ';
	bool isEnd = false; //���� ����������� �� ����� �����
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


