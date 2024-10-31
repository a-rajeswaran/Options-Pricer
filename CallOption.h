#pragma once
#include "VanillaOption.h"
#ifndef CALLOPTION_H
#define CALLOPTION_H

class CallOption:public VanillaOption
{public:
	CallOption(double expiry, double strike);
	//~CallOption();
	double payoff(double a) override;
	OptionType getOptionType() override;
};

#endif

