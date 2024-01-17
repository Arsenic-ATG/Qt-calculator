// do not try to play with comments
#ifndef UNARY_OPERATION_HANDLER_H
#define UNARY_OPERATION_HANDLER_H
#define FACTORIAL_INFINITY 15000
#define RAD 57.2957795
#define PI 3.14159265358979323
#define GRAD 63.661977237
#include<string>
#include<QString>
#include "ui_mainwindow.h"
class Unary_operation_handler
{
public:
    Unary_operation_handler();
    void Unary_operation_triggered(QPushButton* button,Ui::MainWindow * ui);
private:
    static double factorial(int labelnumber);
};

#endif // UNARY_OPERATION_HANDLER_H
