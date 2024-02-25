#include "Insurance.h"

Insurance::Insurance(double price)
	: basePrice(price)
{

}

Insurance::~Insurance()
{
	std::cout << "~Insurance()\n";
}

bool Insurance::operator<(const Insurance& other) const
{
	return this->GetFullPrice() < other.GetFullPrice();
}

bool Insurance::operator>(const Insurance& other) const
{
	return this->GetFullPrice() > other.GetFullPrice();
}

std::ostream& operator<<(std::ostream& out, const Insurance& other)
{
	other.PrintTo(out);
	out << " Insurance.GetFullPrice: " << other.GetFullPrice();
	return out;
}

std::istream& operator>>(std::istream& in, Insurance& I)
{
	I.ReadFrom(in);
	return in;
}
