#pragma once
#include "ConsoleOutput.h"

class Authorization {


	public:
		Authorization()
		{

		}
		Authorization(bool start)
		{
			first();
		}
		void first() {
			Output text;
			text.out("Авторизация\nВведите логин и пароль", 20, 5);

		}
};