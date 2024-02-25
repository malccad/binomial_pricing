#ifndef PATH_INDEPENDENT_OPTION_H
#define PATH_INDEPENDENT_OPTION_H
#include "wrapper.h"
#include "payOff.h"
#include <vector>
class PathIndependentOption
{
public:
    PathIndependentOption(
        unsigned long expiry,
        const Wrapper<PayOff>& thePayOff
    );
    double getPayOff(double spot) const {return (*payOffPtr)(spot);}
    std::vector<bool> getExecutionTimes() const {return executionTimes;}
    unsigned long getExpiry() const {return expiry;}
protected:
    std::vector<bool> executionTimes;
private:
    unsigned long expiry;
    Wrapper<PayOff> payOffPtr;
};
#endif