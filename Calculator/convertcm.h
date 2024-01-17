#ifndef CONVERTCM_H
#define CONVERTCM_H

#include <QMainWindow>

namespace Ui {
class convertcm;
}

class convertcm : public QMainWindow
{
    Q_OBJECT

public:
    explicit convertcm(QWidget *parent = nullptr);
    ~convertcm();

signals:
    void back();

private:
    Ui::convertcm *ui;
};

#endif // CONVERTCM_H
