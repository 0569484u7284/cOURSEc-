#pragma once
#include <vector>
#include <ctime> //��� ������� time() ������������ ��� clock_t � CLOCKS_PER_SEC
#include <cassert>// assert() ��� ���������� ������ ��������� ��� ���������� ������������� ������ pet
#include "Game.h"
#include "Food.h"
#include "Console.h"
#include "Pet.h"

/*����� ������ ������������ �������� � ��, ��� �� ������� �� �������
��������, ����� ������� �� ������� ����� ����,
 � ����� �� �������� � �������*/


class Cat :public Pet {
	Preferences catPref;

public:
	static void test() {
		Console::CatPics::showPet({ 3, 3 });

	}

	void feedPet() override {


	}

};

class Dog : public Pet {
	Preferences dogPref;


public:

	void feedPet() override {


	}
};

class Fish : public Pet {
	Preferences fishPref;


public:

	void feedPet() override {


	}
};

class Otters : public Pet {
	Preferences ottersPref;


public:


	void feedPet() override {


	}
};

class Coon : public Pet {

public:

	void feedPet() override {


	}
};

class NullPet : public Pet {
public:
	void feedPet() override {


	}
};





#pragma region PetCreationFabricMethod

class PetFabbric {
public:
	static Pet* createPet(int type) {
		switch (type)
		{
		case Pet::FishID:
			return new Fish;
		case  Pet::CatID:
			return new Cat;
		case Pet::DogID:
			return new Dog;
		case Pet::OttersID:
			return new Otters;
		case Pet::CoonID:
			return new Coon;
		default:
			return new NullPet;//��������� ������ ��������� ��� ���������� ������������� �������
		}

		//���������� ��������� � ����������� �����
	}
};



/*//���������� �������� fabric   tamagochiType { FishID = 0, CatID, DogID, OttersID, CoonID };
Pet* Pet::createPet(tamagochiType id) {

	Pet* pet;

	switch (id)
	{
	case FishID:
		pet = new Fish;
		break;
	case CatID:
		pet = new Cat;
		break;
	case DogID:
		pet = new Dog;
		break;
	case OttersID:
		pet = new Otters;
		break;
	case CoonID:
		pet = new Coon;
		break;
	default:
		assert(false);//��������� ������ ��������� ��� ���������� ������������� �������
	}

	//���������� ��������� � ����������� �����
	return pet;
}*/


#pragma endregion PetCreationFabricMethod
