#include <iostream>
#include "../include/payOffFactory.h"


PayOffFactory& PayOffFactory::instance()
{
    static PayOffFactory theFactory;
    return theFactory;
}

void PayOffFactory::registerPayOff(std::string payOffId, InputParamsFunction inputParamsFunction,CreatePayOffFunction creatorFunction)
{
    std::pair<std::string, std::pair<InputParamsFunction, CreatePayOffFunction> >  nestedPair;

    nestedPair.first = payOffId;
    nestedPair.second = std::make_pair(inputParamsFunction, creatorFunction);

    theCreatorFunctions.insert(nestedPair);
}

std::map<std::string, double> PayOffFactory::getPayOffParams(std::string payOffId)
{
    std::map<std::string, std::pair<InputParamsFunction, CreatePayOffFunction> >::const_iterator i = theCreatorFunctions.find(payOffId);
    return (i->second).first();
}

PayOff* PayOffFactory::createPayOff(std::string payOffId, std::map<std::string, double> payOffParams)
{
    std::map<std::string, std::pair<InputParamsFunction, CreatePayOffFunction> >::const_iterator i = theCreatorFunctions.find(payOffId);
    if (i==theCreatorFunctions.end())
    {
        std::cout << payOffId << " is an unknown payoff" << std::endl;
        return NULL;
    }
    return (i->second).second(payOffParams);
}