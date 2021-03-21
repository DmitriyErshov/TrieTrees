#include "frontend.h"

//���������� ������� ���������� ������� 
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
}

//��������� ������� �� ��������������
void setCoursor(int x, int y)
{
	COORD position;										// ���������� ����������� ���������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// ��������� ����������� ���������� ������������ ������
	position = GetConsoleCursorPosition(hConsole);

	if (x < 0)
		x = 0;

	if (y < 0)
		y = 0;

	position.X = position.X + x;									// ��������� ���������� X
	position.Y = position.Y + y;

	SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}