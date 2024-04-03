#include "../include/inputPayOffParams.h"
#include <iostream>
#include <map>

std::map<std::string, double> inputStrike()
{
    double strike;
    std::map<std::string, double> out;

    std::cout << "\nEnter strike\n";
    std::cin >> strike;
    
    out.insert(std::make_pair("strike", strike));
    return out;
}
std::map<std::string, double> inputDoubleDigital()
{
    double lowerStrike;
    double upperStrike;
    std::map<std::string, double> out;

    std::cout << "\nEnter lower strike\n";
    std::cin >> lowerStrike;

    std::cout << "\nEnter upper strike\n";
    std::cin >> upperStrike;

    out.insert(std::make_pair("lowerStrike", lowerStrike));
    out.insert(std::make_pair("upperStrike", upperStrike));
    return out;
}