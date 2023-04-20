#include "mainwindow.h"
#include "ui_mainwindow.h"
double firstNum;
bool user_is_typing_secondNumber=false;
double answer=0;
QString arithmetic_expression;
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Error_Label->setStyleSheet("QLabel {color : red;}");

    connect_buttons(ui,this);

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_Power->setCheckable(true);
    ui->pushButton_Log->setCheckable(true);
    ui->pushButton_mod->setCheckable(true);


}

void MainWindow::connect_buttons(Ui::MainWindow * ui,MainWindow * window){
    MainWindow::connect_digits(ui,window);
    MainWindow::connect_unary(ui,window);
    MainWindow::connect_binary(ui,window);
    MainWindow::connect_special_digits(ui,window);
}


void MainWindow::connect_digits(Ui::MainWindow * ui,MainWindow * window){
    QObject::connect(ui->pushButton_0,SIGNAL(released()),window,SLOT(digit_pressed()));
    QObject::connect(ui->pushButton_1,SIGNAL(released()),window,SLOT(digit_pressed()));
    QObject::connect(ui->pushButton_2,SIGNAL(released()),window,SLOT(digit_pressed()));
    QObject::connect(ui->pushButton_3,SIGNAL(released()),window,SLOT(digit_pressed()));
    QObject::connect(ui->pushButton_4,SIGNAL(released()),window,SLOT(digit_pressed()));
    QObject::connect(ui->pushButton_5,SIGNAL(released()),window,SLOT(digit_pressed()));
    QObject::connect(ui->pushButton_6,SIGNAL(released()),window,SLOT(digit_pressed()));
    QObject::connect(ui->pushButton_7,SIGNAL(released()),window,SLOT(digit_pressed()));
    QObject::connect(ui->pushButton_8,SIGNAL(released()),window,SLOT(digit_pressed()));
    QObject::connect(ui->pushButton_9,SIGNAL(released()),window,SLOT(digit_pressed()));


}


void MainWindow::connect_unary(Ui::MainWindow * ui,MainWindow * window){
    QObject::connect(ui->pushButton_plusMinus,SIGNAL(released()),window,SLOT(unary_operation_pressed()));
    QObject::connect(ui->pushButton_percent,SIGNAL(released()),window,SLOT(unary_operation_pressed()));
    QObject::connect(ui->pushButton_Log,SIGNAL(released()),window,SLOT(unary_operation_pressed()));
    QObject::connect(ui->pushButton_Sqrt,SIGNAL(released()),window,SLOT(unary_operation_pressed()));
    QObject::connect(ui->pushButton_Factorial,SIGNAL(released()),window,SLOT(unary_operation_pressed()));
    QObject::connect(ui->pushButton_exponent,SIGNAL(released()),window,SLOT(unary_operation_pressed()));
    QObject::connect(ui->pushButton_sigmoid,SIGNAL(released()),window,SLOT(unary_operation_pressed()));
    QObject::connect(ui->pushButton_sin,SIGNAL(released()),window,SLOT(unary_operation_pressed()));
    QObject::connect(ui->pushButton_cos,SIGNAL(released()),window,SLOT(unary_operation_pressed()));
    QObject::connect(ui->pushButton_pi,SIGNAL(released()),window,SLOT(digit_pressed()));


}


void MainWindow::connect_binary(Ui::MainWindow * ui,MainWindow * window){
    QObject::connect(ui->pushButton_multiply,SIGNAL(released()),window,SLOT(binary_operation_pressed()));
    QObject::connect(ui->pushButton_add,SIGNAL(released()),window,SLOT(binary_operation_pressed()));
    QObject::connect(ui->pushButton_minus,SIGNAL(released()),window,SLOT(binary_operation_pressed()));
    QObject::connect(ui->pushButton_divide,SIGNAL(released()),window,SLOT(binary_operation_pressed()));
    QObject::connect(ui->pushButton_Power,SIGNAL(released()),window,SLOT(binary_operation_pressed()));
    QObject::connect(ui->pushButton_mod,SIGNAL(released()),window,SLOT(binary_operation_pressed()));
}

