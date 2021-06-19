#include <iostream>
#include <string>
#include <fstream>
#include "../secure/sec.h"
#include "../server/server.h"
#define DEBUG

struct data_1
{
	std::string log;
	std::string pass;
};


struct data_2
{
	std::string fname;
	std::string lname;
	std::string log;
	std::string pass;
	std::string sex;
	std::string year;
	std::string other;
	std::string ID;
};

int main()
{
	setlocale(LC_ALL, "RU");
	struct data_1 a;
	struct data_2 b;
	std::string temp;
	const std::string path = "../secure/001.txt";
	std::ifstream fin;
	int tempi = 0;
	int tempi1 = 0;
	int tempi2 = 0;


	
	
	std::cout << "Регистрация:\n";
	std::cout << "имя: ";
	std::cin >> b.fname;
	std::cout << "Фамилия: ";
	std::cin >> b.lname;
	std::cout << "Год: ";
	std::cin >> b.year;
	std::cout << "Пол: ";
	std::cin >> b.sex;
	std::cout << "Прочее: ";
	std::cin >> b.other;

	std::cout << "Придумайте логин: ";
	std::cin >> b.log;
	tempi2 = sizeof(b.log);
	fin.open(path);
	while (!fin.eof())
	{
		fin >> temp;

		tempi1 = sizeof(temp);

		if (tempi2 != tempi1)
		{
#ifdef DEBUG
			std::cout << "pravilno\n";
#endif // DEBUG
			return 0;
		}

		for (int i = 0; i < tempi1; i++)
		{
			if (b.log[i] != temp[i])
			{
#ifdef DEBUG
				std::cout << "pravilno\n";
#endif // DEBUG
				return 0;
			}
		}
	}
	std::cout << "login uje sushestvuet\n";
	fin.close();


	/*std::cout << "Вводите логин и пароль:\n";
	std::cin >> a.log;
	std::cin >> a.pass;


	secu(a.log, a.pass);*/

	return 0;
}
