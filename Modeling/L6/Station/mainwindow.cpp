#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "modeling.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_model_clicked()
{
    double t1_client = ui->dspb_time_client->value();
    double t2_client = ui->dspb_time_client_2->value();

    double t1_auto = ui->dspb_time_auto->value();
    double t2_auto = ui->dspb_time_auto_2->value();

    double t1_window = ui->dspb_time_window->value();
    double t2_window = ui->dspb_time_window_2->value();

    double time = double(ui->spb_time->value());

    double chance_to_window = ui->dspb_chance_only_window->value();
    double chance_back_to_window = ui->dspb_chance_to_window->value();

    Clients* clients = new Clients(t1_client, t2_client, chance_to_window);
    std::vector<Automate*> autos;

    for(unsigned i = 0; i < 4; i++)
    {
        autos.push_back(new Automate(t1_auto, t2_auto, chance_back_to_window));
    }

    Window* window = new Window(t1_window, t2_window);

    Modeling model(clients, autos, window, time);

    model.process();

    ui->lbl_queue_all->setText("В очереди: " + QString::number(model.get_queue_size()));
    ui->lbl_queue_auto1->setText("В очереди: " + QString::number(autos[0]->get_queue_size()));
    ui->lbl_queue_auto2->setText("В очереди: " + QString::number(autos[1]->get_queue_size()));
    ui->lbl_queue_auto3->setText("В очереди: " + QString::number(autos[2]->get_queue_size()));
    ui->lbl_queue_auto4->setText("В очереди: " + QString::number(autos[3]->get_queue_size()));
    ui->lbl_queue_window->setText("В очереди: " + QString::number(window->get_queue_size()));

    ui->lbl_done_all->setText("Обслужено: " + QString::number(model.get_success_count()));
    ui->lbl_done_auto1->setText("Обслужено: " + QString::number(autos[0]->get_success_count()));
    ui->lbl_done_auto2->setText("Обслужено: " + QString::number(autos[1]->get_success_count()));
    ui->lbl_done_auto3->setText("Обслужено: " + QString::number(autos[2]->get_success_count()));
    ui->lbl_done_auto4->setText("Обслужено: " + QString::number(autos[3]->get_success_count()));
    ui->lbl_done_window->setText("Обслужено: " + QString::number(window->get_success_count()));

    ui->lbl_to_window_auto1->setText("Перешли в кассу: " + QString::number(autos[0]->get_to_window_count()));
    ui->lbl_to_window_auto2->setText("Перешли в кассу: " + QString::number(autos[1]->get_to_window_count()));
    ui->lbl_to_window_auto3->setText("Перешли в кассу: " + QString::number(autos[2]->get_to_window_count()));
    ui->lbl_to_window_auto4->setText("Перешли в кассу: " + QString::number(autos[3]->get_to_window_count()));
    ui->lbl_to_window_all->setText("Только в кассу: " + QString::number(model.get_to_window_count()));


    qDebug() << "\n----Электричка приехала---";
    qDebug() << "Стоит в очередях: "<< model.get_queue_size();
    qDebug() << "Успели на электричку: "<< model.get_success_count();
    qDebug() << "Пошли сразу в кассу: "<< model.get_to_window_count();
    qDebug() << "Пошли в кассу из автомата: "<< model.get_to_window_count_from_automates();

    delete clients;
    delete window;
    for(Automate* a: autos)
    {
        delete a;
    }
}
