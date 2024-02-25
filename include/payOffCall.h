#ifndef PAYOFF_CALL_H
#define PAYOFF_CALL_H
#include "payOff.h"
class PayOffCall: public PayOff
{
public:
    PayOffCall(double strike_);

    virtual PayOff* clone() const;
    virtual ~PayOffCall(){}

    virtual double operator()(double spot) const;
private:
    double strike;
};
#endif