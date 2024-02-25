#include "FamilyInsurance.h"

FamilyInsurance::FamilyInsurance(unsigned members)
	: familySize(members)
{

}

FamilyInsurance::FamilyInsurance(double basePrice, unsigned members)
	: Insurance(basePrice), familySize(members)
{

}

FamilyInsurance::~FamilyInsurance()
{
	std::cout << "~FamilyInsurance()\n";
}

void FamilyInsurance::PrintTo(std::ostream& out) const
{
	out << "FamilyInsurance: basePrice: " << this->basePrice
		<< " familySize: " << this->familySize;
}

void FamilyInsurance::ReadFrom(std::istream& in)
{
	in >> this->basePrice >> this->familySize;
}

double FamilyInsurance::GetFullPrice() const
{
	return this->familySize * this->basePrice;
}
