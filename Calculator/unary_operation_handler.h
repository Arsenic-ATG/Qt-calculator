#ifndef UNARY_OPERATION_HANDLER_H
#define UNARY_OPERATION_HANDLER_H

#include<string>
#include<QString>
#include<mainwindow.h>
#include "ui_mainwindow.h"
class Unary_operation_handler
{
public:
    Unary_operation_handler();
    static double Unary_operation_triggered(QString symbol ,double firstNum, double secondNum,Ui::MainWindow *ui);

};

#endif // UNARY_OPERATION_HANDLER_H
