#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <uniformrandom.h>
#include <exprandom.h>
#include <modeling.h>
#include <QDebug>

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

    UniformRandom ur(ui->dspb_a->value(), ui->dspb_b->value());
    ExpRandom er(ui->dbsp_lambda->value());
    Generator gen(ur);
    Processor proc(er);
    double back = double(ui->spb_back->value()) / 100;
    double dt = ui->dspb_dt->value();
    qDebug() << "BACK:" <<back;
    int count = ui->spb_count->value();
    qDebug() << count;
    int res;

    qDebug() << ur.Generate();
    qDebug() << er.Generate();

    if(ui->rb_deltat->isChecked())
    {
        res = Modeling::MethodDeltaT(gen, proc, count, back, dt);
    }
    else
    {
        res = Modeling::MethodEvent(gen, proc, count, back);
    }

    ui->statusBar->showMessage("Оптимальное число заявок: " + QString::number(res));
}
