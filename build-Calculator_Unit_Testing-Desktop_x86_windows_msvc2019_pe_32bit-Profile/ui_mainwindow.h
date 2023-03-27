/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCopy;
    QAction *actionExit;
    QAction *actionPaste;
    QAction *actionDark;
    QAction *actionLight;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *Error_Label;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QGridLayout *keypad_grid;
    QPushButton *pushButton_9;
    QPushButton *pushButton_0;
    QPushButton *pushButton_plusMinus;
    QPushButton *pushButton_6;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_percent;
    QPushButton *pushButton_1;
    QPushButton *pushButton_Log;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_equals;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_Factorial;
    QPushButton *pushButton_add;
    QPushButton *pushButton_Power;
    QPushButton *pushButton_divide;
    QPushButton *pushButton_multiply;
    QPushButton *pushButton_Sqrt;
    QPushButton *pushButton_exponent;
    QPushButton *pushButton_mod;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuThemes;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(441, 494);
        MainWindow->setMinimumSize(QSize(0, 75));
        MainWindow->setMouseTracking(false);
        MainWindow->setStyleSheet(QString::fromUtf8("/*Change the background color */\n"
"background-color: #fff;"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionDark = new QAction(MainWindow);
        actionDark->setObjectName(QString::fromUtf8("actionDark"));
        actionLight = new QAction(MainWindow);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("/* (Label at top) Label Stylesheet */\n"
"\n"
"QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  \n"
"  color: rgb(0, 255, 0);\n"
"\n"
"}\n"
"\n"
"background-color : white;\n"
"\n"
"/* End Label Stylesheet */"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Error_Label = new QLabel(centralwidget);
        Error_Label->setObjectName(QString::fromUtf8("Error_Label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Terminal"));
        Error_Label->setFont(font);
        Error_Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(Error_Label);

        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy);
        verticalWidget->setMinimumSize(QSize(0, 80));
        verticalWidget->setMaximumSize(QSize(16777215, 75));
        verticalWidget->setStyleSheet(QString::fromUtf8("#verticalWidget\n"
"{ \n"
"  border: 2px solid gray;\n"
"  background-color: rgb(239,239,239);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(verticalWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 15));
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"  color: #000;\n"
"  background-color: rgb(239,239,239);\n"
"}"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);

        label = new QLabel(verticalWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 20));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"  color: #000;\n"
"  background-color: rgb(239,239,239);\n"
"}"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);


        verticalLayout_2->addWidget(verticalWidget);

        keypad_grid = new QGridLayout();
        keypad_grid->setSpacing(20);
        keypad_grid->setObjectName(QString::fromUtf8("keypad_grid"));
        keypad_grid->setSizeConstraint(QLayout::SetDefaultConstraint);
        keypad_grid->setContentsMargins(2, 3, 2, 2);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setMinimumSize(QSize(50, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setWeight(50);
        pushButton_9->setFont(font2);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_9, 5, 2, 1, 1);

        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        sizePolicy1.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy1);
        pushButton_0->setFont(font2);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_0, 6, 0, 1, 3);

        pushButton_plusMinus = new QPushButton(centralwidget);
        pushButton_plusMinus->setObjectName(QString::fromUtf8("pushButton_plusMinus"));
        sizePolicy1.setHeightForWidth(pushButton_plusMinus->sizePolicy().hasHeightForWidth());
        pushButton_plusMinus->setSizePolicy(sizePolicy1);
        pushButton_plusMinus->setFont(font2);
        pushButton_plusMinus->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #000;\n"
"  background-color: rgb(215, 215, 215);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_plusMinus, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_6, 4, 2, 1, 1);

        pushButton_minus = new QPushButton(centralwidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->setExclusive(true);
        buttonGroup->addButton(pushButton_minus);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        sizePolicy1.setHeightForWidth(pushButton_minus->sizePolicy().hasHeightForWidth());
        pushButton_minus->setSizePolicy(sizePolicy1);
        pushButton_minus->setFont(font2);
        pushButton_minus->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #FFF;\n"
"  background-color: rgb(38, 196, 111);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_minus, 5, 7, 1, 1);

        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        sizePolicy1.setHeightForWidth(pushButton_clear->sizePolicy().hasHeightForWidth());
        pushButton_clear->setSizePolicy(sizePolicy1);
        pushButton_clear->setFont(font2);
        pushButton_clear->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  background-color: rgb(254,99,71);\n"
"  border-radius: 4px;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_clear, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_3, 2, 2, 1, 1);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setMinimumSize(QSize(50, 50));
        pushButton_8->setFont(font2);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_8, 5, 1, 1, 1);

        pushButton_percent = new QPushButton(centralwidget);
        pushButton_percent->setObjectName(QString::fromUtf8("pushButton_percent"));
        sizePolicy1.setHeightForWidth(pushButton_percent->sizePolicy().hasHeightForWidth());
        pushButton_percent->setSizePolicy(sizePolicy1);
        pushButton_percent->setFont(font2);
        pushButton_percent->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #000;\n"
