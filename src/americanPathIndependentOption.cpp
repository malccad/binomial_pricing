#include "../include/americanPathIndependentOption.h"

AmericanPathIndependentOption::AmericanPathIndependentOption(
        unsigned long expiry,
        const Wrapper<PayOff>& thePayOff
    )
    :
    PathIndependentOption(
        expiry,
        thePayOff)
{   
    for (unsigned long t=0; t<=expiry; t++)
        executionTimes[t] = true;
}