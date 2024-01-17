#ifndef UNITCONVERT_H
#define UNITCONVERT_H

#include <QWidget>

namespace Ui {
class UnitConvert;
}

class UnitConvert : public QWidget
{
    Q_OBJECT

public:
    explicit UnitConvert(QWidget *parent = nullptr);
    ~UnitConvert();

private:
    Ui::UnitConvert *ui;
};

#endif // UNITCONVERT_H
