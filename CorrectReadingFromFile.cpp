#include "CorrectReadingFromFile.h"

Insurance** CorrectReadingFromFile(std::ifstream& fin, unsigned size)
{
    Insurance** allInsurances = new Insurance* [size];
    std::string data;

    bool dataTypeInData = false;

    for (unsigned i = 0; i < size; ++i)
    {
        if (not dataTypeInData)
        {
            fin >> data;
            fin.get();
        }
        else
        {
            dataTypeInData = false;
        }
        // we are reading object FamilyInsurance
        if (data == InsuranceReadKeyWords::FamilyInsuranceKeyWord)
        {
            double basePrice = 0;
            unsigned familySize = 1;
            fin >> data;
            fin.get();
            // basePrice is not default
            if (data == InsuranceReadKeyWords::basePriceKeyWord)
            {
                fin >> basePrice;
                fin.get();
                // now let's check familySize
                fin >> data;
                fin.get();
                // familySize is not default
                if (data == InsuranceReadKeyWords::familySizeKeyWord)
                {
                    fin >> familySize;
                    fin.get();
                }
                else
                {
                    dataTypeInData = true;
                }
                allInsurances[i] = new FamilyInsurance(basePrice, familySize);
            }
            // basePrice is default == 0, let's check familySize
            else if (data == InsuranceReadKeyWords::familySizeKeyWord)
            {
                fin >> familySize;
                fin.get();
                allInsurances[i] = new FamilyInsurance(familySize);
            }
            else
            {
                allInsurances[i] = new FamilyInsurance();
                dataTypeInData = true;
            }
        }
        // we are reading object AutoInsurance
        else if (data == InsuranceReadKeyWords::AutoInsuranceKeyWord)
        {
            double basePrice = 0;
            unsigned engineVolume = 0;
            fin >> data;
            fin.get();
            // basePrice is not default
            if (data == InsuranceReadKeyWords::basePriceKeyWord)
            {
                fin >> basePrice;
                fin.get();
                // now let's check engineVolume
                fin >> data;
                fin.get();
                // engineVolume is not default
                if (data == InsuranceReadKeyWords::engineVolumeKeyWord)
                {
                    fin >> engineVolume;
                    fin.get();
                }
                else
                {
                    dataTypeInData = true;
                }
                allInsurances[i] = new AutoInsurance(basePrice, engineVolume);
            }
            // basePrice is default == 0, let's check engineVolume
            else if (data == InsuranceReadKeyWords::engineVolumeKeyWord)
            {
                fin >> engineVolume;
                fin.get();
                allInsurances[i] = new AutoInsurance(engineVolume);
            }
            else
            {
                allInsurances[i] = new AutoInsurance();
                dataTypeInData = true;
            }
        }
        else
        {
            throw("Error::Insurance type is unknown\n");
        }
    }
    return allInsurances;
}