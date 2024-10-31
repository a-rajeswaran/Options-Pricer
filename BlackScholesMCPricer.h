#pragma once
#ifndef BLACKSCHOLESMCPRICER_H
#define BLACKSCHOLESMCPRICER_H
#include "AsianOption.h"
#include "PutOption.h"
#include "CallOption.h"
#include "MT.h"
#include <math.h>
#include <typeinfo>
#include <stdexcept>
class BlackScholesMCPricer
{
private:
	Option* option;
	double S0;
	double r;
	double vol;
	int nb_paths;
	double _estimate;
	double sum;
	double sum_2;

public:
	BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);
	int getNbPaths() const ;
	void generate(int N);
	double operator()() const ;
	std::vector<double>  confidenceInterval() const;

};


#endif
