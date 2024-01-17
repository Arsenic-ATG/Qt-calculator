// do not try to play with comments
#ifndef UNITCONVERTORMAINWINDOW_H
#define UNITCONVERTORMAINWINDOW_H

#include <QMainWindow>
#include<convertcm.h>//unit convertor window
#include <QPlainTextEdit>

namespace Ui {
class UnitConvertorMainWindow;
}

class UnitConvertorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UnitConvertorMainWindow(QWidget *parent = nullptr);
    ~UnitConvertorMainWindow();
    double valueInMeter;
    double valueInKilometer;
    double valueInCentimeter;
    double valueInInch;
    double valueInFoot;
    double valueInYard;
    double valueInMillimeter;

    double valueInSquareKilometer;
    double valueInSquareFoot;
    double valueInSquareMeter;
    double valueInHectare;
    double valueInSquareCentimeter;
    double valueInSquareInch;
    double valueInSquareYard;

    double valueInMiligram;
    double valueInGram;
    double valueInKilogram;
    double valueInPound;
    double valueInTon;

    double valueInMeterPerSecond;
    double valueInMilesPerHour;
    double valueInMeterPerHour;
    double valueInKilometerPerHour;
    double valueInKilometerPerMinute;

    double valueInDegree;
    double valueInRadian;
    double valueInGrad;
    double valueInQuadrant;
    double valueInCircle;
    double valueInTurn;
    double valueInSign;

    double valueInKelvin;
    double valueInCelsius;
    double valueInFahrenheit;
    double valueInRankine;
    double valueInReaumur;
    double valueInTriplePointOfWater;

    double valueInSecond;
    double valueInMinute;
    double valueInHour;
    double valueInDay;
    double valueInWeek;
    double valueInMonth;
    double valueInYear;

    double valueInCubicMeter;
    double valueInCubicKilometer;
    double valueInCubicCentimeter;
    double valueInCubicMillimeter;
    double valueInLiter;
    double valueInMilliliter;

    bool eventFilter(QObject *obj, QEvent *event) override;

    convertcm * pconvertcm=NULL;// ADDRESS OF WINDOW UNIT CONVERTOR

signals:
    void back();




private:
    bool pushButton1Clicked;
    Ui::UnitConvertorMainWindow *ui;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEditFuel;
    QPlainTextEdit *plainTextEditSpeed;
    QPlainTextEdit *plainTextEditAngle;
    QPlainTextEdit *plainTextEditTemperature;
    QPlainTextEdit *plainTextEditTime;
    QPlainTextEdit *plainTextEditVolume;

private slots:
    void onPlainTextEditTextChangedArea();
    void onPlainTextEditTextChangedWeight();
    void updateLabels();
    void onPlainTextEditTextChangedSpeed();
    void onPlainTextEditTextChangedAngle();
    void onPlainTextEditTextChangedTemperature();
    void onPlainTextEditTextChangedTime();
    void onPlainTextEditTextChangedVolume();
    void onPushButtonLengthClicked();
    void onPushButtonAreaClicked();
    void onPushButtonWeightClicked();
    void onPushButtonSpeedClicked();
    void onPushButtonAngleClicked();
    void onPushButtonTemperatureClicked();
    void onPushButtonTimeClicked();
    void onPushButtonVolumeClicked();
    void cleartext();

};


#endif // UNITCONVERTORMAINWINDOW_H
