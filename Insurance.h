#pragma once
#include <iostream>

class Insurance
{
protected:
	double basePrice = 0;
public:
	Insurance() = default;
	Insurance(double);
	virtual ~Insurance();

	virtual void PrintTo(std::ostream&) const abstract;
	virtual void ReadFrom(std::istream&) abstract;
	virtual double GetFullPrice() const abstract;

	bool operator<(const Insurance&);
	bool operator>(const Insurance&);
};