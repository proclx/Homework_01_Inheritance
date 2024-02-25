#include "minMax.h"

const Insurance* MaxInsurance(const Insurance* const* allInsurances, unsigned size)
{
    const Insurance* max = allInsurances[0];
    for (unsigned i = 1; i < size; ++i)
    {
        if (*allInsurances[i] > *max)
        {
            max = allInsurances[i];
        }
    }
    return max;
}

const Insurance* MinInsurance(const Insurance* const* allInsurances, unsigned size)
{
    const Insurance* min = allInsurances[0];
    for (unsigned i = 1; i < size; ++i)
    {
        if (*allInsurances[i] < *min)
        {
            min = allInsurances[i];
        }
    }
    return min;
}
