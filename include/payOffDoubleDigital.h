#ifndef PAYOFF_DOUBLE_DIGITAL_H
#define PAYOFF_DOUBLE_DIGITAL_H
#include "payOff.h"
#include <map>
#include <string>
class PayOffDoubleDigital: public PayOff
{
public:
    PayOffDoubleDigital(std::map<std::string, double> payOffParams_);

    virtual PayOff* clone() const;
    virtual ~PayOffDoubleDigital(){}

    virtual double operator()(double spot) const;
private:
    std::map<std::string, double> payOffParams;
};
#endif