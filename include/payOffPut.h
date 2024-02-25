#ifndef PAYOFF_PUT_H
#define PAYOFF_PUT_H
#include "payOff.h"
class PayOffPut: public PayOff
{
public:
    PayOffPut(double strike_);

    virtual PayOff* clone() const;
    virtual ~PayOffPut(){}

    virtual double operator()(double spot) const;
private:
    double strike;
};
#endif