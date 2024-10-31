#include "DigitalCallOption.h"

DigitalCallOption::DigitalCallOption(double const expiry, double const strike) :VanillaOption(expiry, strike) {}

double DigitalCallOption::payoff(double const a)
{
	if (a - getStrike() < 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

OptionType DigitalCallOption::getOptionType()
{
	return OptionType::call;
}
