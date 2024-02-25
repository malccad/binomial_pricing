#include "../include/pathIndependentOption.h"

PathIndependentOption::PathIndependentOption(
    unsigned long expiry_,
    const Wrapper<PayOff>& thePayOff_
)
:expiry(expiry_), payOffPtr(thePayOff_), executionTimes(expiry_ + 1)
{}