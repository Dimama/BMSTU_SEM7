#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vector>
#include <data.h>
#include <QTableWidget>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_calculate_clicked();
    void fill_table_column(const vector<int>& nums, QTableWidget* tbl, unsigned column);

private:
    Ui::MainWindow *ui;
    Data dt;

};

#endif // MAINWINDOW_H
