#pragma once

class Food {

	//базовый класс с едой
public:


};

class FeedPet {
	Menu* chooseMealMenu = new Menu;
	std::vector<Food*> meal;

public:
	~FeedPet()
	{
		for (auto a : meal)
		{// удаление всех элементов вектора очистка памяти
			delete a;
		}
	}

	FeedPet()
	{
	
	}
};


class Water {//вода
public:
	int satur() {
		return 2;
	}
};

class Cheese {//сыр
public:
	int satur() {
		return 10;
	}
};


/*
использовать параметризированный метод фабрику,
который однако сразу вызывает функцию satur из пространства имен нужного класса
через switch и enum
и возвращает int

*/