void MainWindow::connect_special_digits(Ui::MainWindow *ui, MainWindow *window){
    QObject::connect(ui->pushButton_pi,SIGNAL(released()),window,SLOT(special_number_pressed()));
    QObject::connect(ui->pushButton_previos_answer,SIGNAL(released()),window,SLOT(special_number_pressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}







//button press handaling



void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton *)sender();
    QString input;
    double labelnumber;

    if((ui->pushButton_add->isChecked() || ui->pushButton_divide->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked() || ui->pushButton_Power->isChecked() || ui->pushButton_mod->isChecked()) && (!user_is_typing_secondNumber))
    {
        //ui->pushButton_equals->setEnabled(false);
        user_is_typing_secondNumber=true;
        labelnumber = button->text().toDouble();
        input = QString::number(labelnumber,'g',15);
    }

    else
    {
        ui->pushButton_equals->setEnabled(true);
        if(ui->label->text().contains(".") && button->text() == "0")
        {
            input=ui->label->text() + button->text();
        }
        else
        {
            labelnumber = (ui->label->text() + button->text()).toDouble();
            input = QString::number(labelnumber,'g',15);
        }
    }
    ui->label->setText(input);

}





//number enchantment buttons

void MainWindow::on_pushButton_dot_released()
{
    // check for appearance of decimal, exit function if there is one
    if(ui->label->text().contains(".")){
        return;
    }
    ui->label->setText(ui->label->text() + ".");
    //check for extra decimal
}


void MainWindow::on_pushButton_clear_released()
{
    ui->Error_Label->setText("");
    ui->pushButton_add->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_Power->setChecked(false);
    ui->pushButton_mod->setChecked(false);
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
    if(user_is_typing_secondNumber){
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
            if(secondNum==0){
                ui->Error_Label->setText("Error message: cannot divide by 0");
            }
            else{
            labelnumber = firstNum / secondNum;
            ui->pushButton_divide->setChecked(false);
            symbol = " / ";
            }
        }

        else if(ui->pushButton_Power->isChecked())
        {

            labelnumber = pow(firstNum,secondNum);
            ui->pushButton_Power->setChecked(false);
            symbol = " ^ ";
        }

        else if(ui->pushButton_mod->isChecked())
        {
            if(secondNum==0){
                ui->Error_Label->setText("Error message: cannot calculate mudulu of 0");
            }
            else{

                labelnumber = (int(firstNum) % int(secondNum));
                ui->pushButton_mod->setChecked(false);
                symbol = " mod ";
            }
        }


        // Setting the equation label
        ui->label_2->setText(QString::number(firstNum,'g',15) + symbol + QString::number(secondNum,'g',15) + " = ");
        input = QString::number(labelnumber,'g',15);
        ui->label->setText(input);
        user_is_typing_secondNumber=false;
        answer=input.toDouble();
        arithmetic_expression=ui->label_2->text();
    }
}






//operations


void MainWindow::unary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    double labelnumber;
    QString input;
    QString symbol;
    ui->Error_Label->setText("");
    labelnumber = (ui->label->text()).toDouble();
    if(button->text() == "+/-")
    {
        input = QString::number(labelnumber*-1,'g',15);
    }

    else if(button->text() == "%")
    {
        input = QString::number(labelnumber*0.01,'g',15);
    }

    else if(button->text()=="Log"){
        if((ui->label->text().toDouble())<=0){
            ui->Error_Label->setText("Error message: Log input cant be less then 0");
        }
        else{
            input = QString::number(log10(labelnumber),'g',15);
        }
    }

    else if(button->text() == "√")
    {
        input = QString::number(sqrt(labelnumber),'g',15);
    }

    else if(button->text() == "!")
    {

        input = QString::number(factorial(int(labelnumber)),'g',15);
    }

    else if(button->text() == "exp"){
        input = QString::number(exp(labelnumber),'g',15);
    }
    else if(button->text() == "sigmoid"){
        input = QString::number(1/(1+exp(-labelnumber)),'g',15);
    }

    else if(button->text() == "sin"){
        if(ui->comboBox->currentIndex()==1){input = QString::number(sin(labelnumber/RAD),'g',15);}
        else if(ui->comboBox->currentIndex()==2){input = QString::number(cos(labelnumber/GRAD),'g',15);}
        else input = QString::number(sin(labelnumber),'g',15);

    }
    else if(button->text() == "cos"){
        if(ui->comboBox->currentIndex()==1){input = QString::number(cos(labelnumber/RAD),'g',15);}
        else if(ui->comboBox->currentIndex()==2){input = QString::number(cos(labelnumber/GRAD),'g',15);}
        else input = QString::number(cos(labelnumber),'g',15);
    }




    symbol=button->text();
    if(button->text() == "!"){
        ui->label_2->setText("(" + QString::number(labelnumber) + ")" +symbol + " = ");
    }
    else{
    ui->label_2->setText(symbol+ "(" + QString::number(labelnumber)+ ")" + " = ");
    }
    ui->label->setText(input);
    answer=input.toDouble();
    arithmetic_expression=ui->label_2->text();

}




