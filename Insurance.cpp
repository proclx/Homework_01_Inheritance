#include "Insurance.h"

Insurance::Insurance(double price)
	: basePrice(price)
{

}

Insurance::~Insurance()
{
	std::cout << "~Insurance()\n";
}

bool Insurance::operator<(const Insurance& other)
{
	return this->GetFullPrice() < other.GetFullPrice();
}

bool Insurance::operator>(const Insurance& other)
{
	return this->GetFullPrice() > other.GetFullPrice();
}
