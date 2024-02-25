#include "../include/pricingEngine.h"
#include <iostream>
PricingEngine::PricingEngine(
    double up_,
    double down_,
    double r_,
    unsigned long expiry_,
    double spot
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
    )
{
}

DerivativeTree PricingEngine::computeDerivativePrice(
    const PathIndependentOption& theOption
)
{
    DerivativeTree theDerivativeTree(
        up,
        down,
        r,
        expiry
    );
    std::cout << "Derivative tree initialized.\n";
    theDerivativeTree.computeDerivativePrice(
        theSpotTree,
        theOption
    );
    std::cout << "Derivative price is computed.\n";
    return theDerivativeTree;
}