#include <iostream>
#include <fstream>
#include "Insurance.h"
#include "FamilyInsurance.h"
#include "AutoInsurance.h"
#include "CorrectReadingFromFile.h"
#include "minMax.h"

int main()
{
	unsigned size;
	std::ifstream fin("Insurances.txt");
	fin >> size;
	Insurance** allInsurances = CorrectReadingFromFile(fin, size);
	fin.close();

	std::cout << "File successfully is read\n";

	for (unsigned i = 0; i < size; ++i)
	{
		std::cout << *allInsurances[i] << '\n';
	}

	std::cout << "Max insurance: " << *MaxInsurance(allInsurances, size) << '\n';
	std::cout << "Min insurance: " << *MinInsurance(allInsurances, size) << '\n';

	for (unsigned i = 0; i < size; ++i)
	{
		delete[] allInsurances[i];
	}
	delete[] allInsurances;

	std::cout << std::endl;
	return 0;
}