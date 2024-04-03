#include "../include/payOffDoubleDigital.h"
PayOffDoubleDigital::PayOffDoubleDigital(std::map<std::string, double> payOffParams_)
    :payOffParams(payOffParams_)
{}

PayOff* PayOffDoubleDigital::clone() const
{
    return new PayOffDoubleDigital(*this);
}

double PayOffDoubleDigital::operator()(double spot) const
{
    std::map<std::string, double>::const_iterator i = payOffParams.find("lowerStrike");
    double lowerStrike = i->second;
    std::map<std::string, double>::const_iterator j = payOffParams.find("upperStrike");
    double upperStrike = j->second;
    return (spot >= lowerStrike && spot <= upperStrike)? 1.0 : 0.0;
}