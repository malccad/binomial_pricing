#ifndef DERIVATIVE_TREE_H
#define DERIVATIVE_TREE_H
#include <vector>
#include "spotTree.h"
#include "pathIndependentOption.h"
class DerivativeTree
{
public:
    DerivativeTree(
        double up,
        double down,
        double r,
        unsigned long expiry
    );

    void computeDerivativePrice(
        const SpotTree& theSpotTree,
        const PathIndependentOption& theOption);

    double getFutureDerivativePrice(
        unsigned long time,
        unsigned long numHeads
    ) const;
private:
    double p;
    double q;
    double r;
    std::vector<std::vector<double> > price;
    std::vector<std::vector<bool> > executionStrategy;

    void resizeTrees(unsigned long depth);
    double getIntrinsicVal(
        unsigned long time,
        unsigned long numHeads,
        const SpotTree& theSpotTree,
        const PathIndependentOption& theOption
    ) const;
    double getDiscountedFuture(
        unsigned long time,
        unsigned long numHeads
    ) const;
};
#endif