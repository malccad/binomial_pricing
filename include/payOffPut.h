#ifndef PAYOFF_PUT_H
#define PAYOFF_PUT_H
#include "payOff.h"
#include <map>
#include <string>
class PayOffPut: public PayOff
{
public:
    PayOffPut(std::map<std::string, double> payOffParams_);

    virtual PayOff* clone() const;
    virtual ~PayOffPut(){}

    virtual double operator()(double spot) const;
private:
    std::map<std::string, double> payOffParams;
};
#endif