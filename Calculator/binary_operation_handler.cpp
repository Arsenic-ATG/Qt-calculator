#include "binary_operation_handler.h"

Binary_Operation_Handler::Binary_Operation_Handler()
{

}


double Binary_Operation_Handler::Binary_operation_triggered(QString symbol ,double firstNum, double secondNum,Ui::MainWindow *ui){
    double labelnumber=0;
    QString input;
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
    return labelnumber;
}