void MainWindow::binary_operation_pressed()
{
    ui->Error_Label->setText("");
    QPushButton* button = (QPushButton *)sender();
    //double labelnumber;
    //QString input;

    firstNum = ui->label->text().toDouble();
    button->setChecked(true);
    user_is_typing_secondNumber=false;

    if(ui->pushButton_add->isChecked())
    {
        ui->label_2->setText(ui->label->text() + " + ");
    }

    else if(ui->pushButton_minus->isChecked())
    {
        ui->label_2->setText(ui->label->text() + " - ");
    }

    else if(ui->pushButton_multiply->isChecked())
    {
        ui->label_2->setText(ui->label->text() + " x ");
    }

    else if(ui->pushButton_divide->isChecked())
    {
        ui->label_2->setText(ui->label->text() + " / ");
    }
    else if(ui->pushButton_Power->isChecked())
    {
        ui->label_2->setText(ui->label->text() + " ^ ");
    }

    else if(ui->pushButton_mod->isChecked())
    {
        ui->label_2->setText(ui->label->text() + " mod ");
    }


}


void MainWindow::special_number_pressed(){
    QPushButton* button = (QPushButton *)sender();
    if(button->text()=="ans"){
        ui->label->setText(QString::number(answer,'g',15));
        if(!user_is_typing_secondNumber){ui->label_2->setText(ui->label_2->text()+ "answer");user_is_typing_secondNumber=true;}
        else{ui->label_2->setText(arithmetic_expression);}
    }
    else if(button->text()=="pi"){
        ui->label->setText(QString::number(PI,'g',15));
    }
}




//implemented opertions

double MainWindow::factorial(int labelnumber){
    if(labelnumber<=1){
        return 1;
    }
    else if(labelnumber>=FACTORIAL_INFINITY){
        return INFINITY;
    }
    else {
        labelnumber-=1;
        return (labelnumber+1)*factorial(labelnumber);
    }
}







