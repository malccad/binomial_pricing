#include "../include/payOffCall.h"
PayOffCall::PayOffCall(double strike_)
    :strike(strike_)
{}

PayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this);
}

double PayOffCall::operator()(double spot) const
{
    return (spot-strike<0.0)? 0.0 : spot-strike;
}