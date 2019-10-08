#pragma once
#include <vector>
#include "Pet.h"
#include "ScreenWork.h"
#include "Menu.h"


class Game {
	int(*game)();
	std::string Name;

public:
	Game(std::string Name, int(*game)()) {
		this->Name = Name;
		this->game = game;
	}

	//принимает питомца
	void Play(Pet* pet) {
		//проверяет может ли питомец выполнить это действие
		if (!pet->getPref()->correct(this))
		{
			Console::WriteLine("I woudn`t play this!", { 5,5 }, RED);
			_getch();
			pet->incEnjoy(-5);
		}
		pet ->incEnjoy(game());
	};

	std::string* getName() { return &Name; }
};


class GameLand {
	Menu *chooseGameMenu = new Menu;
	std::vector<Game*> games;
public:
	//деструктор
	~GameLand()
	{
		for (auto s : games)
		{//удаление всех элементов вектора игр, очистка памяти
			delete s;
		}
	}

	//конструктор по умолчанию добавляет игры в вектор и сколько они возвращают
	GameLand()
	{
		chooseGameMenu->setNewMenu({ "Tetris" }, { 4,4 });//меню игр
		games.push_back(new Game(
			"Tetris",
			[]()->int {
				return rand() % 20;
			}
		));
	}

	//возващает указатель на выбранную пользователем игру
	Game* ChooseGame() {
		return games[chooseGameMenu->open()];
	}

};

//
//class SeaWar : public Game{
//public:
//
//	SeaWar()
//	{
//		myT.push_back(Game::CatGame);
//
//	}
//
//	int Play(Pet * pet) override{
//	
//	
//	}
//}
//

//class SeaWar : public Game {
//
//
//public:
//	int score() {
//		return 10;
//	}
//};
//
//class Maze : public Game {
//
//public:
//
//
//};
//
