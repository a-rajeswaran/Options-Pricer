
#include <iostream>
#include <vector>

#include "BlackScholesPricer.h"
#include "BinaryTree.cpp"
#include "AsianCallOPtion.h"
#include "AsianPutOption.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "BlackScholesMCPricer.h"
#include "CRRPricer.h"

double BSapprox(VanillaOption* option, double asset_price, double interest_rate, double volatility, int N, double S0)
{
	double h = option->getExpiry() / N;
	double U = -1+exp((interest_rate + (volatility * volatility) / 2) * h + volatility * sqrt(h));
	double D = -1+exp((interest_rate + (volatility * volatility) / 2) * h - volatility * sqrt(h));
	double R = exp(interest_rate * h) - 1;
	CRRPricer pricer(option, N, S0, U, D, R);
	return pricer();



}



int main()
{
	//CallOption option2(0.5, 40);
	//CallOption* p = &option2;
	//BlackScholesPricer pricer2(p, 42, 0.1, 0.2);
	//BlackScholesMCPricer pricer2(p, 42, 0.1, 0.2);
	//pricer2.generate(1000);
	//std::cout << pricer2();
	

	//std::vector<double> temps = { 0.1,0.2,0.3,0.4,0.5 };


	


	

	/*std::vector<double> S = {50,50,50};
	std::vector<double> T = { 1,2,3 };
	AsianPutOption c1(T, 60);
	std::cout << "Random number from U([0,1]): " << MT::rand_unif() << std::endl;
	std::cout << "Random number from N(0,1): " << MT::rand_norm() << std::endl;
	*/

	BinaryTree<int> binaryTree(3);

	binaryTree.setDepth(3); // Set depth to 3

	// Set values in the binary tree
	binaryTree.setNode(0, 0, 1);
	

	// Display the binary tree
	binaryTree.display();

	return 0;





}




