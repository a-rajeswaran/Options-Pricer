#pragma once
#ifndef CRRPRICER_H
#define CRRPRICER_H

#include "VanillaOption.h"
#include "BlackScholesPricer.h"
#include "BinaryTree.cpp"
class CRRPricer
{
private:
    Option* option;
    int depth;
    double asset_price;
    double up;
    double down;
    double interest_rate; //R dans l'énoncé


public:
    CRRPricer(Option* option, int N, double asset_price, double U, double D, double rate);
    void compute();
    void myPriceTree(); //shows the asset price tree (not the option)
    void myOptionPriceTree(); //shows the option price tree 
    double get(int n, int i) const; //returns H(n,i)
    double operator()(bool closed_form = false) const;

};

#endif

