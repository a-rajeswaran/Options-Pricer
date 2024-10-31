#include "DigitalOption.h"
#include <stdexcept>

DigitalOption::DigitalOption(double const expiry, double const strike) :Option(expiry)
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

double DigitalOption::getStrike()
{
	return _strike;
}
