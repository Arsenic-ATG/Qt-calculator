#include "unitconvert.h"
#include "ui_unitconvert.h"

UnitConvert::UnitConvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UnitConvert)
{
    ui->setupUi(this);
}

UnitConvert::~UnitConvert()
{
    delete ui;
}
