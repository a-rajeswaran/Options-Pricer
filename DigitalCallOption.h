#pragma once
#ifndef DIGITALCALLOPTION_H
#define DIGITALCALLOPTION_H
#include "DigitalOption.h"

class DigitalCallOption :
    public DigitalOption
{
public:
	DigitalCallOption(double expiry, double strike);
	double payoff(double a) override;
	OptionType getOptionType() override;
};

#endif

