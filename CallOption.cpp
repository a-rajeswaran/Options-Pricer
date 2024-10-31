#include "CallOption.h"

CallOption::CallOption(double const expiry, double const strike):VanillaOption(expiry, strike){}

double CallOption::payoff(double const a) 
{
	if (a - getStrike() < 0)
	{
		return 0;
	}
	else
	{
		return a - getStrike();
	}
}

OptionType CallOption::getOptionType() 
{
	return OptionType::call;
}
