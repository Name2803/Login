#include "sec.h"


std::string secu(const std::string& outLog, const std::string& outPass)
{
	setlocale(LC_ALL, "RU");
	const std::string path = "../secure/001.txt";

	std::string inLog;
	std::string inPass;
	std::string ID;
	

#ifdef DEBUG

	std::cout << "������ ��������\n";
#endif // DEBUG

	std::cout << outLog << std::endl;
	std::cout << outPass << std::endl;

//-----otkritie fayla----------
	std::ifstream fin;
	fin.open(path);
	fin >> inLog;
	fin >> inPass;
	fin >> ID;
	while (!fin.eof())
	{
		if (sizeof(inLog) != sizeof(outLog) || sizeof(inPass) != sizeof(outPass))
			continue;

		for (int i = 0; inLog[i] != '\0' && outLog[i] != '\0'; i++)
			if (inLog[i] != outLog[i])
				break;
		for (int i = 0; inPass[i] != '\0' && outPass[i] != '\0'; i++)
		{
			if (inPass[i] != outPass[i])
				break;
			if (inPass[sizeof(inPass) / 8 - 2] == outPass[sizeof(outPass) / 8 - 2])
			{
				std::cout << "�������� ��������\n";
				return ID;
			}
		}

	}

	std::cout << "������������ ����� ��� ������\n";

	fin.close();
	return 0;
}