#include "stylesheethelper.h"

StylesheetHelper::StylesheetHelper()
{

}

void StylesheetHelper::setStyleProperty(QWidget* widget, const QString& property, const QString& value)
{
    std::string styleString = widget->styleSheet().toStdString();
    int propertyPos = styleString.find(property.toStdString());
    int colonPos = styleString.find(':',propertyPos);
    int semicolonPos = styleString.find(';',propertyPos);
    int len = semicolonPos - colonPos;
    styleString.replace(colonPos+1,len-1,value.toStdString());
    widget->setStyleSheet(QString(styleString.data()));
}

QString StylesheetHelper::getStyleProperty(QWidget* widget, const QString& property)
{
    std::string styleString = widget->styleSheet().toStdString();
    std::string valueString;
    int propertyPos = styleString.find(property.toStdString());
    int colonPos = styleString.find(':',propertyPos);
    int semicolonPos = styleString.find(';',propertyPos);
    int len = semicolonPos - colonPos;
    valueString = std::string(styleString,colonPos+1,len-1);
    int leadingSpaceCount = 0;
    for(auto &c : valueString){
        if(c == ' ') leadingSpaceCount++;
        else break;
    }
    valueString.erase(0,leadingSpaceCount);
    return QString(valueString.data());
}
