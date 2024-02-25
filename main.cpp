#include <iostream>
#include <fstream>
#include "Insurance.h"
#include "FamilyInsurance.h"
#include "AutoInsurance.h"
#include "CorrectReadingFromFile.h"

int main()
{
	unsigned size;
	std::ifstream fin("Insurances.txt");
	fin >> size;
	Insurance** allInsurances = CorrectReadingFromFile(fin, size);
	fin.close();

	for (unsigned i = 0; i < size; ++i)
	{
		allInsurances[i]->PrintTo(std::cout);
		std::cout << '\n';
	}

	for (int i = 0; i < size; ++i)
	{
		delete[] allInsurances[i];
	}
	delete[] allInsurances;

	return 0;
}