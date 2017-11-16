#include "modeling.h"

#include "QDebug"

int Modeling::MethodDeltaT(Generator &gen, Processor &proc, int count, double back, double dt)
{
    double gen_next = gen.GenNextPeriod();
    qDebug() << "gen_next: " << gen_next;
    double pr_next = gen_next + proc.NextProcPeriod();

    for(double cur_time = 0; count > 0; cur_time += dt)
    {
        qDebug() << "cur time: " << cur_time;
        if (gen_next <= cur_time)
        {
            proc.Recieve();
            gen_next += gen.GenNextPeriod();
            qDebug() << "gen_next: " << gen_next;
            count--;
        }
        qDebug() << "pr_next" << pr_next;
        if (cur_time >= pr_next)
        {
            if(proc.GetQueueSize() > 0)
            {
                proc.Process(back);
            }
            if(proc.GetQueueSize() > 0)
            {
                pr_next += proc.NextProcPeriod();
            }
            else
            {
                pr_next = gen_next + proc.NextProcPeriod();
            }

        }
    }
    return proc.GetMaxQueueSize();
}

int Modeling::MethodEvent(Generator &gen, Processor &proc, int count, double back)
{
    double gen_next = gen.GenNextPeriod();
    double pr_next = gen_next + proc.NextProcPeriod();

    while (count > 0)
    {
        if (gen_next <= pr_next)
        {
            proc.Recieve();
            gen_next += gen.GenNextPeriod();
            count--;
        }
        if (gen_next >= pr_next)
        {
            if(proc.GetQueueSize() > 0)
            {
                proc.Process(back);
            }
            if(proc.GetQueueSize() > 0)
            {
                pr_next += proc.NextProcPeriod();
            }
            else
            {
                pr_next = gen_next + proc.NextProcPeriod();
            }
        }
    }
    return proc.GetMaxQueueSize();
}
