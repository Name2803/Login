#include"server.h"

const std::string path = "../server/data.txt";

void server(const std::string outID)
{
	setlocale(LC_ALL, "RU");
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


void zapSer(const int ouyID, const std::string outFn, const std::string outLn, const std::string outY, const std::string outS, const std::string outO)
{
	setlocale(LC_ALL, "RU");
	std::ofstream fout;
	fout.open(path, std::ofstream::app);
	fout << ouyID << " " << outFn << " " << outLn << " " << outY << " " << outS << " " << outO << "\n";
	fout.close();
}