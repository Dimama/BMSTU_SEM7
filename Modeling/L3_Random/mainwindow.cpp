#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

static unsigned row_count = 10;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tb1->setRowCount(row_count);
    ui->tb2->setRowCount(row_count);

    dt.read_numbers_from_file("new_digits.txt");
    dt.generate_numbers(1000);

    fill_table_column(dt.alg1, ui->tb1, 0);
    fill_table_column(dt.alg2, ui->tb1, 1);
    fill_table_column(dt.alg3, ui->tb1, 2);
    fill_table_column(dt.tbl1, ui->tb2, 0);
    fill_table_column(dt.tbl2, ui->tb2, 1);
    fill_table_column(dt.tbl3, ui->tb2, 2);

    double alg1_res = dt.calculate_entr(dt.alg1);
    double alg2_res = dt.calculate_entr(dt.alg2);
    double alg3_res = dt.calculate_entr(dt.alg3);

    double tbl1_res = dt.calculate_entr(dt.tbl1);
    double tbl2_res = dt.calculate_entr(dt.tbl2);
    double tbl3_res = dt.calculate_entr(dt.tbl3);

    ui->lbl_alg->setText("Результат: " + QString::number(alg1_res ,'f', 2) + " | "
                                        + QString::number(alg2_res ,'f', 2) + " | "
                                        + QString::number(alg3_res ,'f', 2));

    ui->lbl_tbl->setText("Результат: " + QString::number(tbl1_res ,'f', 2) + " | "
                                        + QString::number(tbl2_res ,'f', 2) + " | "
                                        + QString::number(tbl3_res ,'f', 2));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_calculate_clicked()
{
    if (!ui->lineEdit->text().isEmpty())
    {
        this->dt.read_sequence(ui->lineEdit->text().trimmed());
        double res = dt.calculate_entr(dt.sequence);
        ui->lbl_seq->setText("Результат: " + QString::number(res ,'f', 2));
    }
}

void MainWindow::fill_table_column(const vector<int> &nums, QTableWidget *tbl, unsigned column)
{
    unsigned step = nums.size() / row_count;
    qDebug() << nums.size();
    for(unsigned i = 0; i < row_count; i++)
    {
        QTableWidgetItem *item = tbl->item(i, column);
        if(!item)
        {
            item = new QTableWidgetItem();
            tbl->setItem(i, column, item);
        }
        item->setText(QString().setNum(nums[i*step]));

    }
}

