#include "../include/payOffPut.h"
PayOffPut::PayOffPut(double strike_)
    :strike(strike_)
{}

PayOff* PayOffPut::clone() const
{
    return new PayOffPut(*this);
}

double PayOffPut::operator()(double spot) const
{
    return (strike-spot<0.0)? 0.0 : spot-strike;
}