#include "../include/europeanPathIndependentOption.h"

EuropeanPathIndependentOption::EuropeanPathIndependentOption(
        unsigned long expiry,
        const Wrapper<PayOff>& thePayOff
    )
    :
    PathIndependentOption(
        expiry,
        thePayOff)
{   
    for (unsigned long t=0; t<=expiry-1; t++)
        executionTimes[t] = false;
    executionTimes[expiry] = true;
}