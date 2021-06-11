#include <iostream>
#include <string>
#include "../secure/sec.h"
#include "../server/server.h"

struct data_1
{
	std::string log;
	std::string pass;
	std::string ID;
};


int main()
{
	setlocale(LC_ALL, "RU");
	struct data_1 a;
	
	
	std::cout << "¬водите логин и пароль:\n";
	std::cin >> a.log;
	std::cin >> a.pass;


	a.ID = secu(a.log, a.pass);

	server(a.ID);

	return 0;
}
