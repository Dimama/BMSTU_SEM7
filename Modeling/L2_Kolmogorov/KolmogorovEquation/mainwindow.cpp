#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    unsigned count = ui->spinBox_count->value();
    this->set_row_columns(count);
    ui->lineEdit->setText("Ввод элементов в формате: целая часть[.дробная часть]");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_table_clicked()
{
    unsigned count = ui->spinBox_count->value();
    this->set_row_columns(count);
}

void MainWindow::set_row_columns(unsigned count)
{
    ui->table->setRowCount(count);
    ui->table->setColumnCount(count);
    unsigned h = ui->table->height() / (count+1) * 0.9;
    unsigned w = ui->table->width() / count * 0.9;

    for(unsigned i = 0; i < count; i++)
    {
        ui->table->setRowHeight(i, h);
        ui->table->setColumnWidth(i, w);

    }

}

int MainWindow::get_matrix(std::vector<std::vector<double>>& matrix)
{

    unsigned count = ui->table->columnCount();

    for(std::vector<double> v: matrix)
    {
        v.clear();
    }
    matrix.clear();


    for(unsigned i = 0; i < count; i++)
    {
        std::vector<double> v;
        matrix.push_back(v);
        for(unsigned j = 0; j < count; j++)
        {
            double num;
            try
            {
                QTableWidgetItem *item = ui->table->item(i,j);
                if(!item)
                {
                    num = 0.0;
                    QTableWidgetItem* item = new QTableWidgetItem();
                    ui->table->setItem(i, j, item);
                }
                else
                {
                    num = item->text().toDouble();
                }

                if(num < 0)
                    return -2;

                ui->table->item(i,j)->setText(QString().setNum(num));

                qDebug() << num;

            }
            catch(std::exception& e)
            {
                qDebug() << e.what();
                return -1;
            }

             matrix[i].push_back(num);
        }
    }
    return 1;
}

void MainWindow::on_btn_clear_clicked()
{
    ui->table->clearContents();

}

void MainWindow::on_btn_calculate_clicked()
{

    std::vector<std::vector<double>> matrix;

    QMessageBox msg;
    int res = get_matrix(matrix);
    if(res < 0)
    {
        msg.setWindowTitle("Ошибка!");
        if (res == -1)
            msg.setText("Ошибка обработки элементов матрицы!");
        else if (res == -2)
            msg.setText("Элменты матрицы не могут быть отрицательными числами!");

    }
    else
    {
        QString str;
        std::vector<double> times;
        int res = Solution::SolveSystem(matrix, times);
        if(res < 0)
        {
            msg.setWindowTitle("Ошибка!");
            str = "Ошибка при решении матрицы!";
        }
        else
        {
            msg.setWindowTitle("Результат");
            for(unsigned i = 0; i < times.size(); i++)
                str += "t" + QString::number(i+1)+":  " + QString::number(times[i]) + "\n";
        }
        msg.setText(str);
    }
    msg.exec();


}
