#include "AsianCallOption.h"

AsianCallOption::AsianCallOption(std::vector<double> timesteps,double strike):AsianOption(timesteps),_strike(strike){}

double AsianCallOption::getStrike()
{
	return _strike;
}

double AsianCallOption::payoff(double a)
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