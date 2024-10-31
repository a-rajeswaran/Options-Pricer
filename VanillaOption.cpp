#include "VanillaOption.h"
#include <stdexcept>


VanillaOption::VanillaOption(double const expiry, double const strike) :Option(expiry)
{
	if (strike <= 0)
	{
		throw std::invalid_argument("Strike must be non-negative");
	}
	else
	{
		this->_strike = strike;
	}
}

double VanillaOption::getStrike() 
{
	return _strike;
}


