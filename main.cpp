#include <iostream>
#include "include/pricingEngine.h"
#include "include/derivativeTree.h"
#include "include/europeanPathIndependentOption.h"
#include "include/americanPathIndependentOption.h"
#include "include/payOffCall.h"
#include "include/payOffPut.h"
int main()
{
    unsigned long expiry;
    double up;
    double down;
    double spot;
    double r;
    double strike;
    std::cout << "\nEnter expiry\n";
    std::cin >> expiry;
    std::cout << "\nEnter up\n";
    std::cin >> up;
    std::cout << "\nEnter down\n";
    std::cin >> down;
    std::cout << "\nEnter spot\n";
    std::cin >> spot;
    std::cout << "\nEnter r\n";
    std::cin >> r;
    std::cout << "\nEnter strike\n";
    std::cin >> strike;

    PayOffCall payOffCall(strike);
    PayOffPut payOffPut(strike);

    std::cout << "Payoffs done.\n";
    EuropeanPathIndependentOption euroCallOption(
        expiry,
        payOffCall
    );
    EuropeanPathIndependentOption euroPutOption(
        expiry,
        payOffPut
    );
    AmericanPathIndependentOption amerCallOption(
        expiry,
        payOffCall
    );
    AmericanPathIndependentOption amerPutOption(
        expiry,
        payOffPut
    );
    std::cout << "Options done.\n";
    PricingEngine theEngine(
        up,
        down,
        r,
        expiry,
        spot
    );
    std::cout << "Pricing engine done.\n";
    DerivativeTree amerCallTree = theEngine.computeDerivativePrice(
        amerCallOption
    );
    
    unsigned long time;
    unsigned long numHeads;
    std::cout << "\nEnter time\n";
    std::cin >> time;
    std::cout << "\nEnter numHeads\n";
    std::cin >> numHeads;

    double futureDerivativePrice = amerCallTree.getFutureDerivativePrice(time, numHeads);
    std::cout << "Future derivative price at time " << time << ": " << futureDerivativePrice <<"\n"; 

}