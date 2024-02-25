#pragma once
#include "Insurance.h"

class FamilyInsurance 
	: public Insurance
{
private:
	unsigned familySize = 1;
public:
	FamilyInsurance() = default;
	FamilyInsurance(unsigned);
	FamilyInsurance(double, unsigned);
	virtual ~FamilyInsurance();

	virtual void PrintTo(std::ostream&) const override;
	virtual void ReadFrom(std::istream&) override;
	virtual double GetFullPrice() const override;
};

