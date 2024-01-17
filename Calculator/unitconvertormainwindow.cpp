// do not try to play with comments
#include "unitconvertormainwindow.h"
#include "ui_unitconvertormainwindow.h"
#include<QPushButton>
#include<QDebug>
#include<QMessageBox>
#include<QComboBox>

UnitConvertorMainWindow::UnitConvertorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UnitConvertorMainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->pushButton1, &QPushButton::clicked, this, &UnitConvertorMainWindow::onPushButtonLengthClicked);
    connect(ui->pushButton1_2, &QPushButton::clicked, this, &UnitConvertorMainWindow::onPushButtonAreaClicked);
    connect(ui->pushButton1_14, &QPushButton::clicked, this, &UnitConvertorMainWindow::onPushButtonWeightClicked);
    connect(ui->pushButton1_13, &QPushButton::clicked, this, &UnitConvertorMainWindow::onPushButtonSpeedClicked);
    connect(ui->pushButton1_3, &QPushButton::clicked, this, &UnitConvertorMainWindow::onPushButtonAngleClicked);
    connect(ui->pushButton1_12, &QPushButton::clicked, this, &UnitConvertorMainWindow::onPushButtonTemperatureClicked);
    connect(ui->pushButton1_11, &QPushButton::clicked, this, &UnitConvertorMainWindow::onPushButtonTimeClicked);
    connect(ui->pushButton1_9, &QPushButton::clicked, this, &UnitConvertorMainWindow::onPushButtonVolumeClicked);

    ui->plainTextEdit_2->installEventFilter(this);
    ui->plainTextEdit_10->installEventFilter(this);
    ui->plainTextEdit_23->installEventFilter(this);
    ui->plainTextEdit_22->installEventFilter(this);
    ui->plainTextEdit_3->installEventFilter(this);
    ui->plainTextEdit_21->installEventFilter(this);
    ui->plainTextEdit_20->installEventFilter(this);
    ui->plainTextEdit_18->installEventFilter(this);

    QStringList strList;
    strList << "Length" << "Temperature" << "Speed" << "Area" << "Fuel" <<"Angle" << "Volume" << "Weight" << "Preasure";

//    for(int i = 0; i<strList.size(); i++){
//        QListWidgetItem *pItem = new QListWidgetItem();
//        pItem->setSizeHint(QSize(50,50));
//        pItem->setTextAlignment(Qt::AlignCenter);
//        pItem->setText(strList.at(i));
//        ui->listWidget->insertItem(i,pItem);
//    } TESTING FOR SET AS TEXT

//    connect(ui->listWidget,&QListWidget::currentRowChanged,[=](int index)
//    {
//        qDebug()<<"index ="<<index;
//    }); DEBUG OF SEE THE VALUE (THE VALUE RETURN WIHT CORRECT VALUE, GOOD JOB TEAM)

    QIcon icon0(":/Images/Angle.png");
    QListWidgetItem * pItem0 = new QListWidgetItem(icon0,"");
    ui->listWidget->insertItem(0,pItem0);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon1(":/Images/Length.png");
    QListWidgetItem * pItem1 = new QListWidgetItem(icon1,"");
    ui->listWidget->insertItem(1,pItem1);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon2(":/Images/Area.png");
    QListWidgetItem * pItem2 = new QListWidgetItem(icon2,"");
    ui->listWidget->insertItem(2,pItem2);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon3(":/Images/Weight.png");
    QListWidgetItem * pItem3 = new QListWidgetItem(icon3,"");
    ui->listWidget->insertItem(3,pItem3);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon4(":/Images/Speed.png");
    QListWidgetItem * pItem4 = new QListWidgetItem(icon4,"");
    ui->listWidget->insertItem(4,pItem4);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon5(":/Images/Temperature.png");
    QListWidgetItem * pItem5 = new QListWidgetItem(icon5,"");
    ui->listWidget->insertItem(5,pItem5);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon6(":/Images/Time.png");
    QListWidgetItem * pItem6 = new QListWidgetItem(icon6,"");
    ui->listWidget->insertItem(6,pItem6);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon7(":/Images/Volume.png");
    QListWidgetItem * pItem7 = new QListWidgetItem(icon7,"");
    ui->listWidget->insertItem(7,pItem7);
    ui->listWidget->setIconSize(QSize(50,50));

    connect(ui->listWidget,&QListWidget::currentRowChanged,[=](int index)
    {
        ui->stackedWidget->setCurrentIndex(index);
    });

    plainTextEdit_2 = ui->plainTextEdit_2;

    plainTextEdit_3 = ui->plainTextEdit_10;

    plainTextEditFuel = ui->plainTextEdit_23;

    plainTextEditSpeed = ui->plainTextEdit_22;

    plainTextEditAngle = ui->plainTextEdit_3;

    plainTextEditTemperature= ui->plainTextEdit_21;

    plainTextEditTime= ui->plainTextEdit_20;

    plainTextEditVolume= ui->plainTextEdit_18;


    connect(ui->back,&QPushButton::clicked,[=](){
        emit this->back();
    });
}

