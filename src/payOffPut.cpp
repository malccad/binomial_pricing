#include "../include/payOffPut.h"
PayOffPut::PayOffPut(std::map<std::string, double> payOffParams_)
    :payOffParams(payOffParams_)
{}

PayOff* PayOffPut::clone() const
{
    return new PayOffPut(*this);
}

double PayOffPut::operator()(double spot) const
{
    std::map<std::string, double>::const_iterator i = payOffParams.find("strike");
    double strike = i->second;
    return (spot > strike)? 0.0 : strike-spot;
}