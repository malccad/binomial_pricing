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
        double spot,
        const PathIndependentOption& theOption
    );
    double getFutureDerivativePrice(
        unsigned long time,
        unsigned long numHeads
    ) const;
private:
    SpotTree theSpotTree;
    DerivativeTree theDerivativeTree;
    double up;
    double down;
    double r;
    unsigned long expiry;
};

#endif