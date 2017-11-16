#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "exprandom.h"

class Processor
{
public:
    Processor(const ExpRandom& _rnd) : rnd(_rnd),
                                        requests(0),
                                        maxqueuesize(0),
                                        queuesize(0) {}
    int GetMaxQueueSize();
    int GetProcessedRequests();
    int GetQueueSize();
    double NextProcPeriod();
    void Recieve();
    void Process(double back);

private:
    ExpRandom rnd;
    int requests;
    int maxqueuesize;
    int queuesize;
};

#endif // PROCESSOR_H
