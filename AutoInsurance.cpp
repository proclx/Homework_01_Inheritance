#include "AutoInsurance.h"

const double ENGINE_VOLUME_MORE_THAN_2 = 1.15;
const double ENGINE_VOLUME_MORE_THAN_3 = 1.25;

AutoInsurance::AutoInsurance(double volume)
	: engineVolume(volume)
{

}

AutoInsurance::AutoInsurance(double base, double engine)
	: Insurance(base), engineVolume(engine)
{

}

AutoInsurance::~AutoInsurance()
{
	std::cout << "~AutoInsurance()\n";
}

void AutoInsurance::PrintTo(std::ostream& out) const
{
	out << "AutoInsurance: basePrice: " << this->basePrice
		<< " engineVolume: " << this->engineVolume;
}

void AutoInsurance::ReadFrom(std::istream& in)
{
	in >> this->basePrice >> this->engineVolume;
}

double AutoInsurance::GetFullPrice() const
{
	double result = 0;
	if (this->engineVolume > 2.0)
	{
		result = this->basePrice * ENGINE_VOLUME_MORE_THAN_2;
	}
	else if (this->engineVolume > 3.0)
	{
		result = this->basePrice * ENGINE_VOLUME_MORE_THAN_3;
	}
	else
	{
		result = this->basePrice;
	}
	return result;
}
