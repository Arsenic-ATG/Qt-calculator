#ifndef BINARY_OPERATION_HANDLER_H
#define BINARY_OPERATION_HANDLER_H
#include<string>
#include<QString>
#include "ui_mainwindow.h"
using namespace std;
class Binary_Operation_Handler
{
public:
    Binary_Operation_Handler();
    static double Binary_operation_triggered(QString symbol ,double firstNum, double secondNum,Ui::MainWindow *ui);

};

#endif // BINARY_OPERATION_HANDLER_H
