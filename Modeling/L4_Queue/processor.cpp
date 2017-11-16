#include "processor.h"
#include "exprandom.h"
#include "baserandom.h"
#include "QDebug"

int Processor::GetMaxQueueSize()
{
    return this->maxqueuesize;
}

int Processor::GetProcessedRequests()
{
    return this->requests;
}

int Processor::GetQueueSize()
{
    return this->queuesize;
}

double Processor::NextProcPeriod()
{
    return rnd.Generate();
}

void Processor::Recieve()
{
    this->queuesize++;
    this->requests++;
    if (this->queuesize > this->maxqueuesize)
    {
        qDebug() << "++";
        this->maxqueuesize++;
    }
}

void Processor::Process(double back)
{
    if (this->queuesize > 0)
    {
        queuesize--;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::uniform_real_distribution<double> unif(0,1);
        std::default_random_engine re(seed);
        double rnd = unif(re);
        if(rnd <= back)
        {
            qDebug() << "back with rand: " << rnd;
            this->Recieve();
        }
    }
}
