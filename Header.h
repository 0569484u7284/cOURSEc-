#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include "BetterVecor.h"
#include "Game.h"

class Preferences {
public:
	//еда и игры которая подходят тамагочику
	BetterVector<std::string> goodStuff;
	//тамагочик никогда не сделает/сьест/поиграет
	BetterVector<std::string> neverDo;
};


class Pet {
	int timer = 0;
	int changeLevelsTime = 10000;

protected:
	int health = 100;
	int saturation = 100;
	int enjoy = 100;
	Preferences pref;
public:
	//функция кушат и играт принимает в себя указатель на функцию и тип животного
	//feed принимает в себя функцию для увеличения насыщения и радости
	//virtual void feed(Food *f) = 0;
	void play(Game game) {
		enjoy += game.play(*this);
	};

	void setPreferences(Preferences* pref) {
		this->pref = pref;
	}
	BetterVector<std::string>  getPreferences() {
		return this->pref.goodFood;
	};
	//функция уменьшающая радость и здоровье раз в опр время
	void time() {
		while (true)
		{
			clock_t t1 = clock();
			if (double(t1) / CLOCKS_PER_SEC >= 1) {
				enjoy--;
				saturation--;
				if (saturation < 20 || enjoy < 20)
					health -= 5;
			}
		}
	}
};
