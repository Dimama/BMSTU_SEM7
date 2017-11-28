#include "modeling.h"

Modeling::Modeling(Clients* _clients, std::vector<Automate*>& _autos, Window* _window, double _time)
{
    this->clients = _clients;
    this->autos = _autos;
    this->window = _window;
    this->time = _time;

    QObject::connect(clients, SIGNAL(new_client()), this, SLOT(get_client()));
    QObject::connect(clients, SIGNAL(new_client_to_window()), window, SLOT(get_client()));
    for(Automate* a: autos)
        QObject::connect(a, SIGNAL(to_window()), window, SLOT(get_client()));

}

void Modeling::process()
{
    while (time > 0)
    {
        time -= STEP;

        clients->process();
        for(Automate* a: autos)
        {
            a->process();
        }
        window->process();
    }
}

unsigned Modeling::get_success_count()
{
    unsigned count = window->get_success_count();
    for(Automate *a: autos)
    {
        count += a->get_success_count();
    }
    return count;
}

unsigned Modeling::get_queue_size()
{
    unsigned count = window->get_queue_size();
    for(Automate *a: autos)
    {
        count += a->get_queue_size();
    }
    return count;
}

unsigned Modeling::get_to_window_count_from_automates()
{
    unsigned count = 0;
    for(Automate *a: autos)
    {
        count += a->get_to_window_count();
    }
    return count;
}

unsigned Modeling::get_to_window_count()
{
    return clients->get_count_to_window();
}

void Modeling::get_client()
{
    unsigned min_size = window->get_queue_size();
    int comp = -1;
    unsigned size;
    for(int i = 0; i < 4; i++)
    {
        size = autos[i]->get_queue_size();
        if(size < min_size)
        {
            min_size = size;
            comp = i;
        }
    }

    if(comp == -1)
    {
        window->get_client();
    }
    else
    {
        autos[comp]->get_client();
    }


}
