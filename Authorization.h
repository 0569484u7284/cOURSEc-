#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstdlib>
#include "Console.h"

class Authorization {

	std::string wd;

	//шифрование данных
	class Crypt {
	public:
		//принимает ключ для шифрации и возвращает шифр. пароль
		static std::string XOR(std::string key, std::string data) {
			int keyPos = 0;
			for (size_t i = 0; i < data.size(); i++)
			{
				data[i] = data[i] ^ (key[keyPos] * key.size());
				if (keyPos >= key.size())
					keyPos = 0;
			}
			return data;
		}
	};

	//класс данных пользователя
	class User {

	public:
		//пустой конструктор по умочанию
		User(){}
		//конруктор принимает ник пользователя
		User(std::string name)
		{
			this->name = name;
		}
		bool checkPswd(std::string name, std::string pswd) {
			return (name == Crypt::XOR(pswd, name));
		}
		std::string name;
	};

public:

	//
	Authorization(std::string wd = "data.txt")
	{
		this->wd = wd;
	}


	bool loginToUser(std::string Name, std::string pswd) {
		User* u;
		std::string temp;
		std::ifstream in(wd);
		while (std::getline(in, temp))
		{
			u = new User(temp);
			if (u->name == Crypt::XOR(pswd, Name))
			{
				return true;
			};
		}
		return false;
	}


	bool addNew(std::string Name, std::string pswd) {
		std::ofstream outFile(wd, std::ios::app);
		if (!loginToUser(Name, pswd))
		{
			outFile << (Crypt::XOR(pswd, Name)) << "\n";
			return true;
		}
		return false;
	}

};