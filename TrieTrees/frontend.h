#pragma once
#include <stdio.h>
#include <Windows.h>

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);

void setCoursor(int x, int y);

void SetColor(int text, int bg);