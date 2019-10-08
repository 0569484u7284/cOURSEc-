#pragma once

#include "Console.h"
#include "PetBaseClass.h"
#include "Menu.h"


//класс, через который происходит вывод, "анимация", выбор питомца
//отвечает за вывод игры на консоль


class Tamagochi {

	GameLand g;

	void StartRegistrationScreen() {

		Authorization auth("text.txt");
		Console::Registartion(auth);
	}

	Pet* setPet() {
		Console::WriteLine("Choose your tamadochi:", 6, 5);

		//список возможных питомцев рыбка, котик, песель, выдра, енотик
		Menu menu({ "Fish", "Cat", "Dog", "Otters", "Coon" }, { 6,6 });
		//           0        1      2       3         4     координаты

		////(menu.open() возвращает выбранный пункт мен
		Pet* pet = PetFabbric::createPet(menu.open());
		system("cls");

		Console::WriteLine("Enter name for your pet", { 5,5 });
		pet->setPetName(Console::getLine({ 5, 6 }));
		return pet;
	}

	void laod() {}
	void save() {}
public:
	Tamagochi()
	{
		laod();
		//	StartRegistrationScreen();
		/*setPet*///();
	}
	~Tamagochi()
	{
		save();
	}

	//начать игру
	void Start() {
		bool exit = false;
		Pet* startPet = setPet();

		//выбор из меню
		Menu chooseAction({ "Play","Feed", "Sleep" }, { 3,3 });

		//выполняется, пока пользователь не захочет выйти
		do
		{
			if (startPet != 0)//если пользователь уже создал себе тамагочика
			{
				switch (chooseAction.open())//смотрит выбор пользователя
				{
				case 0://пользователь выбрал поиграть
					//просим питомца поиграть, показываем ему игру, которую выбирает пользователь 
					g.ChooseGame()->Play(startPet);
					break;
				case 1://пользователь выбрал покормить
					Console::WriteLine("IN development Feed", { 5,5 });
					break;
				case 2:
					Console::WriteLine("IN development Sleep", { 5,5 });
					break;
				default:
					break;
				}
				//update pet
				//interuct user

			}
			else //иначе создать тамагочика
			{//присваивает тип тамагочика
			}
		} while (!exit);
	}


};