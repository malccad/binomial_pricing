#ifndef PAYOFF_CALL_H
#define PAYOFF_CALL_H
#include "payOff.h"
#include <map>
#include <string>
class PayOffCall: public PayOff
{
public:
    PayOffCall(std::map<std::string, double> payOffParams_);

    virtual PayOff* clone() const;
    virtual ~PayOffCall(){}

    virtual double operator()(double spot) const;
private:
    std::map<std::string, double> payOffParams;
};
#endif