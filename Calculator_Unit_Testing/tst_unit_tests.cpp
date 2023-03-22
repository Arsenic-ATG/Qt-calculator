#include <QtTest>
#include<iostream>
#include <../Calculator/mainwindow.h>
#include <ui_mainwindow.h>
#include<QApplication>
// add necessary includes here
class Unit_tests : public QObject
{
    Q_OBJECT

;
public:
    Unit_tests();
    ~Unit_tests();
private:
   void press_digit(int num,int digits_num,Ui::MainWindow* ui);

private slots:
    void Check_Sum_of_two_numbers();
    void Check_diff_of_two_numbers();
    void Check_multiply_of_two_numbers();
    void Check_divide_of_two_numbers();

};

Unit_tests::Unit_tests()
{

}

Unit_tests::~Unit_tests()
{

}

void Unit_tests::press_digit(int num,int digits_num, Ui::MainWindow *ui){

    while(digits_num>=1){
        digits_num--;
        int digit=int(num/pow(10,digits_num))%10;
        switch(digit){
            case 0:
                ui->pushButton_0->click();
                break;
            case 1:
                ui->pushButton_1->click();
                break;
            case 2:
                ui->pushButton_2->click();
                 break;
            case 3:
                ui->pushButton_3->click();
                 break;
            case 4:
                ui->pushButton_4->click();
                 break;
            case 5:
                ui->pushButton_5->click();
                 break;
            case 6:
                ui->pushButton_6->click();
                 break;
            case 7:
                ui->pushButton_7->click();
                 break;
            case 8:
                ui->pushButton_8->click();
                 break;
            case 9:
                ui->pushButton_9->click();
                 break;
            default:
                ui->pushButton_1->click();
                 break;
            }

    }
}

int digits_counter(int num){
    int count=0;
    while (num>0){
        num/=10;
        count++;
    }
    return count;
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow ui;
    Unit_tests ut;
    ui.show();
    QTest::qExec(&ut,argc,argv);


    return 0;
}


void Unit_tests::Check_Sum_of_two_numbers(){
    MainWindow ui;
    int num1=std::rand();
    int num2=std::rand();
    press_digit(num1,digits_counter(num1),ui.ui);
    ui.ui->pushButton_add->click();
    press_digit(num2,digits_counter(num2),ui.ui);
    ui.ui->pushButton_equals->click();
    QString Label_number=(ui.ui->label->text());
    int sum=Label_number.toInt();
    QCOMPARE(sum,num1+num2);
}


void Unit_tests::Check_diff_of_two_numbers(){
    MainWindow ui;
    int num1=std::rand();
    int num2=std::rand();
    press_digit(num1,digits_counter(num1),ui.ui);
    ui.ui->pushButton_minus->click();
    press_digit(num2,digits_counter(num2),ui.ui);
    ui.ui->pushButton_equals->click();
    QString Label_number=(ui.ui->label->text());
    int sum=Label_number.toInt();
    QCOMPARE(sum,num1-num2);
}

void Unit_tests::Check_multiply_of_two_numbers(){
    MainWindow ui;
    int num1=std::rand();
    int num2=std::rand();
    press_digit(num1,digits_counter(num1),ui.ui);
    ui.ui->pushButton_multiply->click();
    press_digit(num2,digits_counter(num2),ui.ui);
    ui.ui->pushButton_equals->click();
    QString Label_number=(ui.ui->label->text());
    int sum=Label_number.toInt();
    QCOMPARE(sum,num1*num2);
}

void Unit_tests::Check_divide_of_two_numbers(){
    MainWindow ui;
    int num1=std::rand();
    int num2=std::rand();
    press_digit(num1,digits_counter(num1),ui.ui);
    ui.ui->pushButton_divide->click();
    press_digit(num2,digits_counter(num2),ui.ui);
    ui.ui->pushButton_equals->click();
    QString Label_number=(ui.ui->label->text());
    int sum=Label_number.toInt();
    QCOMPARE(sum,num1/num2);
}



#include "tst_unit_tests.moc"

