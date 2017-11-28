#include "clients.h"

Clients::Clients(double t1, double t2, double chance)
{
    this->min_time = t1;
    this->max_time = t2;
    this->chance = chance;
    this->count = 0;
    this->count_to_window = 0;
    this->time = 0;
}

void Clients::process()
{
    if (time <= 0)
    {
        time = randomGen(min_time, max_time);
        count++;

        double rnd = randomGen(0, 1);
        if (rnd <= chance)
        {
            emit new_client_to_window();
            count_to_window++;
        }
        else
        {
            emit new_client();
        }
    }
    else
    {
        time -= STEP;
    }
}

unsigned Clients::get_count()
{
    return count;
}

unsigned Clients::get_count_to_window()
{
    return count_to_window;
}

