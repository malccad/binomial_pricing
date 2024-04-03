#include "../include/pricingEngine.h"
#include <iostream>
PricingEngine::PricingEngine(
    double up_,
    double down_,
    double r_,
    unsigned long expiry_,
    double spot,
    const PathIndependentOption& theOption
    )
    :
    up(up_),
    down(down_),
    r(r_),
    expiry(expiry_),
    theSpotTree(
        expiry_,
        up_,
        down_,
        spot
    ),
    theDerivativeTree(
        up_,
        down_,
        r_,
        expiry_,
        theSpotTree,
        theOption
    )
{
}

double PricingEngine::getFutureDerivativePrice(
    unsigned long time,
    unsigned long numHeads
) const
{
    return theDerivativeTree.getFutureDerivativePrice(time, numHeads);
}