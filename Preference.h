#pragma once
#include <vector>
#include <string>
#include "Game.h"
#include "PetBaseClass.h"
#include "Pet.h"

class Preferences {

	template<typename T>
	bool InVector(T data, std::vector<T> vect) {
		for (auto a : vect)
		{
			if (a == data)
				return true;
		}
		return false;
	}


	std::vector<std::string> goodStuff;
	std::vector<std::string> neverDo;

public:
	Preferences()
	{

	}
	Preferences(std::vector<std::string> good, std::vector<std::string> never)
	{
		goodStuff = good;
		neverDo = never;
	}
	std::vector<std::string> getGood() {
		return goodStuff;
	}
	std::vector<std::string> getNever() {
		return neverDo;
	}
	void addGood(std::string good) {
		goodStuff.push_back(good);
	}
	void addNever(std::string never) {
		neverDo.push_back(never);
	}

	//проверяет нравится ли питомцу эта игра 
	bool correct(Game* g) {
		return InVector<std::string>(*g->getName(), goodStuff);
	}
};
