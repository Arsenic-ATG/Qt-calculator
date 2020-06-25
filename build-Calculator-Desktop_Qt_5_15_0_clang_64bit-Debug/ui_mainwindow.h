/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_plusMinus;
    QPushButton *pushButton_percent;
    QPushButton *pushButton_divide;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_multiply;
    QPushButton *pushButton_1;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_add;
    QPushButton *pushButton_7;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_0;
    QPushButton *pushButton_equals;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(243, 361);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 241, 61));
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(0, 60, 61, 61));
        pushButton_plusMinus = new QPushButton(centralwidget);
        pushButton_plusMinus->setObjectName(QString::fromUtf8("pushButton_plusMinus"));
        pushButton_plusMinus->setGeometry(QRect(60, 60, 61, 61));
        pushButton_percent = new QPushButton(centralwidget);
        pushButton_percent->setObjectName(QString::fromUtf8("pushButton_percent"));
        pushButton_percent->setGeometry(QRect(120, 60, 61, 61));
        pushButton_divide = new QPushButton(centralwidget);
        pushButton_divide->setObjectName(QString::fromUtf8("pushButton_divide"));
        pushButton_divide->setGeometry(QRect(180, 60, 61, 61));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 120, 61, 61));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 120, 61, 61));
        pushButton_multiply = new QPushButton(centralwidget);
        pushButton_multiply->setObjectName(QString::fromUtf8("pushButton_multiply"));
        pushButton_multiply->setGeometry(QRect(180, 120, 61, 61));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(0, 120, 61, 61));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(120, 180, 61, 61));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(60, 180, 61, 61));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(180, 180, 61, 61));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 180, 61, 61));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(120, 240, 61, 61));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(60, 240, 61, 61));
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(180, 240, 61, 61));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(0, 240, 61, 61));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(120, 300, 61, 61));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(0, 300, 121, 61));
        pushButton_equals = new QPushButton(centralwidget);
        pushButton_equals->setObjectName(QString::fromUtf8("pushButton_equals"));
        pushButton_equals->setGeometry(QRect(180, 300, 61, 61));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_plusMinus->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_percent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_divide->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_multiply->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_equals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
