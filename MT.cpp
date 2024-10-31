#include "MT.h"

std::mt19937 MT::generator;

MT& MT::getInstance() 
{
    static MT instance;
    return instance;
}

MT::MT() 
{
    std::seed_seq seed{ static_cast<unsigned>(std::time(0)) };
    generator.seed(seed);
}

double MT::rand_unif() 
{
    return getInstance().uniformDistribution(generator);
}

double MT::rand_norm() 
{
    return getInstance().normalDistribution(generator);
}

double MT::uniformDistribution(std::mt19937& gen) 
{
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(gen);
}

double MT::normalDistribution(std::mt19937& gen) 
{
    std::normal_distribution<double> distribution(0.0, 1.0);
    return distribution(gen);
}
