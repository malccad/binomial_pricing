#ifndef PATH_INDEPENDENT_OPTION_EUROPEAN_H
#define PATH_INDEPENDENT_OPTION_EUROPEAN_H
#include "pathIndependentOption.h"

class EuropeanPathIndependentOption: public PathIndependentOption
{
public:
    EuropeanPathIndependentOption(
        unsigned long expiry,
        const Wrapper<PayOff>& thePayOff
    );
};
#endif