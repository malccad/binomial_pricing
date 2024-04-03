#include <iostream>
#include "include/pricingEngine.h"
#include "include/derivativeTree.h"
#include "include/europeanPathIndependentOption.h"
#include "include/americanPathIndependentOption.h"
#include "include/inputPayOffParams.h"
#include "include/payOff.h"
#include "include/payOffCall.h"
#include "include/payOffPut.h"
#include "include/payOffDoubleDigital.h"
#include "include/payOffFactory.h"
#include "include/payOffHelper.h"
#include "include/spotTree.h"
int main()
{
    unsigned long expiry;
    double up;
    double down;
    double spot;
    double r;
    std::string payOffId;
    int optionInput;
    PathIndependentOption* optionPtr = 0;

    std::cout << "\nEnter the expiry.\n";
    std::cin >> expiry;
    std::cout << "\nEnter the up factor.\n";
    std::cin >> up;
    std::cout << "\nEnter the down factor.\n";
    std::cin >> down;
    std::cout << "\nEnter spot, i.e. the current price of the underlying asset.\n";
    std::cin >> spot;
    std::cout << "\nEnter the interest rate.\n";
    std::cin >> r;
    std::cout << "\nEnter the pay off type. (Here are the available choices: 'call', 'put', 'doubleDigital')\n";
    std::cin >> payOffId;
    std::map<std::string, double> payOffParams = PayOffFactory::instance().getPayOffParams(payOffId);
    PayOff* payOffPtr = PayOffFactory::instance().createPayOff(payOffId, payOffParams);

    std::cout << "\nEnter option type (0 for european and 1 for american)\n";
    std::cin >> optionInput;

    switch (optionInput) {
        case 0:
            optionPtr = new EuropeanPathIndependentOption(
                expiry,
                *payOffPtr
            );
            break;
        case 1:
            optionPtr = new AmericanPathIndependentOption(
                expiry,
                *payOffPtr
            );
            break;
        default:
            std::cerr << "Invalid input!" << std::endl;
            return 1;
    };
    PricingEngine theEngine(
        up,
        down,
        r,
        expiry,
        spot,
        *optionPtr
    );
    
    unsigned long time;
    unsigned long numHeads;
    std::cout << "\nEnter the time, an integer between 0 and expiry, when you would like to know the price of the option:\n";
    std::cin >> time;
    std::cout << "\nEnter the number of heads yielded between now and the time that you just entered.\n";
    std::cin >> numHeads;

    double futureDerivativePrice = theEngine.getFutureDerivativePrice(time, numHeads);
    std::cout << "Derivative price at time " << time << ": " << futureDerivativePrice <<"\n"; 

    delete optionPtr;
    delete payOffPtr;
}