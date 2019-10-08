#pragma once
#include "GatKey.h"
#include <Windows.h>


//вложенный класс для отрисовки и выбора пнктов меню///////////////////////
class Menu {
	std::vector<std::string> titles;//вектор выводимых пунктов меню
	int active;//текущий пункт меню
	COORD pos;
public:
	Menu()
	{

	}
	Menu(std::vector<std::string> titles, COORD start)
	{
		active = 0;
		this->titles = titles;
		this->pos = start;
	}
	void setNewMenu(std::vector<std::string> titles, COORD start) {
		active = 0;
		this->titles = titles;
		this->pos = start;
	}

	void updateActive() {
		for (size_t i = 0; i < titles.size(); i++)
		{
			if (i == active)//когда цикл дошел до активного пункта меню
				SetColor(BLACK, WHITE);

			else
				SetColor(WHITE, BLACK);

			//смещает курсор на количество уже отображенных пунктов меню
			SetCursorPosition(pos.X + (i * titles[0].size() + i) + 1, pos.Y + 1);
			std::cout << titles[i];//вывод пункта меню 
			SetColor(WHITE, BLACK);
		}
	}

	//возвращает номер выбранного пользователем меню
	int userChoise() {
		bool choise = false;
		updateActive();
		//цикл выполняется, пока  while (!choise); выбор не будет сделан choise = true
		do
		{
			if (_kbhit()) {
				switch (keyHandler())//возвращает истину, если нажата какая-либо клавиша на клавиатуре библиотека conio.h
				{

				case key_RightArrow: {
					if (active < titles.size() - 1)
						active++;

					else
						active = 0;
					break;
				}
				case key_LeftArrow: {
					if (active > 0)
						active--;

					else
						active = titles.size() - 1;
					break;
				}
				case key_ENTER:
					choise = true;
					break;

				default:
					break;
				}
				updateActive();
			}
		} while (!choise);
		//очистить консоль
		system("cls");

		return active;
	}

	//преобразовывавет все заголовки к одному размеру для отображения меню 
	void modify() {
		int maxSize = 0;
		for (auto s : titles)
		{
			if (s.size() > maxSize)
				maxSize = s.size();
		}
		for (auto& data : titles)
		{
			while (data.size() < maxSize)
			{
				data.insert(data.size(), " ");
			}
		}
	}


	//отрисовка рамки
	void printFrame() {
		SetCursorPosition(pos.X, pos.Y);

		modify();//все к одному размеру, чтобі отрисовать рамку

		std::cout << char(LeftTopDoubleFrame);
		for (size_t i = 1; i < titles[0].size() * titles.capacity() + titles.capacity(); i++)
		{
			if (i % (titles[0].size() + 1) != 0)
				std::cout << char(205); //═══

			else
				std::cout << char(203); //═╦═
		}
		std::cout << char(RightTopDoubleFrame);
		SetCursorPosition(pos.X, pos.Y + 1);

		std::cout << char(StraitUpDown);
		for (size_t i = 0; i <= titles.capacity(); i++)
		{
			SetCursorPosition(pos.X + (i * titles[0].size() + i), pos.Y + 1);
			std::cout << char(StraitUpDown);
		}
		SetCursorPosition(pos.X, pos.Y + 2);

		std::cout << char(LeftDownDoubleFrame);
		for (size_t i = 1; i < titles[0].size() * titles.capacity() + titles.capacity(); i++)
		{
			if (i % (titles[0].size() + 1) != 0)
				std::cout << char(205); //═

			else
				std::cout << char(202); //╩
		}
		std::cout << char(RightDownDoubleFrame);
	}

	//открывает меню, отрисовывает и возвращает выбор пользователя
	int open() {
		//если опций меню нет, возвращает ноль
		if (titles.size() - 1 <= 0)
			return -1;

		printFrame();

		return userChoise();
	}

};

