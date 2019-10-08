#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include "Authorization.h"
#include "GatKey.h"


//класс, выводящий текст на экран, и наследники которого хранят информацию о выводимых текстовых рисунках
class Console {

public:
	static void WriteLine(std::string t, COORD pos, Color textC = WHITE, Color backC = BLACK) {

		SetCursor(pos.X, pos.Y);
		SetColor(textC, backC);
		std::cout << t;
		SetColor(WHITE, BLACK);
	}
	static void WriteLine(std::string t, int X = 20, int Y = 20, Color textC = WHITE, Color backC = BLACK) {
		SetCursor(X, Y);
		SetColor(textC, backC);
		std::cout << t;
		SetColor(WHITE, BLACK);
	}

	static std::string getLine(COORD pos = { 3,3 }) {
		std::string data;
		SetCursor(pos.X, pos.Y);
		std::cin >> data;
		return data;
	}
	static void Registartion(Authorization auth) {
		WriteLine("enter login\n", { 9,9 });
		std::string tempLogin, tempPass;
		std::cin >> tempLogin;
		WriteLine("enter password\n", { 11,11 });
		std::cin >> tempPass;
		system("cls");
		if (auth.addNew("login", "password"))
			WriteLine("Registred ", { 10,10 }, BLACK, WHITE);
		else if (auth.addNew("login", "password"))
			WriteLine("data problems");

	}
	static void Authorization() {
	}


	class CatPics{

	public:
		static void showPet(COORD pos) {
			WriteLine("there\nwould\nbe\na cat", pos);
		}
	};

	class DogPics{

	public:
		static void showPet(COORD pos) {
			WriteLine("there\nwould\nbe\na DogPics", pos);
		}
	};

	class FishPics{


	public:
		static void showPet(COORD pos) {
			WriteLine("there\nwould\nbe\na FishPics", pos);
		}
	};
};

