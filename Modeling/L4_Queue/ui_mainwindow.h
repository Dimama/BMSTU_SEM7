/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QRadioButton *rb_event;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rb_deltat;
    QLabel *label_7;
    QDoubleSpinBox *dspb_dt;
    QGroupBox *groupBox_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *dspb_a;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *dspb_b;
    QGroupBox *groupBox_3;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDoubleSpinBox *dbsp_lambda;
    QGroupBox *groupBox_4;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *spb_back;
    QWidget *widget5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *spb_count;
    QGroupBox *groupBox_5;
    QLineEdit *le_res;
    QPushButton *btn_model;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(547, 187);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(3, 1, 211, 81));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        rb_event = new QRadioButton(groupBox);
        rb_event->setObjectName(QStringLiteral("rb_event"));
        rb_event->setGeometry(QRect(10, 50, 101, 17));
        rb_event->setFont(font);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 187, 27));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        rb_deltat = new QRadioButton(widget);
        rb_deltat->setObjectName(QStringLiteral("rb_deltat"));
        rb_deltat->setFont(font);
        rb_deltat->setChecked(true);

        horizontalLayout_4->addWidget(rb_deltat);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_4->addWidget(label_7);

        dspb_dt = new QDoubleSpinBox(widget);
        dspb_dt->setObjectName(QStringLiteral("dspb_dt"));
        dspb_dt->setValue(1);

        horizontalLayout_4->addWidget(dspb_dt);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(220, 1, 151, 81));
        groupBox_2->setFont(font);
        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(34, 18, 90, 27));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        dspb_a = new QDoubleSpinBox(widget1);
        dspb_a->setObjectName(QStringLiteral("dspb_a"));
        dspb_a->setFont(font);
        dspb_a->setValue(3);

        horizontalLayout_2->addWidget(dspb_a);

        widget2 = new QWidget(groupBox_2);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(34, 46, 90, 27));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        dspb_b = new QDoubleSpinBox(widget2);
        dspb_b->setObjectName(QStringLiteral("dspb_b"));
        dspb_b->setFont(font);
        dspb_b->setValue(15);

        horizontalLayout_3->addWidget(dspb_b);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(220, 80, 151, 81));
        groupBox_3->setFont(font);
        widget3 = new QWidget(groupBox_3);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(14, 31, 131, 27));
        horizontalLayout = new QHBoxLayout(widget3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        dbsp_lambda = new QDoubleSpinBox(widget3);
        dbsp_lambda->setObjectName(QStringLiteral("dbsp_lambda"));
        dbsp_lambda->setFont(font);
        dbsp_lambda->setValue(9);

        horizontalLayout->addWidget(dbsp_lambda);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(4, 80, 211, 81));
        groupBox_4->setFont(font);
        widget4 = new QWidget(groupBox_4);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(10, 50, 191, 27));
        horizontalLayout_6 = new QHBoxLayout(widget4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        spb_back = new QSpinBox(widget4);
        spb_back->setObjectName(QStringLiteral("spb_back"));
        spb_back->setFont(font);
        spb_back->setMaximum(100);
        spb_back->setValue(0);

        horizontalLayout_6->addWidget(spb_back);

        widget5 = new QWidget(groupBox_4);
        widget5->setObjectName(QStringLiteral("widget5"));
        widget5->setGeometry(QRect(11, 21, 191, 25));
        horizontalLayout_5 = new QHBoxLayout(widget5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        spb_count = new QSpinBox(widget5);
        spb_count->setObjectName(QStringLiteral("spb_count"));
        spb_count->setFont(font);
        spb_count->setMinimum(1);
        spb_count->setMaximum(100000);
        spb_count->setValue(500);

        horizontalLayout_5->addWidget(spb_count);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 200, 191, 81));
        groupBox_5->setFont(font);
        le_res = new QLineEdit(groupBox_5);
        le_res->setObjectName(QStringLiteral("le_res"));
        le_res->setEnabled(false);
        le_res->setGeometry(QRect(20, 20, 161, 20));
        le_res->setFont(font);
        btn_model = new QPushButton(centralWidget);
        btn_model->setObjectName(QStringLiteral("btn_model"));
        btn_model->setGeometry(QRect(375, 9, 161, 151));
        QFont font1;
        font1.setPointSize(13);
        btn_model->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font2;
        font2.setFamily(QStringLiteral("Proxy 7"));
        font2.setPointSize(12);
        statusBar->setFont(font2);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lab 4", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\274\320\265\321\202\320\276\320\264\320\260", 0));
        rb_event->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\261\321\213\321\202\320\270\320\271\320\275\321\213\320\271", 0));
        rb_deltat->setText(QApplication::translate("MainWindow", "\320\224\320\265\320\273\321\214\321\202\320\260 t", 0));
        label_7->setText(QApplication::translate("MainWindow", "dt:", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\263\320\265\320\275\320\265\321\200\320\260\321\202\320\276\321\200\320\260", 0));
        label->setText(QApplication::translate("MainWindow", "a:", 0));
        label_2->setText(QApplication::translate("MainWindow", "b:", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\236\320\220", 0));
        label_3->setText(QApplication::translate("MainWindow", "lambda:", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\267\320\260\321\217\320\262\320\276\320\272", 0));
        label_6->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202 \320\262\320\276\320\267\320\262\321\200\320\260\321\202\320\260: ", 0));
        label_5->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\267\320\260\321\217\320\262\320\276\320\272:", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\236\320\277\321\202\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\273\320\270\320\275\320\260 \320\276\321\207\320\265\321\200\320\265\320\264\320\270", 0));
        btn_model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
