#include "../include/payOffHelper.h"

namespace
{
    PayOffHelper<PayOffCall> RegisterCall("call", inputStrike);
    PayOffHelper<PayOffPut> RegisterPut("put", inputStrike);
    PayOffHelper<PayOffDoubleDigital> RegisterDoubleDigital("doubleDigital", inputDoubleDigital);
}