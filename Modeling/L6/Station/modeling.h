#ifndef MODELING_H
#define MODELING_H

#include "clients.h"
#include "computer.h"
#include <vector>


class Modeling: public QObject
{
Q_OBJECT
private slots:
    void get_client();

public:
    Modeling(Clients* _clients, std::vector<Automate*>& _autos, Window* _window, double _time);
    void process();
    unsigned get_success_count();
    unsigned get_queue_size();
    unsigned get_to_window_count_from_automates();
    unsigned get_to_window_count();

private:
    Clients* clients;
    std::vector<Automate*> autos;
    Window* window;
    double time;

};

#endif // MODELING_H
