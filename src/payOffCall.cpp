#include "../include/payOffCall.h"
PayOffCall::PayOffCall(std::map<std::string, double> payOffParams_)
    :payOffParams(payOffParams_)
{}

PayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this);
}

double PayOffCall::operator()(double spot) const
{
    std::map<std::string, double>::const_iterator i = payOffParams.find("strike");
    double strike = i->second;
    return (spot-strike<0.0)? 0.0 : spot-strike;
}