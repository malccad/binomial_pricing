#ifndef PRICING_ENGINE_H
#define PRICING_ENGINE_H
#include "pathIndependentOption.h"
#include "spotTree.h"
#include "derivativeTree.h"

class PricingEngine
{
public:
    PricingEngine(
        double up,
        double down,
        double r,
        unsigned long expiry,
        double spot
    );
    DerivativeTree computeDerivativePrice(
        const PathIndependentOption& theOption
    );

private:
    SpotTree theSpotTree;
    double up;
    double down;
    double r;
    unsigned long expiry;
};

#endif