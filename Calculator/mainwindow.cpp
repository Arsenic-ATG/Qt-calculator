#include "mainwindow.h"
#include "ui_mainwindow.h"
double firstNum;
double secondNum;
bool user_is_typing_secondNumber=false;

QString input;
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->Error_Label->setStyleSheet("QLabel {color : red;}");

    connect_buttons(ui.data(),this);

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_Power->setCheckable(true);
    ui->pushButton_Log->setCheckable(true);
    ui->pushButton_mod->setCheckable(true);


}

void MainWindow::connect_buttons(Ui::MainWindow * ui,MainWindow * window){
    MainWindow::connect_digits(window);
    MainWindow::connect_unary(ui,window);
    MainWindow::connect_binary(ui,window);
    MainWindow::connect_special_digits(ui,window);
}


void MainWindow::connect_digits(MainWindow * window){
    for(int i=1; i<=9; i++){

        QPushButton *button = qobject_cast<QPushButton*>(window->findChild<QObject*>("pushButton_" + QString::number(i)));
        QObject::connect(button, SIGNAL(released()), window, SLOT(digit_pressed()));
    }



}


void MainWindow::connect_unary(Ui::MainWindow * ui,MainWindow * window){
    for (const auto& name : unary_buttonNames) {
            QPushButton *button = qobject_cast<QPushButton*>(window->findChild<QPushButton*>(name));
            QObject::connect(button, &QPushButton::released, window, &MainWindow::unary_operation_pressed);
        }


}


void MainWindow::connect_binary(Ui::MainWindow * ui,MainWindow * window){
    for (const auto& name : binary_buttonNames) {
            QPushButton *button = qobject_cast<QPushButton*>(window->findChild<QPushButton*>(name));
            QObject::connect(button, &QPushButton::released, window, &MainWindow::binary_operation_pressed);
        }

}

void MainWindow::connect_special_digits(Ui::MainWindow *ui, MainWindow *window){
    QObject::connect(ui->pushButton_pi,SIGNAL(released()),window,SLOT(special_number_pressed()));
    QObject::connect(ui->pushButton_previos_answer,SIGNAL(released()),window,SLOT(special_number_pressed()));

}

MainWindow::~MainWindow()
{
    ui.reset();
}







//button press handaling



void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton *)sender();
    double labelnumber;

    if((ui->pushButton_add->isChecked() || ui->pushButton_divide->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked() || ui->pushButton_Power->isChecked() || ui->pushButton_mod->isChecked()) && (!user_is_typing_secondNumber))
    {
        user_is_typing_secondNumber=true;
        labelnumber = button->text().toDouble();
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
    secondNum=input.toDouble();
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



    if(user_is_typing_secondNumber){
        secondNum = ui->label->text().toDouble();
        input=equal_handler.Equals_Button_triggered(firstNum,secondNum,ui.data());
        user_is_typing_secondNumber=false;
//        answer=input.toDouble();
//        arithmetic_expression=ui->label_2->text();
    }
}






//operations


void MainWindow::unary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    /*answer=*/unary_handler.Unary_operation_triggered(button,ui.data());
//    arithmetic_expression=ui->label_2->text();

}




void MainWindow::binary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    firstNum=ui->label->text().toDouble();
    binary_handler.Binary_operation_pressed(ui.data(),button);

}


void MainWindow::special_number_pressed(){
    QPushButton* button = (QPushButton *)sender();
    if(button->text()=="ans"){

        if(!user_is_typing_secondNumber){
            if(ui->label->text()=="0"){
                ui->label_2->setText("answer");
            }
            else{
                ui->label_2->setText(ui->label_2->text()+ "answer");
            }
            ui->label->setText(QString::number(equal_handler.answer,'g',15));
        }
        else{ui->label_2->setText(equal_handler.arithmetic_expression);}
    }
    else if(button->text()=="pi"){
        ui->label->setText(QString::number(PI,'g',15));
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
