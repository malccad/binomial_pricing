#include "../include/derivativeTree.h"
#include <iostream>
DerivativeTree::DerivativeTree(
    double up,
    double down,
    double r_,
    unsigned long expiry
    )
    :
    r(r_)
{
    p = (1+r_ - down)/(up - down);
    q = (up - 1 - r_)/(up - down);
    resizeTrees(expiry);
}

void DerivativeTree::resizeTrees(unsigned long depth)
{
    price.resize(depth + 1);
    executionStrategy.resize(depth + 1);
    for (unsigned long i=0; i<depth+1; i++)
    {
        price[i].resize(i+1);
        executionStrategy[i].resize(i+1);
    }
}

double DerivativeTree::getIntrinsicVal(
    unsigned long time,
    unsigned long numHeads,
    const SpotTree& theSpotTree,
    const PathIndependentOption& theOption
) const
{
    double curSpot = theSpotTree.getFutureSpotPrice(time, numHeads);
    return theOption.getPayOff(curSpot);
}

double DerivativeTree::getDiscountedFuture(
    unsigned long time,
    unsigned long numHeads
) const
{
    return 1/(1+r)*(p*price[time+1][time-numHeads] + q*price[time+1][time+1-numHeads]);
}

void DerivativeTree::computeDerivativePrice(
    const SpotTree& theSpotTree,
    const PathIndependentOption& theOption
    )
{
    std::vector<bool> executionTimes = theOption.getExecutionTimes();
    for (int t=price.size()-1; t>=0 ;t--)
    {   
        std::cout << "t: "<< t <<"\n";
        for (unsigned long numHeads=0; numHeads<=t; numHeads++)
        {
            double intrinsicVal = (executionTimes[t] == true)? getIntrinsicVal(t, numHeads, theSpotTree, theOption) : std::numeric_limits<double>::lowest();
            double discountedFuture = (t<=price.size() - 2)? getDiscountedFuture(t, numHeads): std::numeric_limits<double>::lowest();
            std::cout << "computed intrinsic value and discounted future\n";
            std::cout << "Intrinsic value: "<< intrinsicVal <<"\n";
            std::cout << "Discounted value: "<< discountedFuture <<"\n";
            if (intrinsicVal<discountedFuture)
                {
                    price[t][t-numHeads] = discountedFuture;
                    executionStrategy[t][t-numHeads] = false;
                }
            else
                {
                    price[t][t-numHeads] = intrinsicVal;
                    executionStrategy[t][t-numHeads] = true;                    
                }
            price[t][t-numHeads] = (intrinsicVal<discountedFuture)? discountedFuture: intrinsicVal;
        }
    }

}

double DerivativeTree::getFutureDerivativePrice(
    unsigned long time,
    unsigned long numHeads
) const
{
    return price[time][time-numHeads];
}
