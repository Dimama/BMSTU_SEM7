#ifndef UNIFORMRANDOM_H
#define UNIFORMRANDOM_H

#include "baserandom.h"

class UniformRandom: public BaseRandom
{
public:
    UniformRandom(int _a, int _b): a(_a), b(_b) {}
    double Generate()
    {
        return Rand(a,b);
    }

private:
    double a;
    double b;
};

#endif // UNIFORMRANDOM_H
