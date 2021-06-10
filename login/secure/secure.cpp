#include "secure.h"
#define DEBUG

class Prov
{
public:
	int prov(const std::string& fLog, const std::string& fPass)
	{
#ifdef DEBUG
		std::cout << "Вызвана функция проверки\n";
#endif // DEBUG
		if (ror(fLog, fPass) == -1)
			return -1;

#ifdef DEBUG
		std::cout << "провекрка прошла\n";
#endif // DEBUG
		return 0;
	}

	
private:

	std::string ID;

	int ror(const std::string& fLog, const std::string& fPass)
	{
		std::string inLog;
		std::string inPass;

		const std::string path = "001.txt";


		//-----------chtenie fiyla----------------
		std::ifstream fin;
		fin.open(path);
		fin >> inLog;
		fin >> inPass;
		fin >> this->ID;


		//-------proverka logina i paroli-------
		if (sizeof(inLog) != sizeof(fLog) || sizeof(inPass) != sizeof(fPass))
		{
			std::cout << "Неправильный логин или пароль!" << std::endl;
			return -1;
		}


		for (int i = 0; inLog[i] != '\0' && fLog[i] != '\0'; i++)
		{
			if (inLog[i] != fLog[i])
			{
				std::cout << "Неправильный логин или пароль!" << std::endl;
				return -1;
			}
		}

		for (int i = 0; inPass[i] != '\0' && fPass[i] != '\0'; i++)
		{
			if (inPass[i] != fPass[i])
			{
				std::cout << "Неправильный логин или пароль!" << std::endl;
				return -1;
			}
		}


		fin.close();
	}
};

int sdf(const std::string& fLog, const std::string& fPass)
{
	Prov a;
	if (a.prov(fLog, fPass) == -1)
		return -1;


	return 0;
}
