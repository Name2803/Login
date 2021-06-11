#include"server.h"

void server(const std::string outID)
{
	const std::string path = "data.txt";
	std::string inID;
	std::string fName;
	std::string lName;
	int year;
	std::string other;
	int idn;



	std::ifstream fin;
	fin.open(path);
	while (!fin.eof())
	{
		fin >> inID >> fName >> lName >> year >> other;
		for (idn = 0; idn < 3; idn++)
			if (inID[idn] != outID[idn])
				break;
		if (idn == 3)
			std::cout << fName
			<< "\n"
			<< lName
			<< "\n"
			<< year
			<< "\n"
			<< other;
	}
	fin.close();
}