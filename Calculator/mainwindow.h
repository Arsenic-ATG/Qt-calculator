#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "theme.h"
#include <QMainWindow>
#include <math.h>
#include <QDebug>
#include <binary_operation_handler.h>
#include<unary_operation_handler.h>
#include<equals_handler.h>
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
    const QStringList unary_buttonNames = {"pushButton_plusMinus", "pushButton_percent", "pushButton_Log",
                                          "pushButton_Sqrt", "pushButton_Factorial", "pushButton_exponent",
                                          "pushButton_sigmoid", "pushButton_sin", "pushButton_cos", "pushButton_pi"};
    const QStringList binary_buttonNames={"pushButton_multiply",
                                          "pushButton_add","pushButton_minus","pushButton_divide", "pushButton_Power","pushButton_squared"};
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
    void on_actiontheme_1_triggered();
    void on_actiontheme_2_triggered();

public:
    void connect_buttons(Ui::MainWindow * ui,MainWindow * window);
    void connect_digits(MainWindow * window);
    void connect_unary(MainWindow * window);
    void connect_binary(MainWindow * window);
    void connect_special_digits(Ui::MainWindow * ui,MainWindow * window);

    void applyTheme(const Theme &theme);

    std::vector<QPushButton*> digitButtons;
    QComboBox *comboBox;
    QWidget *centralwidget;
    QWidget *verticalWidget;
    QLabel *label;
    QLabel *label_2;
};
#endif // MAINWINDOW_H
