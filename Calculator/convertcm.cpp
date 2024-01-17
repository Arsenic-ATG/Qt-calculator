#include "convertcm.h"
#include "ui_convertcm.h"
#include<QPushButton>

convertcm::convertcm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::convertcm)
{
    ui->setupUi(this);

    {
        ui->setupUi(this);
        connect(ui->back,&QPushButton::clicked,this,[=](){
            emit this->back();
        });
    }
}

convertcm::~convertcm()
{
    delete ui;
}
