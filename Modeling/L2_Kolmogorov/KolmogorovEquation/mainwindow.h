#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <solution.h>
#include <exception>
#include <QMessageBox>
#include <QDebug>

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
    void on_btn_table_clicked();

    void on_btn_clear_clicked();

    void on_btn_calculate_clicked();

    void on_btn_clearRes_clicked();

private:
    Ui::MainWindow *ui;
    void set_row_columns(unsigned count);
    int get_matrix(std::vector<std::vector<double>>& matrix);
};

#endif // MAINWINDOW_H
