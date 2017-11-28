#include "computer.h"

Computer::Computer(double t1, double t2)
{
    this->min_time = t1;
    this->max_time = t2;
    this->queue_size = 0;
    this->success_count = 0;
    this->time = 0;
}

unsigned Computer::get_queue_size()
{
    return queue_size;
}

unsigned Computer::get_success_count()
{
    return success_count;
}

/* --------------------------------- ---------------------------------*/

void Computer::get_client()
{
    queue_size++;
}

void Window::process()
{
    if(queue_size > 0)
    {
        if(time <= 0)
        {
            time = randomGen(min_time, max_time);
        }

        time -= STEP;

        if(time <= 0)
        {
            queue_size--;
            success_count++;
        }
    }
}

void Automate::process()
{
    if(queue_size > 0)
    {
        if(time <= 0)
        {
            time = randomGen(min_time, max_time);
        }

        time -= STEP;

        if(time <= 0)
        {
            queue_size--;
            double rnd = randomGen(0, 1);
            if(rnd < chance)
            {
                to_window_count++;
                emit to_window();
            }
            else
            {
                success_count++;
            }
        }
    }
}

unsigned Automate::get_to_window_count()
{
    return to_window_count;
}