"  background-color: rgb(215, 215, 215);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_percent, 1, 2, 1, 1);

        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        sizePolicy1.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy1);
        pushButton_1->setMinimumSize(QSize(50, 50));
        pushButton_1->setFont(font2);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_1, 2, 0, 1, 1);

        pushButton_Log = new QPushButton(centralwidget);
        pushButton_Log->setObjectName(QString::fromUtf8("pushButton_Log"));
        sizePolicy1.setHeightForWidth(pushButton_Log->sizePolicy().hasHeightForWidth());
        pushButton_Log->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        pushButton_Log->setFont(font3);
        pushButton_Log->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #000;\n"
"  background-color: rgb(215, 215, 215);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_Log, 1, 3, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_5, 4, 1, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_4, 4, 0, 1, 1);

        pushButton_equals = new QPushButton(centralwidget);
        pushButton_equals->setObjectName(QString::fromUtf8("pushButton_equals"));
        sizePolicy1.setHeightForWidth(pushButton_equals->sizePolicy().hasHeightForWidth());
        pushButton_equals->setSizePolicy(sizePolicy1);
        pushButton_equals->setFont(font2);
        pushButton_equals->setToolTipDuration(-1);
        pushButton_equals->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #FFF;\n"
"  background-color: rgb(239, 92, 98);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_equals, 6, 7, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMinimumSize(QSize(50, 50));
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_7, 5, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(50, 50));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        sizePolicy1.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy1);
        pushButton_dot->setFont(font2);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(134,134,140);\n"
"background-color: rgb(239,239,239);\n"
"border-radius: 4px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff\n"
");\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border-style: inset;\n"
"background: qradialgradient(\n"
"cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #707070, stop: 1 #606060\n"
");\n"
"}"));

        keypad_grid->addWidget(pushButton_dot, 6, 3, 1, 1);

        pushButton_Factorial = new QPushButton(centralwidget);
        pushButton_Factorial->setObjectName(QString::fromUtf8("pushButton_Factorial"));
        sizePolicy1.setHeightForWidth(pushButton_Factorial->sizePolicy().hasHeightForWidth());
        pushButton_Factorial->setSizePolicy(sizePolicy1);
        pushButton_Factorial->setFont(font2);
        pushButton_Factorial->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #FFF;\n"
"  background-color: rgb(241, 122, 28);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_Factorial, 4, 4, 1, 1);

        pushButton_add = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_add);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        sizePolicy1.setHeightForWidth(pushButton_add->sizePolicy().hasHeightForWidth());
        pushButton_add->setSizePolicy(sizePolicy1);
        pushButton_add->setFont(font2);
        pushButton_add->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #FFF;\n"
"  background-color: rgb(105, 165, 245);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_add, 4, 7, 1, 1);

        pushButton_Power = new QPushButton(centralwidget);
        pushButton_Power->setObjectName(QString::fromUtf8("pushButton_Power"));
        sizePolicy1.setHeightForWidth(pushButton_Power->sizePolicy().hasHeightForWidth());
        pushButton_Power->setSizePolicy(sizePolicy1);
        pushButton_Power->setFont(font2);
        pushButton_Power->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #FFF;\n"
"  background-color: rgb(241, 122, 28);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_Power, 1, 4, 1, 1);

        pushButton_divide = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_divide);
        pushButton_divide->setObjectName(QString::fromUtf8("pushButton_divide"));
        sizePolicy1.setHeightForWidth(pushButton_divide->sizePolicy().hasHeightForWidth());
        pushButton_divide->setSizePolicy(sizePolicy1);
        pushButton_divide->setFont(font2);
        pushButton_divide->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #FFF;\n"
"  background-color: rgb(196, 56, 227);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}\n"
""));

        keypad_grid->addWidget(pushButton_divide, 2, 7, 1, 1);

        pushButton_multiply = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_multiply);
        pushButton_multiply->setObjectName(QString::fromUtf8("pushButton_multiply"));
        sizePolicy1.setHeightForWidth(pushButton_multiply->sizePolicy().hasHeightForWidth());
        pushButton_multiply->setSizePolicy(sizePolicy1);
        pushButton_multiply->setFont(font2);
        pushButton_multiply->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #FFF;\n"
"  background-color: rgb(241, 122, 28);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_multiply, 1, 7, 1, 1);

        pushButton_Sqrt = new QPushButton(centralwidget);
        pushButton_Sqrt->setObjectName(QString::fromUtf8("pushButton_Sqrt"));
        sizePolicy1.setHeightForWidth(pushButton_Sqrt->sizePolicy().hasHeightForWidth());
        pushButton_Sqrt->setSizePolicy(sizePolicy1);
        pushButton_Sqrt->setFont(font2);
        pushButton_Sqrt->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #FFF;\n"
