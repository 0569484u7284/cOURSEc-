#pragma once
#include <conio.h>

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);


//struct COORD {
//	int X;
//	int y;
//};

void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}
enum Color { BLACK, START_COLOR = BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, GREY_LIGHT, GRAY_DARK, BLUE_LIGHT, GREEN_LIGHT, CYAN_LIGHT, RED_LIGHT, MAGENTA_LIGHT, YELLOW, WHITE, END_COLOR };

enum  ASCII_Table {
	LeftTopDoubleFrame = 201, RightTopDoubleFrame = 187, LeftDownDoubleFrame = 200, RightDownDoubleFrame = 188, StraitUpDown = 186,
};
bool SetCursorPosition(COORD coord)
{
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
bool SetCursorPosition(short x, short y)
{
	COORD coord = { x, y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetColor(Color text, Color background) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
const enum  standartKeys {
	key_Q = 113, key_W = 119, key_E = 101, key_R = 114, key_T = 116, key_Y = 121, key_U = 117, key_I = 105, key_O = 111, key_P = 112, key_LeftBracket = 91, key_RightBracket = 93,
	key_A = 97, key_S = 115, key_D = 100, key_F = 102, key_G = 103, key_H = 104, key_J = 106, key_K = 107, key_L = 108, key_Semicolon = 59, key_Quotes = 39,
	key_Z = 122, key_X = 120, key_C = 99, key_V = 118, key_B = 98, key_N = 110, key_M = 109, key_triangularArrowLeft = 44, key_triangularArrowRight = 46, key_SLASH = 47,
	key_ENTER = 13, key_SPACE = 32, key_TILDA = 96, key_TAB = 9, key_BACKSPACE = 8, key_BACKSLASH = 92,
	key_ESC = 27
};
//0 to enter Special
const enum specialsKeysPlus0 {
	key_F1 = 59, key_F2, key_F3, key_F4, key_F5, key_F6, key_F7, key_F8, key_F9, key_F10
};
//224 to enter Special
const enum specialKeysPlus224 {
	key_LeftArrow = 75, key_RightArrow = 77, key_UpArrow = 72, key_DownArrow = 80, key_F11 = 133, key_F12 = 134

};
bool wasPressed();
int keyHandler();

//#include "pch.h" 

//const enum  standartKeys {
//	key_Q = 113, key_W = 119, key_E = 101, key_R = 114, key_T = 116, key_Y = 121, key_U = 117, key_I = 105, key_O = 111, key_P = 112, key_LeftBracket = 91, key_RightBracket = 93,
//	key_A = 97, key_S = 115, key_D = 100, key_F = 102, key_G = 103, key_H = 104, key_J = 106, key_K = 107, key_L = 108, key_Semicolon = 59, key_Quotes = 39,
//	key_Z = 122, key_X = 120, key_C = 99, key_V = 118, key_B = 98, key_N = 110, key_M = 109, key_triangularArrowLeft = 44, key_triangularArrowRight = 46, key_SLASH = 47,
//	key_ENTER = 13, key_SPACE = 32, key_TILDA = 96, key_TAB = 9, key_BACKSPACE = 8, key_BACKSLASH = 92
//};
////0 to enter Special
//const enum specialsKeysPlus0 {
//	key_F1 = 59, key_F2, key_F3, key_F4, key_F5, key_F6, key_F7, key_F8, key_F9, key_F10
//};
//const enum specialKeysPlus224 {
//	key_LeftArrow = 75, key_RightArrow = 77, key_UpArrow = 72, key_DownArrow = 80, key_F11 = 133, key_F12 = 134
//
//};

bool wasPressed()
{

	if (_kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 224: {
			//spec 224

			_getch();

			return true;


			//spec 224
		}case 0: {
			//spec 0

			_getch();
			return true;


			//spec 0
		}
		default:
			return true;

		}
	}
	else
	{
		return false;
	}

}
int keyHandler() {
	int key = _getch();
	switch (key)
	{
	case 224: {
		//spec 224

		return _getch();


		//spec 224
	}case 0: {
		//spec 0

		return _getch();


		//spec 0
	}

	default:
		return key;
		break;
	}



}

