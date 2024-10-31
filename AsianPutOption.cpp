#include "AsianPutOption.h"

AsianPutOption::AsianPutOption(std::vector<double> timesteps, double strike) :AsianOption(timesteps), _strike(strike) {}

double AsianPutOption::getStrike()
{
	return _strike;
}

double AsianPutOption::payoff(double a)
{
	if (getStrike() - a > 0)
	{
		return getStrike() - a;
	}
	else
	{
		return 0;
	}
}
