#pragma once
#include "Option.h"
#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H

enum class OptionType
{
    call,
    put
}; 

class VanillaOption :
    public Option
{
    friend class BlackScholesPricer;
private:
    double _strike;

public:
    VanillaOption(double expiry, double strike);
    //~VanillaOption();
    virtual OptionType getOptionType()= 0;
    double getStrike();
};



#endif 

