#pragma once
#include <fstream>
#include "Insurance.h"
#include "FamilyInsurance.h"
#include "AutoInsurance.h"

namespace InsuranceReadKeyWords 
{
	const std::string FamilyInsuranceKeyWord = "FamilyInsurance:";
	const std::string AutoInsuranceKeyWord = "AutoInsurance:";
	const std::string basePriceKeyWord = "basePrice:";
	const std::string familySizeKeyWord = "familySize:";
	const std::string engineVolumeKeyWord = "engineVolume:";
}

Insurance** CorrectReadingFromFile(std::ifstream&, unsigned);