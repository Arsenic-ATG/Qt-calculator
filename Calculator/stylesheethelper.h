#ifndef STYLESHEETHELPER_H
#define STYLESHEETHELPER_H

#include <QWidget>
#include <QString>

class StylesheetHelper
{
private:
    StylesheetHelper();

public:
    static void setStyleProperty(QWidget* widget, const QString& property, const QString& value);
    static QString getStyleProperty(QWidget* widget, const QString& property);
};

#endif // STYLESHEETHELPER_H
