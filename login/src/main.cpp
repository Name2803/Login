#include <iostream>
#include <string>
#include "../secure/secure.h"

struct data
{
	std::string log;
	std::string pass;
};


int main()
{
	struct data a;
	setlocale(LC_ALL, "RU");
	std::cout << "¬ведите логин и пароль:\n";
	std::cin >> a.log;
	std::cin >> a.pass;

	sdf(a.log, a.pass);
	return 0;
}



/*
открыть файл и записывать в него что-то

#include <iostream>
#include <string>
#include <fstream>

int main()
{
	setlocale(LC_ALL, "RU");
	const std::string path =  "001.txt";
	std::ofstream fout;
	fout.open(path, std::ofstream::app);
	if (!fout.is_open())
	{
		std::cout << "Problem with file!\n";
		return -1;
	}

	fout << "привет\n";

	fout.close();


	return 0;
}*/


/*
#include <iostream>
#include <string>
#include <fstream>

int main()
{
	setlocale(LC_ALL, "RU");
	const std::string path =  "001.txt";
	std::ifstream fin;
	fin.open(path);
	if(!fin.is_open())
	{
		std::cout << "Problem with file!\n";
	}
	else
	{
		std::cout << "File is opened successfule!\n";
		char ch;
		//дл€ символов
		while(fin.get(ch))
		{
			std::cout << ch;
		}

		//дл€ строк
		std::string std;
		char str2[20];
			//один способ
		while(!fin.eof())
		{
			str = "";
			fin >> str;
			std::cout << str << "\n";
		}

			//второй способ

			while(!fin.eof())
		{
			str = "";
			std::getline(fin, str);
			fin.getline(str2, 20);
			std::cout << str << "\n";
		}
	}



	fin.close();
*/