#ifndef PATH_INDEPENDENT_OPTION_AMERICAN_H
#define PATH_INDEPENDENT_OPTION_AMERICAN_H
#include "pathIndependentOption.h"

class AmericanPathIndependentOption: public PathIndependentOption
{
public:
    AmericanPathIndependentOption(
        unsigned long expiry,
        const Wrapper<PayOff>& thePayOff
    );
};
#endif