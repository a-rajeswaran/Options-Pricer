#include "AsianOption.h"

AsianOption::AsianOption(std::vector<double> timesteps):Option(timesteps.back())
{
	this->timesteps = timesteps;

}

std::vector<double> AsianOption::getTimeStep()
{
	return timesteps;
}

double AsianOption::payoffPath(std::vector<double> liste_S)
{
	if (liste_S.empty())
	{
		std::cout << "Vecteur vide";
		return -1;
	}
	else
	{
		double moyenne = 0;
		int n = liste_S.size();
		for (int i = 0; i < n; i++)
		{
			moyenne = moyenne + liste_S[i];
		}
		moyenne=moyenne / n;
		return payoff(moyenne);
	}
}

bool AsianOption::isAsianOption()
{
	return true;
}