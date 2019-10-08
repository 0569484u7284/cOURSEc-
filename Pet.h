#pragma once
#include <string>
#include "Preference.h"


class Pet {

protected: //�������� ������ ����������� ������
	std::string name;

	//��������� �������� 
	int saturation = 100;
	int enjoy = 100;

	Preferences pref;

public:
	enum tamagochiType { FishID, CatID, DogID, OttersID, CoonID };

	// ������������������� ����������� ��������� �����
	//static Pet* createPet(tamagochiType id);


	//������� ����� � ����� ��������� � ���� ��������� �� ������� � ��� ���������
	//feed ��������� � ���� ������� ��� ���������� ��������� � �������
	//void play(Game* game) {
	//	//saturation += game->Play(this);
	//};

	virtual void feedPet() = 0;

	//���������/�������� ��� �������
	void setPetName(std::string enteredValue) {
		name = enteredValue;
	}
	std::string getPetName() { return name; }


	void setPreferences(Preferences pref) {
		this->pref = pref;
	}


	//������� ���������� ������������, ���� ������� ������ ������ � ������������
	void hungry() {

		if (saturation < 15)
			Console::WriteLine("Pet is very hungry! Feed him! Or not", { 3,3 }, GREEN, WHITE);
		if (saturation < 5)//����������� ������� ������, 
			Console::WriteLine("Critical level of life!\It live in Ukrane ", { 3,3 }, RED, WHITE);
		if (saturation < 0)
			Console::WriteLine("Your pet tragically died in pain in Ukrane cuz u stupid idiot!", 3, 3);

	}

	Preferences* getPref() { return &pref; };


	//������� ����������� ������� � ��������� � ������� ����
	void time() {
		while (true)
		{
			clock_t t1 = clock();
			if (double(t1) / CLOCKS_PER_SEC >= 1) {
				enjoy--;
				saturation--;
			}

			hungry();//� ������� ���������� ������������, ���� ������� ������ ������ � ������������
		}
	}

	void incEnjoy(int score) {
		enjoy += score;
	}

	void showStatus() {
		time();

	}
};
