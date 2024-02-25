#pragma once
#include "Insurance.h"

class AutoInsurance :
    public Insurance
{
private:
    double engineVolume = 0;
public:
    AutoInsurance() = default;
    AutoInsurance(double);
    AutoInsurance(double base, double engine);
    virtual ~AutoInsurance();

    virtual void PrintTo(std::ostream&) const override;
    virtual void ReadFrom(std::istream&) override;
    virtual double GetFullPrice() const override;
};

