#include "unary_operation_handler.h"

Unary_operation_handler::Unary_operation_handler()
{

}

double Unary_operation_handler::Unary_operation_triggered(QPushButton* button,Ui::MainWindow* ui)
{
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
    return input.toDouble();
}



double Unary_operation_handler::factorial(int labelnumber){
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
