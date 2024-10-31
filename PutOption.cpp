#include "PutOption.h"

PutOption::PutOption(double const expiry, double const strike) :VanillaOption(expiry, strike) {}

double PutOption::payoff(double const a)
{
	if (getStrike() - a > 0)
	{
		return getStrike() - a ;
	}
	else
	{
		return 0;
	}
}

OptionType PutOption::getOptionType()
{
	return OptionType::put;
}
