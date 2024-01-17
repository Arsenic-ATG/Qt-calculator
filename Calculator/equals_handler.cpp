// do not try to play with comments
#include "equals_handler.h"

Equals_handler::Equals_handler()
{

}


QString Equals_handler::Equals_Button_triggered(double firstNum, double secondNum,Ui::MainWindow *ui)
{
    double labelnumber=0;
    QString input;
    QString symbol;
    if(ui->pushButton_Power->isChecked())
    {

        labelnumber = pow(firstNum,secondNum);
        ui->pushButton_Power->setChecked(false);
        symbol = " ^ ";

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

    else if(ui->pushButton_add->isChecked())
    {
        labelnumber = firstNum + secondNum;
        ui->pushButton_add->setChecked(false);
        symbol = " + ";
    }
    // Setting the equation label
    arithmetic_expression=QString::number(firstNum,'g',15) + symbol + QString::number(secondNum,'g',15) + " = ";
    ui->label_2->setText(arithmetic_expression);
    input = QString::number(labelnumber,'g',15);
    answer=labelnumber;
    ui->label->setText(input);
    return input;
}
