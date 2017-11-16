#ifndef MODELING_H
#define MODELING_H

#include "processor.h"
#include "generator.h"

class Modeling
{
public:
    static int MethodDeltaT(Generator& gen, Processor& proc, int count, double back, double dt);
    static int MethodEvent(Generator& gen, Processor& proc, int count, double back);
};

#endif // MODELING_H
