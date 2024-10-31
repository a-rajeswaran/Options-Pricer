#pragma once
#include "AsianOption.h"
#ifndef ASIANCALLOPTION_H
#define ASIANCALLOPTION_H
class AsianCallOption :
    public AsianOption
{
private:
    std::vector<double> timesteps;
    double _strike;

public:
    AsianCallOption(std::vector<double> timesteps, double strike);
    double getStrike();
    double payoff(double a) override;
};

#endif

