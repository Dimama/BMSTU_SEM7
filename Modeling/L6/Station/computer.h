#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include "random.h"

class Computer : public QObject
{
    Q_OBJECT
public slots:
    void get_client();

public:
    Computer(double t1, double t2);
    void process();
    unsigned get_queue_size();
    unsigned get_success_count();

protected:
    unsigned queue_size;
    unsigned success_count;
    double min_time;
    double max_time;
    double time;

};

class Automate: public Computer
{
Q_OBJECT
signals:
    void to_window();

public:
    Automate(double t1, double t2, double _chance): Computer(t1, t2), chance(_chance), to_window_count(0){}
    void process();
    unsigned get_to_window_count();

private:
    double chance;
    unsigned to_window_count;

};

class Window: public Computer
{
Q_OBJECT
public:
    Window(double t1, double t2): Computer(t1, t2) {}
    void process();

};

#endif // COMPUTER_H