"  background-color: rgb(241, 122, 28);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_Sqrt, 2, 4, 1, 1);

        pushButton_exponent = new QPushButton(centralwidget);
        pushButton_exponent->setObjectName(QString::fromUtf8("pushButton_exponent"));
        sizePolicy1.setHeightForWidth(pushButton_exponent->sizePolicy().hasHeightForWidth());
        pushButton_exponent->setSizePolicy(sizePolicy1);
        pushButton_exponent->setFont(font3);
        pushButton_exponent->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #000;\n"
"  background-color: rgb(215, 215, 215);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_exponent, 2, 3, 1, 1);

        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        sizePolicy1.setHeightForWidth(pushButton_mod->sizePolicy().hasHeightForWidth());
        pushButton_mod->setSizePolicy(sizePolicy1);
        pushButton_mod->setFont(font3);
        pushButton_mod->setStyleSheet(QString::fromUtf8("/* (Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet */\n"
"\n"
"QPushButton {\n"
"  color: #000;\n"
"  background-color: rgb(215, 215, 215);\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));

        keypad_grid->addWidget(pushButton_mod, 5, 3, 1, 1);


        verticalLayout_2->addLayout(keypad_grid);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 441, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuThemes = new QMenu(menuFile);
        menuThemes->setObjectName(QString::fromUtf8("menuThemes"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addAction(menuThemes->menuAction());
        menuThemes->addAction(actionDark);
        menuThemes->addAction(actionLight);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Qt-calculator", nullptr));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
        actionDark->setText(QApplication::translate("MainWindow", "Dark", nullptr));
        actionLight->setText(QApplication::translate("MainWindow", "Light", nullptr));
        Error_Label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "0", nullptr));
        label->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "9", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_9->setShortcut(QApplication::translate("MainWindow", "9", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_0->setText(QApplication::translate("MainWindow", "0", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_0->setShortcut(QApplication::translate("MainWindow", "0", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_plusMinus->setText(QApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "6", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_6->setShortcut(QApplication::translate("MainWindow", "6", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_minus->setText(QApplication::translate("MainWindow", "-", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_minus->setShortcut(QApplication::translate("MainWindow", "-", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_clear->setText(QApplication::translate("MainWindow", "C", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_clear->setShortcut(QApplication::translate("MainWindow", "C", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_3->setText(QApplication::translate("MainWindow", "3", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_3->setShortcut(QApplication::translate("MainWindow", "3", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_8->setText(QApplication::translate("MainWindow", "8", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_8->setShortcut(QApplication::translate("MainWindow", "8", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_percent->setText(QApplication::translate("MainWindow", "%", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_percent->setShortcut(QApplication::translate("MainWindow", "%", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_1->setText(QApplication::translate("MainWindow", "1", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_1->setShortcut(QApplication::translate("MainWindow", "1", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_Log->setText(QApplication::translate("MainWindow", "Log", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_Log->setShortcut(QApplication::translate("MainWindow", "%", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_5->setText(QApplication::translate("MainWindow", "5", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_5->setShortcut(QApplication::translate("MainWindow", "5", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_4->setText(QApplication::translate("MainWindow", "4", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_4->setShortcut(QApplication::translate("MainWindow", "4", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        pushButton_equals->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_equals->setText(QApplication::translate("MainWindow", "=", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_equals->setShortcut(QApplication::translate("MainWindow", "Enter", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_7->setText(QApplication::translate("MainWindow", "7", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_7->setShortcut(QApplication::translate("MainWindow", "7", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_2->setShortcut(QApplication::translate("MainWindow", "2", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_dot->setText(QApplication::translate("MainWindow", ".", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_dot->setShortcut(QApplication::translate("MainWindow", ".", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_Factorial->setText(QApplication::translate("MainWindow", "!", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_Factorial->setShortcut(QApplication::translate("MainWindow", "*", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_add->setText(QApplication::translate("MainWindow", " + ", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_add->setShortcut(QApplication::translate("MainWindow", "+", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_Power->setText(QApplication::translate("MainWindow", "^", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_Power->setShortcut(QApplication::translate("MainWindow", "*", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_divide->setText(QApplication::translate("MainWindow", "\303\267", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_divide->setShortcut(QApplication::translate("MainWindow", "/", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_multiply->setText(QApplication::translate("MainWindow", "x", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_multiply->setShortcut(QApplication::translate("MainWindow", "*", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_Sqrt->setText(QApplication::translate("MainWindow", "\342\210\232", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_Sqrt->setShortcut(QApplication::translate("MainWindow", "*", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_exponent->setText(QApplication::translate("MainWindow", "exp", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_exponent->setShortcut(QApplication::translate("MainWindow", "%", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_mod->setText(QApplication::translate("MainWindow", "mod", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_mod->setShortcut(QApplication::translate("MainWindow", "%", nullptr));
#endif // QT_NO_SHORTCUT
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuThemes->setTitle(QApplication::translate("MainWindow", "Themes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
