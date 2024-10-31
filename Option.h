
#ifndef OPTION_H
#define OPTION_H
#include <vector>



class Option
{

private:
	double _expiry;

public:
	Option(double exp);
	//~Option();
	double getExpiry();
	virtual double payoff(double a) = 0;
	virtual double payoffPath(std::vector<double> liste_S);
	virtual bool isAsianOption();
	virtual std::vector<double> getTimeStep();
	virtual bool isAmericanOption();



};

#endif