bool UnitConvertorMainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        // Handle the mouse press event
        ui->plainTextEdit_2->clear();
        ui->plainTextEdit_10->clear();
        ui->plainTextEdit_23->clear();
        ui->plainTextEdit_22->clear();
        ui->plainTextEdit_3->clear();
        ui->plainTextEdit_21->clear();
        ui->plainTextEdit_20->clear();
        ui->plainTextEdit_18->clear();
    }

    // Call the base class implementation for other events
    return QMainWindow::eventFilter(obj, event);
}

void UnitConvertorMainWindow::cleartext() {
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit_10->clear();
    ui->plainTextEdit_23->clear();
    ui->plainTextEdit_22->clear();
    ui->plainTextEdit_3->clear();
    ui->plainTextEdit_21->clear();
    ui->plainTextEdit_20->clear();
    ui->plainTextEdit_18->clear();
}

    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_16;
    QComboBox *comboBox1;
    QPushButton *pushButton1;

    void UnitConvertorMainWindow::onPushButtonLengthClicked() {
    // Set a flag or perform any other actions you need when the button is clicked
    pushButton1Clicked = true;
    updateLabels();
    qDebug() << "PushButton1 clicked!";
    }

    void UnitConvertorMainWindow::updateLabels() {
    int maxLength = 30;  // Adjust the value as needed

    QString inputValue = plainTextEdit_2->toPlainText();


    // Check if the input is a valid number
    bool isNumber;
    double value = inputValue.toDouble(&isNumber);

    QString selectedText = ui->comboBox1->currentText();


    // Check if the input exceeds the maximum length
    if (inputValue.length() > maxLength) {
        // Truncate the text to the maximum length
        inputValue.truncate(maxLength);

        // Set the truncated text in the plain text edit
        plainTextEdit_2->setPlainText(inputValue);
        QMessageBox::critical(this, "Error", "The input have reached max");


    } else if (inputValue.length() <= maxLength && isNumber && pushButton1Clicked){
        // Enable input if it's within the maximum length
        plainTextEdit_2->setReadOnly(false);
        pushButton1Clicked=false;

    if (selectedText == "mm" ) {

            valueInMillimeter = value;
            valueInMeter = value * 0.001;
            valueInKilometer = value * 0.000001;
            valueInCentimeter = value / 10.0;
            valueInInch = value * 0.0393700787;
            valueInFoot = value * 0.032808399;
            valueInYard = value * 0.010936133;


        } else if (selectedText == "cm") {

            valueInCentimeter = value;
            valueInMeter = value / 100.0;         // Centimeter to Meter
            valueInKilometer = value / 100000.0;  // Centimeter to Kilometer
            valueInMillimeter = value * 10.0;     // Centimeter to Millimeter
            valueInInch = value * 0.393701;       // Centimeter to Inch
            valueInFoot = value * 0.0328084;      // Centimeter to Foot
            valueInYard = value * 0.0109361;      // Centimeter to Yard


        } else if (selectedText == "inch") {

            valueInCentimeter = value * 2.54;
            valueInMeter = value * 0.0254;
            valueInKilometer = value /  39370.10;
            valueInMillimeter = value * 25.4;
            valueInInch = value;
            valueInFoot = value / 12;
            valueInYard = value / 36;

        } else if (selectedText == "ft"){

            valueInMillimeter = value * 304.8;
            valueInMeter = value * 0.3048;
            valueInKilometer = value / 3,280.84;
            valueInCentimeter = value * 30.48;
            valueInInch = value * 0.0393700787;
            valueInFoot = value;
            valueInYard = value / 3;

        } else if (selectedText == "m"){

            valueInMillimeter = value * 1000;
            valueInMeter = value;
            valueInKilometer = value / 1000;
            valueInCentimeter = value * 100;
            valueInInch = value / 0.0254;
            valueInFoot = value / 0.0254;
            valueInYard = value / 0.9144;

        } else if (selectedText == "km"){


            valueInMillimeter = value * 1000000;
            valueInMeter = value * 1000;
            valueInKilometer = value;
            valueInCentimeter = value * 100000;
            valueInInch = value * 39,370.1;
            valueInFoot = value * 3,280.84;
            valueInYard = value * 1093.61;

        } else if (selectedText == "yd"){

            valueInMillimeter = value * 914.4;
            valueInMeter = value * 0.9144;
            valueInKilometer = value * 0.0009144;
            valueInCentimeter = value * 91.44;
            valueInInch = value * 36;
            valueInFoot = value * 3;
            valueInYard = value;

        }

        ui->label_12->setText(QString::number(valueInMillimeter, 'f', 4) + " mm");
        ui->label_13->setText(QString::number(valueInCentimeter, 'f', 4) + " cm");
        ui->label_14->setText(QString::number(valueInInch, 'f', 4) + " inch");
        ui->label_15->setText(QString::number(valueInFoot, 'f', 4) + " ft");
        ui->label_16->setText(QString::number(valueInMeter, 'f', 4) + " m");
        ui->label_17->setText(QString::number(valueInKilometer, 'f', 4) + " km");
        ui->label_60->setText(QString::number(valueInYard, 'f', 4) + " yd");


        } else {
            QMessageBox::critical(this, "Error", "Please enter a valid number");
            return;
        }
    }

    QPlainTextEdit *plainTextEdit_10;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_61;
    QComboBox *comboBox1_2;
    QPushButton *pushButton1_2;

    void UnitConvertorMainWindow::onPushButtonAreaClicked() {
        pushButton1Clicked = true;
        onPlainTextEditTextChangedArea();
    }

    void UnitConvertorMainWindow::onPlainTextEditTextChangedArea() {
        int maxLength = 30;  // Adjust the value as needed

        QString inputValue = plainTextEdit_3->toPlainText();

        bool isNumber;
        double value = inputValue.toDouble(&isNumber);

        QString selectedText = ui->comboBox1_2->currentText();


    // Check if the input exceeds the maximum length
    if (inputValue.length() > maxLength) {
        // Truncate the text to the maximum length
        inputValue.truncate(maxLength);

        // Set the truncated text in the plain text edit
        plainTextEdit_3->setPlainText(inputValue);
        QMessageBox::critical(this, "Error", "The input have reached max");


    } else if (inputValue.length() <= maxLength && isNumber && pushButton1Clicked){
        // Enable input if it's within the maximum length
        plainTextEdit_3->setReadOnly(false);
        pushButton1Clicked=false;

        if (selectedText == "hectare" ) {

            valueInSquareKilometer = value * 0.01;
            valueInSquareFoot  = value * 107639.10417;
            valueInSquareMeter = value * 10000;
            valueInHectare  = value;
            valueInSquareCentimeter  = value * 100000000;
            valueInSquareInch  = value * 15500031;
            valueInSquareYard  = value * 11959.900463;


        } else if (selectedText == "cm²") {

            valueInSquareKilometer = value * 1.0e-10;
            valueInSquareFoot = value * 0.00107639;
            valueInSquareMeter = value * 0.0001;
            valueInHectare = value * 1.0e-8;
            valueInSquareCentimeter = value;
            valueInSquareInch = value * 0.15500031;
            valueInSquareYard = value * 0.000119599;

        } else if (selectedText == "inch²") {

            valueInSquareKilometer = value * 6.4516e-11;
            valueInSquareFoot = value * 0.00064516;
            valueInSquareMeter = value * 0.00064516;
            valueInHectare = value * 6.4516e-8;
            valueInSquareCentimeter = value * 6.4516;
            valueInSquareInch = value;
            valueInSquareYard = value * 0.000771605;

        } else if (selectedText == "ft²") {

            valueInSquareKilometer = value * 9.2903e-13;
            valueInSquareFoot = value;
            valueInSquareMeter = value * 0.092903;
            valueInHectare = value * 9.2903e-6;
            valueInSquareCentimeter = value * 929.0304;
            valueInSquareInch = value * 144;
            valueInSquareYard = value * 0.111111;

        } else if (selectedText == "m²") {

            valueInSquareKilometer = value * 1.0e-6;
            valueInSquareFoot = value * 10.7639;
            valueInSquareMeter = value;
            valueInHectare = value * 1.0e-4;
            valueInSquareCentimeter = value * 10000;
            valueInSquareInch = value * 1550.0031;
            valueInSquareYard = value * 1.19599;

        } else if (selectedText == "km²") {

            valueInSquareKilometer = value;
            valueInSquareFoot = value * 1.07639e+7;
            valueInSquareMeter = value * 1.0e+6;
            valueInHectare = value * 100;
            valueInSquareCentimeter = value * 1.0e+10;
            valueInSquareInch = value * 1.5500031e+8;
            valueInSquareYard = value * 1.19599e+6;

        } else if (selectedText == "yd²") {

            valueInSquareKilometer = value * 8.3613e-10;
            valueInSquareFoot = value * 9;
            valueInSquareMeter = value * 0.836127;
            valueInHectare = value * 8.3613e-8;
            valueInSquareCentimeter = value * 8361.2736;
            valueInSquareInch = value * 1296;
            valueInSquareYard = value;

        }

            // Update the labels with the converted values
            ui->label_18->setText(QString::number(valueInHectare,'f') + " hectare");
            ui->label_19->setText(QString::number(valueInSquareCentimeter,'f') + " cm²");
            ui->label_20->setText(QString::number(valueInSquareInch,'f') + " inch²");
            ui->label_21->setText(QString::number(valueInSquareFoot,'f') + " ft²");
            ui->label_22->setText(QString::number(valueInSquareMeter,'f') + " m²");
            ui->label_23->setText(QString::number(valueInSquareKilometer,'f') + " km²");
            ui->label_61->setText(QString::number(valueInSquareYard,'f') + " yd²");

        } else {
            QMessageBox::critical(this, "Error", "Please enter a valid number");
            return;
        }


}

    QPlainTextEdit *plainTextEdit_23;
    QLabel *label_145;
    QLabel *label_146;
    QLabel *label_147;
    QLabel *label_148;
    QLabel *label_149;
    QLabel *label_150;
    QLabel *label_151;
    QComboBox *comboBox1_14;
    QPushButton *pushButton1_14;

    void UnitConvertorMainWindow::onPushButtonWeightClicked() {
    pushButton1Clicked = true;
    onPlainTextEditTextChangedWeight();
    }

    void UnitConvertorMainWindow::onPlainTextEditTextChangedWeight() {
    int maxLength = 30;  // Adjust the value as needed

    QString inputValue = plainTextEditFuel->toPlainText();

    bool isNumber;
    double value = inputValue.toDouble(&isNumber);

    QString selectedText = ui->comboBox1_14->currentText();


    // Check if the input exceeds the maximum length
        if (inputValue.length() > maxLength) {
            // Truncate the text to the maximum length
            inputValue.truncate(maxLength);

            // Set the truncated text in the plain text edit
            plainTextEditFuel->setPlainText(inputValue);
            QMessageBox::critical(this, "Error", "The input have reached max");



        } else if (inputValue.length() <= maxLength && isNumber && pushButton1Clicked){
            // Enable input if it's within the maximum length
            plainTextEditFuel->setReadOnly(false);
            pushButton1Clicked=false;

            if (selectedText == "MG" ) {

                valueInMiligram  = value;
                valueInGram   = value * 0.001;
                valueInKilogram = value * 0.000001;
                valueInPound  = value * 0.0000022046;
                valueInTon  = value * 9.999999999E-10;

            } else if (selectedText == "G") {

                valueInMiligram  = value * 1000;
                valueInGram   = value;
                valueInKilogram = value * 0.001;
                valueInPound  = value * 0.0022046244;
                valueInTon  = value * 0.000001;

            } else if (selectedText == "KG") {

                valueInMiligram  = value * 1000000;
                valueInGram   = value * 1000;
                valueInKilogram = value;
                valueInPound  = value * 2.2046244202;
                valueInTon  = value * 0.001;

            } else if (selectedText == "POUND"){

                valueInMiligram  = value * 453592;
                valueInGram   = value * 453.592;
                valueInKilogram = value * 0.453592;
                valueInPound  = value;
                valueInTon  = value * 0.000453592;

            } else if (selectedText == "TAN"){

                valueInMiligram  = value * 1000000000;
                valueInGram   = value * 1000000;
                valueInKilogram = value * 1000;
                valueInPound  = value * 2204.6244202;
                valueInTon  = value;

            }

            // Update the labels with the converted values
            ui->label_145->setText(QString::number(valueInMiligram,'f') + " MG");
            ui->label_146->setText(QString::number(valueInGram,'f') + " G");
            ui->label_147->setText(QString::number(valueInKilogram,'f') + " KG");
            ui->label_148->setText(QString::number(valueInPound,'f') + " POUND");
            ui->label_149->setText(QString::number(valueInTon,'f') + " TON");

            } else {
                QMessageBox::critical(this, "Error", "Please enter a valid number");
                return;
            }
}

    QPlainTextEdit *plainTextEdit_22;
    QLabel *label_138;
    QLabel *label_139;
    QLabel *label_140;
    QLabel *label_141;
    QLabel *label_142;
    QLabel *label_143;
    QLabel *label_144;
    QComboBox *comboBox1_13;
    QPushButton *pushButton1_13;

    void UnitConvertorMainWindow::onPushButtonSpeedClicked() {
    pushButton1Clicked = true;
    onPlainTextEditTextChangedSpeed();
    }

    void UnitConvertorMainWindow::onPlainTextEditTextChangedSpeed() {
    int maxLength = 30;  // Adjust the value as needed

    QString inputValue = plainTextEditSpeed->toPlainText();

    bool isNumber;
    double value = inputValue.toDouble(&isNumber);

    QString selectedText = ui->comboBox1_13->currentText();


    // Check if the input exceeds the maximum length
    if (inputValue.length() > maxLength) {
        // Truncate the text to the maximum length
        inputValue.truncate(maxLength);

        // Set the truncated text in the plain text edit
        plainTextEditSpeed->setPlainText(inputValue);
        QMessageBox::critical(this, "Error", "The input have reached max");



    } else if (inputValue.length() <= maxLength && isNumber && pushButton1Clicked){
        // Enable input if it's within the maximum length
        plainTextEditSpeed->setReadOnly(false);
        pushButton1Clicked=false;

        if (selectedText == "m/s" ) {

                valueInMeterPerSecond = value;
                valueInMilesPerHour = value * 2.2369362921;
                valueInMeterPerHour = value * 3600;
                valueInKilometerPerHour = value * 3.6;
                valueInKilometerPerMinute = value * 0.06;

        } else if (selectedText == "mi/h") {

                valueInMeterPerSecond = value * 0.44704;
                valueInMilesPerHour = value;
                valueInMeterPerHour = value * 1609.344;
                valueInKilometerPerHour = value * 1.609344;
                valueInKilometerPerMinute = value * 0.0268224;

        } else if (selectedText == "m/h") {

                valueInMeterPerSecond = value * 0.0002777778;
                valueInMilesPerHour = value * 0.0006213712;
                valueInMeterPerHour = value;
                valueInKilometerPerHour = value * 0.001;
                valueInKilometerPerMinute = value * 0.0000166667;

        } else if (selectedText == "km/h"){

                valueInMeterPerSecond = value * 0.2777777778;
                valueInMilesPerHour = value * 0.6213711922;
                valueInMeterPerHour = value * 1000;
                valueInKilometerPerHour = value;
                valueInKilometerPerMinute = value * 0.0166666667;

        } else if (selectedText == "km/m"){

                valueInMeterPerSecond = value * 16.666666667;
                valueInMilesPerHour = value * 37.282271534;
                valueInMeterPerHour = value * 60000;
                valueInKilometerPerHour = value * 60;
                valueInKilometerPerMinute = value;

        }

        // Update the labels with the converted values
        ui->label_138->setText(QString::number(valueInMeterPerSecond, 'f') + " m/s");
        ui->label_139->setText(QString::number(valueInMilesPerHour, 'f') + " mi/h");
        ui->label_140->setText(QString::number(valueInMeterPerHour, 'f') + " m/h");
        ui->label_141->setText(QString::number(valueInKilometerPerHour, 'f') + " km/h");
        ui->label_142->setText(QString::number(valueInKilometerPerMinute, 'f') + " km/m");

        } else {
                QMessageBox::critical(this, "Error", "Please enter a valid number");
                return;
        }


    }

    QPlainTextEdit *plainTextEdit_3;
    QLabel *label_62;
    QLabel *label_63;
    QLabel *label_64;
    QLabel *label_65;
    QLabel *label_66;
    QLabel *label_67;
    QLabel *label_68;
    QComboBox *comboBox1_3;
    QPushButton *pushButton1_3;

    void UnitConvertorMainWindow::onPushButtonAngleClicked() {
        pushButton1Clicked = true;
        onPlainTextEditTextChangedAngle();
    }

    void UnitConvertorMainWindow::onPlainTextEditTextChangedAngle() {
        int maxLength = 30;  // Adjust the value as needed

        QString inputValue = plainTextEditAngle->toPlainText();

        bool isNumber;
        double value = inputValue.toDouble(&isNumber);

        QString selectedText = ui->comboBox1_3->currentText();


        // Check if the input exceeds the maximum length
        if (inputValue.length() > maxLength) {
                // Truncate the text to the maximum length
                inputValue.truncate(maxLength);

                // Set the truncated text in the plain text edit
                plainTextEditAngle->setPlainText(inputValue);
                QMessageBox::critical(this, "Error", "The input have reached max");


        } else if (inputValue.length() <= maxLength && isNumber && pushButton1Clicked){
                // Enable input if it's within the maximum length
                plainTextEditAngle->setReadOnly(false);
                pushButton1Clicked=false;

                if (selectedText == "Degree" ) {

                valueInDegree = value;
                valueInRadian = value * 0.0174532925;
                valueInGrad = value * 1.1111111111;
                valueInQuadrant = value * 0.0111111111;
                valueInCircle = value * 0.0027777778;
                valueInTurn = value * 0.0027777778;
                valueInSign = value * 0.0333333333;

                } else if (selectedText == "Radian") {

                valueInDegree = value * 57.295779513;
                valueInRadian = value;
                valueInGrad = value * 63.661977237;
                valueInQuadrant = value * 0.6366197724;
                valueInCircle = value * 0.1591549431;
                valueInTurn = value * 0.1591549431;
                valueInSign = value * 1.9098593171;

                } else if (selectedText == "Grad") {

                valueInDegree = value * 0.9;
                valueInRadian = value * 0.0157079633;
                valueInGrad = value;
                valueInQuadrant = value * 0.01;
                valueInCircle = value * 0.0025;
                valueInTurn = value * 0.0025;
                valueInSign = value * 0.03;

                } else if (selectedText == "Sign"){

                valueInDegree = value * 30;
                valueInRadian = value * 0.5235987756;
                valueInGrad = value * 33.333333333;
                valueInQuadrant = value * 0.3333333333;
                valueInCircle = value * 0.0833333333;
                valueInTurn = value * 0.0833333333;
                valueInSign = value;

                } else if (selectedText == "Quadrant"){

                valueInDegree = value * 90;
                valueInRadian = value * 1.5707963268;
                valueInGrad = value * 100;
                valueInQuadrant = value;
                valueInCircle = value * 0.25;
                valueInTurn = value * 0.25;
                valueInSign = value * 3;

                } else if (selectedText == "Circle"){

                valueInDegree = value * 360;
                valueInRadian = value * 6.2831853072;
                valueInGrad = value * 400;
                valueInQuadrant = value * 4;
                valueInCircle = value;
                valueInTurn = value;
                valueInSign = value * 12;

                } else if (selectedText == "Turn"){

                valueInDegree = value * 360;
                valueInRadian = value * 6.2831853072;
                valueInGrad = value;
                valueInQuadrant = value * 400;
                valueInCircle = value * 4;
                valueInTurn = value;
                valueInSign = value * 12;

                }

                // Update the labels with the converted values
                ui->label_62->setText(QString::number(valueInDegree, 'f'));
                ui->label_63->setText(QString::number(valueInRadian, 'f'));
                ui->label_64->setText(QString::number(valueInGrad, 'f'));
                ui->label_65->setText(QString::number(valueInQuadrant, 'f'));
                ui->label_66->setText(QString::number(valueInCircle, 'f'));
                ui->label_67->setText(QString::number(valueInTurn, 'f'));
                ui->label_68->setText(QString::number(valueInSign, 'f'));

        } else {
                QMessageBox::critical(this, "Error", "Please enter a valid number");
                return;
        }
    }

    QPlainTextEdit *plainTextEdit_21;
    QLabel *label_131;
    QLabel *label_132;
    QLabel *label_133;
    QLabel *label_134;
    QLabel *label_135;
    QLabel *label_136;
    QLabel *label_137;
    QComboBox *comboBox1_12;
    QPushButton *pushButton1_12;

    void UnitConvertorMainWindow::onPushButtonTemperatureClicked() {
        pushButton1Clicked = true;
        onPlainTextEditTextChangedTemperature();
    }

    void UnitConvertorMainWindow::onPlainTextEditTextChangedTemperature() {
        int maxLength = 30;  // Adjust the value as needed

        QString inputValue = plainTextEditTemperature->toPlainText();

        bool isNumber;
        double value = inputValue.toDouble(&isNumber);

        QString selectedText = ui->comboBox1_12->currentText();


        // Check if the input exceeds the maximum length
        if (inputValue.length() > maxLength) {
                // Truncate the text to the maximum length
                inputValue.truncate(maxLength);

                // Set the truncated text in the plain text edit
                plainTextEditTemperature->setPlainText(inputValue);
                QMessageBox::critical(this, "Error", "The input have reached max");


        } else if (inputValue.length() <= maxLength && isNumber && pushButton1Clicked){
                // Enable input if it's within the maximum length
                plainTextEditTemperature->setReadOnly(false);
                pushButton1Clicked=false;

                if (selectedText == "Kelvin" ) {

                valueInKelvin = value;
                valueInCelsius = value * -272.15;
                valueInFahrenheit = value * -457.87;
                valueInRankine = value * 1.8;
                valueInReaumur = value * -217.72;
                valueInTriplePointOfWater = value * 0.0036608581;

                } else if (selectedText == "Celsius") {

                valueInKelvin = value * 274.15;
                valueInCelsius = value;
                valueInFahrenheit = value * 33.8;
                valueInRankine = value * 493.47;
                valueInReaumur = value * 0.8;
                valueInTriplePointOfWater = value * 1.0036242495;


                } else if (selectedText == "Fahrenheit") {

                valueInKelvin = value * 255.92777778;
                valueInCelsius = value * -17.222222222;
                valueInFahrenheit = value;
                valueInRankine = value * 460.67;
                valueInReaumur = value * -13.777777778;
                valueInTriplePointOfWater = value * 0.9369152796;


                } else if (selectedText == "Rankine"){

                valueInKelvin = value * 0.5555555556;
                valueInCelsius = value * -272.59444444;
                valueInFahrenheit = value * -458.67;
                valueInRankine = value;
                valueInReaumur = value * -218.07555556;
                valueInTriplePointOfWater = value * 0.0020338101;


                } else if (selectedText == "Reaumur"){

                valueInKelvin = value * 274.4;
                valueInCelsius = value * 1.25;
                valueInFahrenheit = value * 34.25;
                valueInRankine = value * 493.92;
                valueInReaumur = value;
                valueInTriplePointOfWater = value * 1.0045394641;


                } else if (selectedText == "TriplePointOfWater"){

                valueInKelvin = value * 273.16;
                valueInCelsius = value * 0.01;
                valueInFahrenheit = value * 32.018;
                valueInRankine = value * 491.688;
                valueInReaumur = value * 0.008;
                valueInTriplePointOfWater = value;

                }

                // Update the labels with the converted values
                ui->label_131->setText(QString::number(valueInKelvin, 'f') + " Kelvin");
                ui->label_132->setText(QString::number(valueInCelsius, 'f') + " Celsius");
                ui->label_133->setText(QString::number(valueInFahrenheit, 'f') + " Fahrenheit");
                ui->label_134->setText(QString::number(valueInRankine, 'f') + " Rankine");
                ui->label_135->setText(QString::number(valueInReaumur, 'f') + " Reaumur");
                ui->label_136->setText(QString::number(valueInTriplePointOfWater, 'f') + " TriplePointOfWater");

        } else {
                QMessageBox::critical(this, "Error", "Please enter a valid number");
                return;
        }
    }

    QPlainTextEdit *plainTextEdit_20;
    QLabel *label_124;
    QLabel *label_125;
    QLabel *label_126;
    QLabel *label_127;
    QLabel *label_128;
    QLabel *label_129;
    QLabel *label_130;
    QComboBox *comboBox1_11;
    QPushButton *pushButton1_11;

    void UnitConvertorMainWindow::onPushButtonTimeClicked() {
        pushButton1Clicked = true;
        onPlainTextEditTextChangedTime();
    }

    void UnitConvertorMainWindow::onPlainTextEditTextChangedTime() {
        int maxLength = 30;  // Adjust the value as needed

        QString inputValue = plainTextEditTime->toPlainText();

        bool isNumber;
        double value = inputValue.toDouble(&isNumber);

        QString selectedText = ui->comboBox1_11->currentText();


        // Check if the input exceeds the maximum length
        if (inputValue.length() > maxLength) {
                // Truncate the text to the maximum length
                inputValue.truncate(maxLength);

                // Set the truncated text in the plain text edit
                plainTextEditTime->setPlainText(inputValue);
                QMessageBox::critical(this, "Error", "The input have reached max");

                QMessageBox::critical(this, "Error", "The input have reached max");


        } else if (inputValue.length() <= maxLength && isNumber && pushButton1Clicked){
                // Enable input if it's within the maximum length
                plainTextEditTime->setReadOnly(false);
                pushButton1Clicked=false;

                if (selectedText == "Second" ) {

                valueInSecond = value;
                valueInMinute = value * 0.0166666667;
                valueInHour = value * 0.0002777778;
                valueInDay = value * 0.0000115741;
                valueInWeek = value * 0.0000016534;
                valueInMonth = value * 3.802570537E-7;
                valueInYear = value * 3.168808781E-8;

                } else if (selectedText == "Minute") {

                valueInSecond = value * 60;
                valueInMinute = value;
                valueInHour = value * 0.0166666667;
                valueInDay = value * 0.0006944444;
                valueInWeek = value * 0.0000992063;
                valueInMonth = value * 0.0000228154;
                valueInYear = value * 0.0000019013;


                } else if (selectedText == "Hour") {

                valueInSecond = value * 3600;
                valueInMinute = value * 60;
                valueInHour = value;
                valueInDay = value * 0.0416666667;
                valueInWeek = value * 0.005952381;
                valueInMonth = value * 0.0013689254;
                valueInYear = value * 0.0001140771;


                } else if (selectedText == "Day"){

                valueInSecond = value * 86400;
                valueInMinute = value * 1440;
                valueInHour = value * 24;
                valueInDay = value;
                valueInWeek = value * 0.1428571429;
                valueInMonth = value * 0.0328542094;
                valueInYear = value * 0.0027378508;


                } else if (selectedText == "Week"){

                valueInSecond = value * 604800;
                valueInMinute = value * 10080;
                valueInHour = value * 168;
                valueInDay = value * 7;
                valueInWeek = value;
                valueInMonth = value * 0.2299794661;
                valueInYear = value * 0.0191649555;

                } else if (selectedText == "Month"){

                valueInSecond = value * 2629800;
                valueInMinute = value * 43830;
                valueInHour = value * 730.5;
                valueInDay = value * 30.4375;
                valueInWeek = value * 4.3482142857;
                valueInMonth = value;
                valueInYear = value * 0.0833333333;

                } else if (selectedText == "Year"){

                valueInSecond = value * 31557600;
                valueInMinute = value * 525960;
                valueInHour = value * 8766;
                valueInDay = value * 365.25;
                valueInWeek = value * 52.178571429;
                valueInMonth = value * 12;
                valueInYear = value;

                }

                // Update the labels with the converted values
                ui->label_124->setText(QString::number(valueInSecond, 'f') );
                ui->label_125->setText(QString::number(valueInMinute, 'f'));
                ui->label_126->setText(QString::number(valueInHour, 'f')) ;
                ui->label_127->setText(QString::number(valueInDay, 'f') );
                ui->label_128->setText(QString::number(valueInWeek, 'f'));
                ui->label_129->setText(QString::number(valueInMonth, 'f'));
                ui->label_130->setText(QString::number(valueInYear, 'f'));

        } else {
                QMessageBox::critical(this, "Error", "Please enter a valid number");
                return;
        }
    }

    QPlainTextEdit *plainTextEdit_18;
    QLabel *label_110;
    QLabel *label_118;
    QLabel *label_119;
    QLabel *label_120;
    QLabel *label_121;
    QLabel *label_122;
    QLabel *label_123;
    QComboBox *comboBox1_9;
    QPushButton *pushButton1_9;

    void UnitConvertorMainWindow::onPushButtonVolumeClicked() {
        pushButton1Clicked = true;
        onPlainTextEditTextChangedVolume();
    }

    void UnitConvertorMainWindow::onPlainTextEditTextChangedVolume() {
        int maxLength = 30;  // Adjust the value as needed

        QString inputValue = plainTextEditVolume->toPlainText();

        bool isNumber;
        double value = inputValue.toDouble(&isNumber);

        QString selectedText = ui->comboBox1_9->currentText();


        // Check if the input exceeds the maximum length
        if (inputValue.length() > maxLength) {
                // Truncate the text to the maximum length
                inputValue.truncate(maxLength);

                // Set the truncated text in the plain text edit
                plainTextEditVolume->setPlainText(inputValue);
                QMessageBox::critical(this, "Error", "The input have reached max");


        } else if (inputValue.length() <= maxLength && isNumber && pushButton1Clicked){
                // Enable input if it's within the maximum length
                plainTextEditVolume->setReadOnly(false);
                pushButton1Clicked=false;

                if (selectedText == "m³" ) {

                valueInCubicMeter = value;
                valueInCubicKilometer = value * 1.E-9;
                valueInCubicCentimeter = value * 1000000;
                valueInCubicMillimeter = value * 1000000000;
                valueInLiter = value * 1000;
                valueInMilliliter = value * 1000000;


                } else if (selectedText == "km³"){

                valueInCubicMeter = value * 1000000;
                valueInCubicKilometer = value;
                valueInCubicCentimeter = value * 1000000000000000;
                valueInCubicMillimeter = value * 1000000000000000000;
                valueInLiter = value * 1000000000000;
                valueInMilliliter = value * 1000000000000000;

                } else if (selectedText == "cm³") {

                valueInCubicMeter = value * 0.000001;
                valueInCubicKilometer = value * 9.999999999E-16;
                valueInCubicCentimeter = value;
                valueInCubicMillimeter = value * 1000;
                valueInLiter = value * 0.001;
                valueInMilliliter = value * 1;

                } else if (selectedText == "mm³"){

                valueInCubicMeter = value * 1.E-9;
                valueInCubicKilometer = value * 1.E-18;
                valueInCubicCentimeter = value * 0.001;
                valueInCubicMillimeter = value;
                valueInLiter = value * 0.000001;
                valueInMilliliter = value * 0.001;

                } else if (selectedText == "l"){

                valueInCubicMeter = value * 0.001;
                valueInCubicKilometer = value * 1.E-12;
                valueInCubicCentimeter = value * 1000;
                valueInCubicMillimeter = value * 1000000;
                valueInLiter = value;
                valueInMilliliter = value * 1000;

                } else if (selectedText == "ml"){

                valueInCubicMeter = value * 0.000001;
                valueInCubicKilometer = value * 9.999999999E-16;
                valueInCubicCentimeter = value * 1;
                valueInCubicMillimeter = value * 1000;
                valueInLiter = value * 0.001;
                valueInMilliliter = value;

                }

                // Update the labels with the converted values
                ui->label_110->setText(QString::number(valueInCubicMeter, 'f') + " m³");
                ui->label_118->setText(QString::number(valueInCubicKilometer, 'f') + " km³");
                ui->label_119->setText(QString::number(valueInCubicCentimeter, 'f') + " cm³");
                ui->label_120->setText(QString::number(valueInCubicMillimeter, 'f') + " mm³");
                ui->label_121->setText(QString::number(valueInLiter, 'f') + " l");
                ui->label_122->setText(QString::number(valueInMilliliter, 'f') + " ml");

        } else {
                QMessageBox::critical(this, "Error", "Please enter a valid number");
                return;
        }
    }
UnitConvertorMainWindow::~UnitConvertorMainWindow()
    {
        delete ui;
    }



