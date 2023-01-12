#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

double firstNum;
bool user_is_typing_secondNumber=false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
   // qDebug() << "test";
    QPushButton * button = (QPushButton *)sender();
    QString input;
    double labelnumber;

    if((ui->pushButton_add->isChecked() || ui->pushButton_divide->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked()) && (!user_is_typing_secondNumber))
    {
        user_is_typing_secondNumber=true;
        labelnumber = button->text().toDouble();
        input = QString::number(labelnumber,'g',15);
    }

    else
    {
        if(ui->label->text().contains(".") && button->text() == "0")
        {
            input=ui->label->text() + button->text();
        }
        else
        {
            labelnumber = (ui->label->text() + button->text()).toDouble();
            input = QString::number(labelnumber,'g',15);
        }
        //labelnumber = (ui->label->text() + button->text()).toDouble();
    }
    ui->label->setText(input);

}

void MainWindow::on_pushButton_dot_released()
{
    // check for appearance of decimal, exit function if there is one
         if(ui->label->text().contains(".")){

                 return;
         }
    ui->label->setText(ui->label->text() + ".");
    //check for extra decimal
}

void MainWindow::unary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    double labelnumber;
    QString input;

    if(button->text() == "+/-")
    {
        labelnumber = (ui->label->text()).toDouble();
        labelnumber *= -1;
        input = QString::number(labelnumber,'g',15);
        ui->label->setText(input);
    }

    else if(button->text() == "%")
    {
        labelnumber = (ui->label->text()).toDouble();
        labelnumber *= 0.01;
        input = QString::number(labelnumber,'g',15);
        ui->label->setText(input);
    }

    //error correction code is still missing
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    user_is_typing_secondNumber=false;

    ui->label->setText("0");
    //Updating the equation label
    ui->label_2->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
    double labelnumber,secondNum;
    QString input;
    labelnumber=0;
    QString symbol;
    secondNum = ui->label->text().toDouble();

    if(ui->pushButton_add->isChecked())
    {
        labelnumber = firstNum + secondNum;
        ui->pushButton_add->setChecked(false);
        symbol = " + ";
    }

    else if(ui->pushButton_minus->isChecked())
    {
        labelnumber = firstNum - secondNum;
        ui->pushButton_minus->setChecked(false);
        symbol = " - ";
    }

    else if(ui->pushButton_multiply->isChecked())
    {
        labelnumber = firstNum * secondNum;
        ui->pushButton_multiply->setChecked(false);
        symbol = " x ";
    }

    else if(ui->pushButton_divide->isChecked())
    {
        labelnumber = firstNum / secondNum;
        ui->pushButton_divide->setChecked(false);
        symbol = " / ";
    }
    // Setting the equation label
    ui->label_2->setText(QString::number(firstNum,'g',15) + symbol + QString::number(secondNum,'g',15));
    input = QString::number(labelnumber,'g',15);
    ui->label->setText(input);

    user_is_typing_secondNumber=false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    //double labelnumber;
    //QString input;

    firstNum = ui->label->text().toDouble();
    button->setChecked(true);
    user_is_typing_secondNumber=false;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionDark_triggered()
{
    ui->centralwidget->setStyleSheet("QWidget { background-color: #000; }");
    ui->label_2->setStyleSheet("QLabel { background-color: grey; }");
    ui->label->setStyleSheet("QLabel { background-color: grey; }");
    ui->verticalWidget->setStyleSheet("QWidget { background-color: grey; }");
    ui->pushButton_0->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
    ui->pushButton_1->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
    ui->pushButton_dot->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }");
}


void MainWindow::on_actionLight_triggered()
{
    ui->centralwidget->setStyleSheet("QWidget { background-color: #fff; }");
    ui->label_2->setStyleSheet("QLabel { background-color: rgb(239,239,239); }");
    ui->label->setStyleSheet("QLabel { background-color: rgb(239,239,239); }");
    ui->verticalWidget->setStyleSheet("QWidget { background-color: rgb(239,239,239); }");
    ui->pushButton_0->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }");
    ui->pushButton_1->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgb(239,239,239);; border-radius: 4px; padding: 10px; }");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }");
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }");
    ui->pushButton_dot->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }");
}

