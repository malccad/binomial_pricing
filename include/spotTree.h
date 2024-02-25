#ifndef SPOT_TREE_H
#define SPOT_TREE_H
#include <vector>

class SpotTree
{
public:
    SpotTree(
        unsigned long expiry,
        double up,
        double down,
        double spot
    );

    double getFutureSpotPrice(
        unsigned long time,
        unsigned long numHeads
    ) const;
private:
    unsigned long expiry;
    double up;
    double down;
    double spot;
    std::vector<std::vector<double> > theTree;

    void resize();
    void computeSpotPrice();
};
#endif