#ifndef BASERANDOM_H
#define BASERANDOM_H

#include <stdlib.h>
#include <time.h>
#include <random>
#include <chrono>

class BaseRandom
{
protected:

    double Rand(double min, double max)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::uniform_real_distribution<double> unif(min,max);
        std::default_random_engine re(seed);
        return unif(re);
    }
};

#endif // BASERANDOM_H
