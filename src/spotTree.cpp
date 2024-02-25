#include "../include/spotTree.h"

SpotTree::SpotTree(
    unsigned long expiry_,
    double up_,
    double down_,
    double spot_
    )
    :
    expiry(expiry_),
    up(up_),
    down(down_),
    spot(spot_)
{
    resize();
    computeSpotPrice();
}

void SpotTree::resize()
{
    theTree.resize(expiry + 1);
    for (unsigned long i=0; i<expiry+1; i++)
    {
        theTree[i].resize(i+1);
    }
}

void SpotTree::computeSpotPrice()
{
    theTree[0][0] = spot;
    for (unsigned long i=1; i<theTree.size(); i++)
    {   
        theTree[i][0] = theTree[i-1][0]*up;
        for (unsigned long j=1; j<=i; j++)
        {
            theTree[i][j] = theTree[i-1][j-1]*down;
        }
    }
}

double SpotTree::getFutureSpotPrice(
        unsigned long time,
        unsigned long numHeads
    ) const
{
    return theTree[time][time-numHeads];
}