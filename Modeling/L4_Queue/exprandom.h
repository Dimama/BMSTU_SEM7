#ifndef EXPRANDOM_H
#define EXPRANDOM_H

#include "baserandom.h"
#include <math.h>

class ExpRandom: public BaseRandom
{
public:
    ExpRandom(double _lambda): lambda(_lambda) {}

    double Generate()
    {
        return log(1 - Rand(0,1))/(-lambda);
    }

private:
    double lambda;
};

#endif // EXPRANDOM_H
