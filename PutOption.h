#pragma once
#include "VanillaOption.h"
#ifndef PUTOPTION_H
#define PUTOPTION_H
class PutOption:public VanillaOption
{
public:
	PutOption(double expiry, double strike);
	//~PutOption();
	double payoff(double a) override;
	OptionType getOptionType() override;
};

#endif

