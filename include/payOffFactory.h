#ifndef PAYOFF_FACTORY_H
#define PAYOFF_FACTORY_H

#include "payOff.h"
#include <map>
#include <string>

class PayOffFactory
{
public:
    typedef PayOff* (*CreatePayOffFunction)(std::map<std::string, double>);
    typedef std::map<std::string, double> (*InputParamsFunction)();

    static PayOffFactory& instance();
    void registerPayOff(std::string, InputParamsFunction, CreatePayOffFunction);
    std::map<std::string, double> getPayOffParams(std::string payOffId);
    PayOff* createPayOff(std::string payOffId, std::map<std::string, double> payOffParams);
    ~PayOffFactory(){};
private:
    std::map<std::string, std::pair<InputParamsFunction, CreatePayOffFunction> > theCreatorFunctions;
    PayOffFactory(){};
    PayOffFactory(const PayOffFactory&){};
    PayOffFactory& operator= (const PayOffFactory&){ return *this;}
};
#endif