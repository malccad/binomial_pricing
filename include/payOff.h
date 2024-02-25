#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{
public:
    PayOff(){};

    virtual PayOff* clone() const=0;
    virtual ~PayOff(){};

    virtual double operator()(double spot) const=0;
private:
};
#endif