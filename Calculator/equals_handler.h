#ifndef EQUALS_HANDLER_H
#define EQUALS_HANDLER_H
#include "ui_mainwindow.h"

class Equals_handler
{
public:
    double answer=0;
    QString arithmetic_expression;
    Equals_handler();
    QString Equals_Button_triggered(double firstNum, double secondNum,Ui::MainWindow *ui);
};

#endif // EQUALS_HANDLER_H
