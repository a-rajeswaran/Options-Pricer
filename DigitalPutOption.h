#pragma once
#ifndef DIGITALPUTOPTION_H
#define DIGITALPUTOPTION_H
#include "DigitalOption.h"
class DigitalPutOption :
    public DigitalOption
{
public:
	DigitalPutOption(double expiry, double strike);
	double payoff(double a) override;
	OptionType getOptionType() override;

};

#endif

