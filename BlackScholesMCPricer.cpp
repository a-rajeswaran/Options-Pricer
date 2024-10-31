#include "BlackScholesMCPricer.h"

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
{
	this->option = option;
	this->S0 = initial_price;
	this->r = interest_rate;
	this->vol = volatility;
	this->nb_paths = 0;
	this->_estimate = -1;
	this->sum = 0;
	this->sum_2 = 0;
}

int BlackScholesMCPricer::getNbPaths() const
{
	return nb_paths;
}

void BlackScholesMCPricer::generate(int N)
{
	if (N<=0)
	{
		throw std::invalid_argument("Number of paths must be strictly positive");
	}
	if (nb_paths == 0)
	{
		_estimate = 0;

	}
	double s = 0;
	double expiry = 0;
	if (typeid(*option) == typeid(PutOption) || typeid(*option) == typeid(CallOption))
	{
		expiry = option->getExpiry();
		for (int i = 0; i < N; i++)
		{
			double Z = MT::rand_norm();
			double S = S0 * exp((r - vol * vol / 2) * expiry + vol * sqrt(expiry) * Z);
			double prix_option = option->payoff(S);
			sum = sum + prix_option;
			sum_2 = sum_2 + prix_option*prix_option;
			s = s + prix_option;

		}
		
		
		
	}
	else
	{
		std::vector<double> T = option->getTimeStep();
		expiry = T.back();
		for (int i = 0; i < N; i++)
		{
			std::vector<double> prix = { S0 };
			for (int j = 1; j < T.size(); j++)
			{
				double Z = MT::rand_norm();
				double delta_T = T[i] - T[i - 1];
				double S = prix.back() * exp((r - vol * vol / 2) * delta_T + vol * sqrt(delta_T) * Z);
				prix.push_back(S);
			}
			double prix_option = option->payoffPath(prix);
			s = s + prix_option;
			sum = sum = prix_option;
			sum_2 = sum_2 + prix_option * prix_option;
		}
		std::cout << "asian";
	}
	s = s / N;
	if (nb_paths = !0)
	{
		s = (_estimate * nb_paths) / (nb_paths + N) + (s * N) / (nb_paths + N);
	}
	nb_paths = nb_paths + N;
	this->_estimate = s*exp(-r*expiry);
}

double BlackScholesMCPricer::operator()() const
{
	if (nb_paths == 0)
	{
		throw std::invalid_argument("No estimate calculated yet");
	}
	else
	{
		return _estimate;
	}
}

std::vector<double>  BlackScholesMCPricer::confidenceInterval() const
{
	double Var = (sum_2 + 2 * sum * sum_2 + nb_paths * sum_2) / nb_paths;
	double sigma = sqrt(Var);
	double q = 1.96 * sigma / sqrt(nb_paths);
	std::vector<double> interval = { _estimate - q, _estimate + q };
	return interval;
}
