#pragma once
#include "AsianOption.h"
#ifndef ASIANPUT_OPTION
#define ASIANPUT_OPTION
class AsianPutOption :
    public AsianOption
{
private:
    double _strike;

public:
    AsianPutOption(std::vector<double> timesteps, double strike);
    double getStrike();
    double payoff(double a) override;
};

#endif


