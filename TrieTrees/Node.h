#pragma once

const int alphabetLettersNum = 26; //������ ��������

struct Node {
	//char s = ' ';
	bool isEnd = false; //���� ����������� �� ����� �����
	Node* childs[alphabetLettersNum];
};
