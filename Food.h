#pragma once

class Food {

	//������� ����� � ����
public:


};

class FeedPet {
	Menu* chooseMealMenu = new Menu;
	std::vector<Food*> meal;

public:
	~FeedPet()
	{
		for (auto a : meal)
		{// �������� ���� ��������� ������� ������� ������
			delete a;
		}
	}

	FeedPet()
	{
	
	}
};


class Water {//����
public:
	int satur() {
		return 2;
	}
};

class Cheese {//���
public:
	int satur() {
		return 10;
	}
};


/*
������������ ������������������� ����� �������,
������� ������ ����� �������� ������� satur �� ������������ ���� ������� ������
����� switch � enum
� ���������� int

*/