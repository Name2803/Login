#include <iostream>
#include <string>
#include "../secure/sec.h"

struct data_1
{
	std::string log;
	std::string pass;
};


int main()
{
	setlocale(LC_ALL, "RU");
	struct data_1 a;
	
	
	std::cout << "¬водите логин и пароль:\n";
	std::cin >> a.log;
	std::cin >> a.pass;


	secu(a.log, a.pass);
	return 0;
}
