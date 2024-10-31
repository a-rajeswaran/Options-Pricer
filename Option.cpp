#include "Option.h"
#include <stdexcept>

Option::Option(double const exp)
{
	if(exp<=0)
	{
		throw std::invalid_argument("Expiry must be non-negative");
	}
	else
	{
		this->_expiry = exp;
	}
}

double Option::getExpiry() {
	return _expiry;
}

double Option::payoffPath(std::vector<double> liste_S)
{
	return liste_S.back();
}

bool Option::isAsianOption()
{
	return false;
}

std::vector<double> Option::getTimeStep()
{
	std::vector<double> expiry = { _expiry };
	return expiry;
}

bool Option::isAmericanOption()
{
	return false;
}