//calculator enchantment functions


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionDark_triggered()
{
    QPalette palette;
    this->setPalette(palette);
    ui->centralwidget->setStyleSheet("QWidget { background-color: #000; }");
    ui->verticalWidget->setStyleSheet("QWidget { background-color: grey; }");
    ui->label_2->setStyleSheet("QLabel { background-color: grey; }");
    ui->label->setStyleSheet("QLabel { background-color: grey; }");
    ui->comboBox->setStyleSheet("QComboBox {background-color: #EFEFEF;}");
    ui->pushButton_0->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_1->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_dot->setStyleSheet("QPushButton { background-color: rgb(215, 215, 215); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(239,239,239);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
}


void MainWindow::on_actionLight_triggered()
{
    QPalette palette;
    this->setPalette(palette);
    ui->comboBox->setStyleSheet("QComboBox {background-color: #EFEFEF;}");
    ui->centralwidget->setStyleSheet("QWidget { background-color: #fff; }");
    ui->label_2->setStyleSheet("QLabel { background-color: rgb(239,239,239); }");
    ui->label->setStyleSheet("QLabel { background-color: rgb(239,239,239); }");
    ui->verticalWidget->setStyleSheet("QWidget { background-color: rgb(239,239,239); }");
    ui->pushButton_0->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_1->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgb(239,239,239);; border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_dot->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
}

void MainWindow::on_actionCyan_triggered()
{
    QPalette palette;
    this->setPalette(palette);
    ui->comboBox->setStyleSheet("QComboBox {background-color: #009575;}");
    ui->centralwidget->setStyleSheet("QWidget { background-color: #002575; }");
    ui->label_2->setStyleSheet("QLabel { background-color: rgb(0,100,100); }");
    ui->label->setStyleSheet("QLabel { background-color: rgb(0,100,100); }");
    ui->verticalWidget->setStyleSheet("QWidget { background-color: rgb(0,100,100); }");
    ui->pushButton_0->setStyleSheet("QPushButton { background-color: rgb(0,100,100); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
    ui->pushButton_1->setStyleSheet("QPushButton { background-color: rgb(0,100,100); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgb(0,100,100); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgb(0,100,100);; border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: rgb(0,100,100); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: rgb(0,100,100); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: rgb(0,100,100); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: rgb(0,100,100); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: rgb(0,100,100); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgb(0,100,100); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
    ui->pushButton_dot->setStyleSheet("QPushButton { background-color: rgb(0,100,100); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(219,219,219);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #FFFFFF, stop: 1 #FFFFFF);}");
}


void MainWindow::on_actiontheme_1_triggered(){
    ui->comboBox->setStyleSheet("QComboBox {background-color: #EFEFEF;}");
    ui->label_2->setStyleSheet("QLabel { background-color: rgb(239,239,239);color: #000000; }");
    ui->label->setStyleSheet("QLabel { background-color: rgb(239,239,239);color: #000000; }");
    ui->verticalWidget->setStyleSheet("QWidget { background-color: rgb(239,239,239); }");
    ui->pushButton_0->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_1->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgb(239,239,239);; border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_dot->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    QPixmap bkgnd(":/resources/Images/theme1.png","5");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void MainWindow::on_actiontheme_2_triggered(){
    ui->comboBox->setStyleSheet("QComboBox {background-color: #EFEFEF;}");
    ui->label_2->setStyleSheet("QLabel { background-color: rgb(239,239,239);color: #000000; }");
    ui->label->setStyleSheet("QLabel { background-color: rgb(239,239,239);color: #000000; }");
    ui->verticalWidget->setStyleSheet("QWidget { background-color: rgb(239,239,239); }");
    ui->pushButton_0->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_1->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgb(239,239,239);; border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_dot->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    QPixmap bkgnd(":/resources/Images/theme2.png","5");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void MainWindow::on_actiontheme_3_triggered(){
    ui->comboBox->setStyleSheet("QComboBox {background-color: #EFEFEF;}");
    ui->label_2->setStyleSheet("QLabel { background-color: rgb(239,239,239);color: #000000; }");
    ui->label->setStyleSheet("QLabel { background-color: rgb(239,239,239);color: #000000; }");
    ui->verticalWidget->setStyleSheet("QWidget { background-color: rgb(239,239,239); }");
    ui->pushButton_0->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_1->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgb(239,239,239);; border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_dot->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    QPixmap bkgnd(":/resources/Images/theme3.png","5");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void MainWindow::on_actiontheme_4_triggered(){
    ui->comboBox->setStyleSheet("QComboBox {background-color: #EFEFEF;}");
    ui->label_2->setStyleSheet("QLabel { background-color: rgb(239,239,239);color: #000000; }");
    ui->label->setStyleSheet("QLabel { background-color: rgb(239,239,239); color: #000000; }");
    ui->verticalWidget->setStyleSheet("QWidget { background-color: rgb(239,239,239); }");
    ui->pushButton_0->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_1->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgb(239,239,239);; border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    ui->pushButton_dot->setStyleSheet("QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }QPushButton:pressed{background-color: rgb(220,220,220);}QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}");
    QPixmap bkgnd(":/resources/Images/theme4.png","5");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
