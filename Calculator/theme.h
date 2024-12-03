// theme.h
#ifndef THEME_H
#define THEME_H

#include <QString>

class Theme
{
public:
    QString comboBoxStyle;
    QString labelStyle;
    QString buttonNormalStyle;
    QString buttonPressedStyle;
    QString buttonHoverStyle;
    QString backgroundImage;

    Theme(QString comboBoxStyle, QString labelStyle, QString buttonNormalStyle, QString buttonPressedStyle, QString buttonHoverStyle, QString backgroundImage)
        : comboBoxStyle(comboBoxStyle), labelStyle(labelStyle), buttonNormalStyle(buttonNormalStyle), buttonPressedStyle(buttonPressedStyle), buttonHoverStyle(buttonHoverStyle), backgroundImage(backgroundImage) {}
};

#endif // THEME_H