#include "DigitalPutOption.h"

DigitalPutOption::DigitalPutOption(double const expiry, double const strike) :VanillaOption(expiry, strike) {}

double DigitalPutOption::payoff(double const a)
{
	if (getStrike() - a >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

OptionType DigitalPutOption::getOptionType()
{
	return OptionType::put;
}
