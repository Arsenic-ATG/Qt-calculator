#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connecting digit buttons
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));

    // Additional connections for operations
    connect(ui->pushButton_addition, SIGNAL(released()), this, SLOT(on_pushButton_addition_clicked()));
    connect(ui->pushButton_subtraction, SIGNAL(released()), this, SLOT(on_pushButton_subtraction_clicked()));
    connect(ui->pushButton_multiplication, SIGNAL(released()), this, SLOT(on_pushButton_multiplication_clicked()));
    connect(ui->pushButton_division, SIGNAL(released()), this, SLOT(on_pushButton_division_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    QString newLabel;

    if ((ui->label->text().contains('.')) && (button->text() == "0"))
    {
        newLabel = ui->label->text() + button->text();
    }
    else
    {
        double labelNumber = (ui->label->text() + button->text()).toDouble();
        newLabel = QString::number(labelNumber, 'g', 15);
    }

    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->label->setText("0");
    firstNum = 0;
    userIsTypingSecondNumber = false;
}

void MainWindow::on_pushButton_addition_clicked()
{
    firstNum = ui->label->text().toDouble();
    ui->label->setText("");
    userIsTypingSecondNumber = true;
}

void MainWindow::on_pushButton_equals_clicked()
{
    double secondNum = ui->label->text().toDouble();
    double result;

    result = firstNum + secondNum;  // Implement other operations similarly

    ui->label->setText(QString::number(result, 'g', 15));
}
