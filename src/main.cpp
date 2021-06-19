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

int reg();
void zap();
int id();
	
struct data_2 b;
const std::string path = "../secure/001.txt";

int main()
{
	int laba;
	setlocale(LC_ALL, "RU");
	struct data_1 a;


	
	std::cout << "Выберите путь:\n"
		<< "1. Регистрация\n"
		<< "2. Логин\n";
	std::cin >> laba;

	if (laba == 1)
	{
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
		while (reg() != 0);
	}
		

	else if (laba == 2)
	{
		std::cout << "Вводите логин и пароль:\n";
		std::cin >> a.log;
		std::cin >> a.pass;


		secu(a.log, a.pass);
	}
	return 0;
}


int reg()
{
	std::string temp;
	std::ifstream fin;
	int tempi = 0;
	int tempi1 = 0;
	int tempi2 = 0;

	std::cout << "Придумайте логин: ";
	std::cin >> b.log;
	tempi2 = sizeof(b.log) / 8;
	fin.open(path);
	while (!fin.eof())
	{
		fin >> temp;

		tempi1 = sizeof(temp) / 8;

		if (tempi2 != tempi1)
		{
#ifdef DEBUG
			std::cout << "pravilno\n";
#endif // DEBUG
			return 0;
		}

		for (int i = 0; i < tempi1 - 1; i++)
		{
			if (b.log[i] != temp[i])
			{
#ifdef DEBUG
				std::cout << "pravilno\n";

#endif // DEBUG
				zap();
				return 0;
			}
		}
	}
	fin.close();
	std::cout << "login uje sushestvuet\n";
	return 1;
}

void zap()
{
	int ID;
	std::string temp1;
	int prov = 0;

	std::ofstream fout;

	fout.open(path, std::ofstream::app);
	ID = id(); ID++;
	fout << b.log << " ";
	

	std::cout << "Введите пароль:\n";
	std::cin >> b.pass;

	while (prov != 1)
	{
		std::cout << "подтвердите пароль:\n";
		std::cin >> temp1;
		if (sizeof(b.pass) / 8 != sizeof(temp1) / 8)
			prov = 0;
		else
		{
			for (int i = 0; i < sizeof(b.pass) / 8 - 1; i++)
			{
				if (b.pass[i] != temp1[i])
				{
					std::cout << "неправильный пароль!\nПовторите попытку\n";
					prov = 0;
					break;
				}

				if (b.pass[sizeof(b.pass) / 8 - 2] == temp1[sizeof(b.pass) / 8 - 2])
				{
					std::cout << "Пароль потвержден\n";

					fout << b.pass << " " << ID << "\n";
					zapSer(ID, b.fname, b.lname, b.year, b.sex, b.other);

					return;
				}
			}
		}
	}



	fout.close();

}

int id()
{
	std::string temp;
	int lastId;

	std::ifstream fin;
	fin.open(path);
	while (!fin.eof())
		fin >> temp >> temp >> lastId;

#ifdef DEBUG
	std::cout << lastId;
#endif // DEBUG


	fin.close();
	return lastId;
}