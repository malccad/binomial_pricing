#ifndef PAYOFF_HELPER_H
#define PAYOFF_HELPER_H
#include "payOff.h"
#include "payOffCall.h"
#include "payOffPut.h"
#include "payOffDoubleDigital.h"
#include "payOffFactory.h"
#include "inputPayOffParams.h"
#include <string>
#include <map>

template <class T>
class PayOffHelper
{
public:
    typedef std::map<std::string, double> (*InputParamsFunction)();
    PayOffHelper(std::string, InputParamsFunction);
    static PayOff* create(std::map<std::string, double>);
};

template <class T>
PayOff* PayOffHelper<T>::create(std::map<std::string, double> payOffParams)
{
    return new T(payOffParams);
}

template <class T>
PayOffHelper<T>::PayOffHelper(std::string payOffId, InputParamsFunction input)
{
    PayOffFactory& thePayOffFactory = PayOffFactory::instance();
    thePayOffFactory.registerPayOff(payOffId, input, PayOffHelper<T>::create);
}
#endif