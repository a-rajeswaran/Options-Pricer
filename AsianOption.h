#pragma once
#include "Option.h"
#ifndef ASIANOPTION_H
#define ASIANOPTION_H
#include <vector>
#include <iostream>
class AsianOption :
    public Option
{
private:
    std::vector<double> timesteps;

public:
    AsianOption(std::vector<double> timesteps);
    std::vector<double> getTimeStep();
    double payoffPath(std::vector<double> liste_S) override;
    bool isAsianOption() override;
};

#endif

