#pragma once
#ifndef DIGITALOPTION_H
#define DIGITALOPTION_H
#include "Option.h"

enum class OptionType
{
    call,
    put
};

class DigitalOption :
    public Option
{
private:
    double _strike;

public:
    DigitalOption(double _expiry, double _strike);
    virtual OptionType getOptionType() = 0;
    double getStrike();

};

#endif

