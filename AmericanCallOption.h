#pragma once
#include "AmericanOption.h"
class AmericanCallOption :
    public AmericanOption
{
public:
    double payoff(double a) override;

};

