#ifndef CLIENTS_H
#define CLIENTS_H

#include "random.h"
#include <QObject>

class Clients: public QObject
{
    Q_OBJECT
signals:
    void new_client();
    void new_client_to_window();

public:
    Clients(double t1, double t2, double chance);
    void process();
    unsigned get_count();
    unsigned get_count_to_window();

private:
    unsigned count;
    unsigned count_to_window;
    double min_time;
    double max_time;
    double time;
    double chance;

};

#endif // CLIENTS_H
