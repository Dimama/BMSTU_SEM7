#ifndef GENERATOR_H
#define GENERATOR_H

#include "uniformrandom.h"

class Generator
{
public:
    Generator(const UniformRandom& _rnd): rnd(_rnd) {}

    double GenNextPeriod()
    {
        return rnd.Generate();
    }

private:
    UniformRandom rnd;
};

#endif // GENERATOR_H
