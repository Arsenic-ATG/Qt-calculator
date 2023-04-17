#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>
#include <QDebug>
#include <iostream>
#define FACTORIAL_INFINITY 15000
#define RAD 57.2957795
#define PI 3.14159265358979323
#define GRAD 63.661977237
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    Ui::MainWindow *ui;


private slots:

    double factorial(int labelnumber);
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

public:
    void connect_buttons(Ui::MainWindow * ui,MainWindow * window);
    void connect_digits(Ui::MainWindow * ui,MainWindow * window);
    //void MainWindow::connect_buttons(Ui::MainWindow * ui,MainWindow * window);
    void connect_unary(Ui::MainWindow * ui,MainWindow * window);
    void connect_binary(Ui::MainWindow * ui,MainWindow * window);
    void connect_special_digits(Ui::MainWindow * ui,MainWindow * window);
};
#endif // MAINWINDOW_H
