#pragma once
#ifndef MT_H
#define MT_H
#include <random>
#include <ctime>
class MT
{
public:
    static MT& getInstance();
    static double rand_unif();
    static double rand_norm();

private:
    MT();
    double uniformDistribution(std::mt19937& gen);
    double normalDistribution(std::mt19937& gen);

    static std::mt19937 generator;
};

#endif

