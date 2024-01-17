// do not try to play with comments
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>
#include <QDebug>
#include <iostream>
#include <binary_operation_handler.h>
#include<unary_operation_handler.h>
#include<equals_handler.h>
#include<unitconvertormainwindow.h>//unit convertor window
#include<nameconvertormainwindow.h>// Name Convertor window
#include<currencyconvertermainwindow.h> // Currency Convertor Window
#include<convertcm.h>
#define FACTORIAL_INFINITY 15000
#define RAD 57.2957795
#define PI 3.14159265358979323
#define GRAD 63.661977237
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Binary_Operation_Handler binary_handler;
    Unary_operation_handler unary_handler;
    Equals_handler equal_handler;

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    UnitConvertorMainWindow * ppage2=NULL;// ADDRESS OF WINDOW UNIT CONVERTOR
    nameconvertorMainWindow * ppage3=NULL;// ADDRESS OF WINDOW NAME CONVERTOR
    CurrencyConverterMainWindow * ppage4=NULL; // ADDRESS OF WINDOW Currency CONVERTOR

    const QStringList unary_buttonNames = {"pushButton_plusMinus", "pushButton_percent", "pushButton_Log",
                                          "pushButton_Sqrt", "pushButton_Factorial", "pushButton_exponent",
                                          "pushButton_sigmoid", "pushButton_sin", "pushButton_cos", "pushButton_pi"};
    const QStringList binary_buttonNames={"pushButton_multiply",
                                          "pushButton_add","pushButton_minus","pushButton_divide", "pushButton_Power","pushButton_mod"};
public:
    QScopedPointer<Ui::MainWindow> ui;

private slots:

//    double factorial(int labelnumber);
    void digit_pressed();
    void special_number_pressed();
    void on_pushButton_dot_released();
    void unary_operation_pressed();
    void on_pushButton_clear_released();
    void on_pushButton_equals_released();
    void binary_operation_pressed();
    void on_actionExit_triggered();
    void on_actionDark_triggered();
    void on_actionLight_triggered();
    void on_actionCyan_triggered();
    void on_actiontheme_1_triggered();
    void on_actiontheme_2_triggered();
    void on_actiontheme_3_triggered();
    void on_actiontheme_4_triggered();

public:
    void connect_buttons(Ui::MainWindow * ui,MainWindow * window);
    void connect_digits(MainWindow * window);
    //void MainWindow::connect_buttons(Ui::MainWindow * ui,MainWindow * window);
    void connect_unary(Ui::MainWindow * ui,MainWindow * window);
    void connect_binary(Ui::MainWindow * ui,MainWindow * window);
    void connect_special_digits(Ui::MainWindow * ui,MainWindow * window);
};
#endif // MAINWINDOW_H
