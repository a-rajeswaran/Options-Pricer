#pragma once
#include "VanillaOption.h"
#include"CallOption.h"
#include"PutOption.h"

#ifndef BLACKSCHOLESPRICER_H
#define BLACKSCHOLESPRICER_H


class BlackScholesPricer
{
public:
	BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility);

	//~BlackScholesPricer();
	double operator()() const;
	double delta() const;

private:
	VanillaOption* option;
	double asset_price;
	double interest_rate;
	double volatility;


};

#endif

