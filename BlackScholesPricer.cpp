
#include "BlackScholesPricer.h"
#include <cmath>
#include <random>
#include<iostream>
#include <typeinfo>

BlackScholesPricer::BlackScholesPricer(VanillaOption* option, double const asset_price, double const interest_rate, double const volatility):option(option), asset_price(asset_price), interest_rate(interest_rate), volatility(volatility){}




/*BlackScholesPricer::~BlackScholesPricer() {
	if (option) {
		delete option;
		
	}
}
*/

double BlackScholesPricer::operator()() const {

	const double S = asset_price;
	const double K = option->_strike;
	const double T = option->getExpiry();
	const double r = interest_rate;
	const double sigma = volatility;

	double d1 = (log(S / K) + (r + std::pow(sigma,2) / 2) * T) / (sigma * sqrt(T));
	double d2 = d1 - sigma * sqrt(T);

	if (option->getOptionType() == OptionType::call)
	{
		return S * 0.5 * (1 + std::erf(d1 / sqrt(2))) - K * exp(-r * T) * 0.5 * (1 + std::erf(d2 / sqrt(2)));
	}
	else 
	{
		return K * exp(-r * T) * 0.5 * (1 + std::erf(-d2 / sqrt(2))) - S * 0.5 * (1 + std::erf(-d1 / sqrt(2)));
	}


}


double BlackScholesPricer::delta() const {

	const double S = asset_price;
	const double K = option->_strike;
	const double T = option->getExpiry();
	const double r = interest_rate;
	const double sigma = volatility;

	double d1 = (log(S / K) + ( r + std::pow(sigma,2) / 2) * T) / (sigma * sqrt(T));

	if (option->getOptionType() == OptionType::call) {
		return std::erf(d1);
	}
	else {
		return (std::erf(d1) - 1);
	}
}