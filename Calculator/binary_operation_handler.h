#ifndef BINARY_OPERATION_HANDLER_H
#define BINARY_OPERATION_HANDLER_H
#include<string>
#include<QString>
#include<iostream>
#include "ui_mainwindow.h"
using namespace std;
class Binary_Operation_Handler
{
public:
    Binary_Operation_Handler();
    void Binary_operation_pressed(Ui::MainWindow * ui,QPushButton* button);
    double answer=0;
    QString arithmetic_expression;
private:


};

#endif // BINARY_OPERATION_HANDLER_H
