#include "frontend.h"

//возвращает текущие координаты курсора 
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
}

//установка курсора по горизонтантали
void setCoursor(int x, int y)
{
	COORD position;										// Объявление необходимой структуры
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода
	position = GetConsoleCursorPosition(hConsole);

	if (x < 0)
		x = 0;

	if (y < 0)
		y = 0;

	position.X = position.X + x;									// Установка координаты X
	position.Y = position.Y + y;

	SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}