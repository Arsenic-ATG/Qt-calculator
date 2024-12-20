#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "theme.h"

// Global variables to store numbers and state
double firstNum;
double secondNum;
bool user_is_typing_secondNumber = false;
QString input;

// Constructor for MainWindow
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Error_Label->setStyleSheet("QLabel {color : red;}");

    // Add digit buttons to the list
    digitButtons.push_back(ui->pushButton_0);
    digitButtons.push_back(ui->pushButton_1);
    digitButtons.push_back(ui->pushButton_2);
    digitButtons.push_back(ui->pushButton_3);
    digitButtons.push_back(ui->pushButton_4);
    digitButtons.push_back(ui->pushButton_5);
    digitButtons.push_back(ui->pushButton_6);
    digitButtons.push_back(ui->pushButton_7);
    digitButtons.push_back(ui->pushButton_8);
    digitButtons.push_back(ui->pushButton_9);
    digitButtons.push_back(ui->pushButton_dot);

    // Initialize UI elements
    comboBox = ui->comboBox;
    centralwidget = ui->centralwidget;
    verticalWidget = ui->verticalWidget;
    label = ui->label;
    label_2 = ui->label_2;

    // Connect buttons to their respective slots
    connect_buttons(ui.data(), this);

    // Set buttons as checkable
    ui->pushButton_add->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_Power->setCheckable(true);
    ui->pushButton_Log->setCheckable(true);
    ui->pushButton_squared->setCheckable(true);
}

// Function to connect all buttons
void MainWindow::connect_buttons(Ui::MainWindow *ui, MainWindow *window)
{
    MainWindow::connect_digits(window);
    MainWindow::connect_unary(window);
    MainWindow::connect_binary(window);
    MainWindow::connect_special_digits(ui, window);
}

// Function to connect digit buttons
void MainWindow::connect_digits(MainWindow *window)
{
    for (int i = 0; i <= 9; i++)
    {
        QPushButton *button = digitButtons[i];
        QObject::connect(button, SIGNAL(released()), window, SLOT(digit_pressed()));
    }
}

// Function to connect unary operation buttons
void MainWindow::connect_unary(MainWindow *window)
{
    for (const auto &name : unary_buttonNames)
    {
        QPushButton *button = qobject_cast<QPushButton *>(window->findChild<QPushButton *>(name));
        QObject::connect(button, &QPushButton::released, window, &MainWindow::unary_operation_pressed);
    }
}

// Function to connect binary operation buttons
void MainWindow::connect_binary(MainWindow *window)
{
    for (const auto &name : binary_buttonNames)
    {
        QPushButton *button = qobject_cast<QPushButton *>(window->findChild<QPushButton *>(name));
        QObject::connect(button, &QPushButton::released, window, &MainWindow::binary_operation_pressed);
    }
}

// Function to connect special digit buttons
void MainWindow::connect_special_digits(Ui::MainWindow *ui, MainWindow *window)
{
    QObject::connect(ui->pushButton_pi, SIGNAL(released()), window, SLOT(special_number_pressed()));
    QObject::connect(ui->pushButton_previos_answer, SIGNAL(released()), window, SLOT(special_number_pressed()));
}

// Destructor for MainWindow
MainWindow::~MainWindow()
{
    ui.reset();
}

// Slot for digit button press
void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton *)sender();
    auto button_number = button->text();
    QString labelnumber;

    // TODO: make this a function (some thing like is_binary_operation_button_checked() or store it as a flag somewhere which can be flipped when a binary operation is performed)
    if ((!user_is_typing_secondNumber) &&
        (ui->pushButton_add->isChecked() ||
            ui->pushButton_divide->isChecked() ||
            ui->pushButton_minus->isChecked() ||
            ui->pushButton_multiply->isChecked() ||
            ui->pushButton_Power->isChecked() ||
            ui->pushButton_squared->isChecked()))
    {
        user_is_typing_secondNumber = true;
        labelnumber = button_number;
    }
    else
    {
        ui->pushButton_equals->setEnabled(true);
        if (ui->label->text().contains(".") && button_number == "0")
            input = ui->label->text() + button_number;
        else
            labelnumber = ui->label->text() + button_number;
    }

    // Remove trailing zeros in number
    while (labelnumber.startsWith('0')) { labelnumber.remove(0,1); }

    ui->label->setText(labelnumber);
    secondNum = labelnumber.toDouble();
}

// Slot for dot button press
void MainWindow::on_pushButton_dot_released()
{
    // Check for appearance of decimal, exit function if there is one
    if (ui->label->text().contains("."))
        return;
    ui->label->setText(ui->label->text() + ".");
}

// Slot for clear button press
void MainWindow::on_pushButton_clear_released()
{
    ui->Error_Label->setText("0");
    ui->pushButton_add->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_Power->setChecked(false);
    ui->pushButton_squared->setChecked(false);
    user_is_typing_secondNumber = false;
    ui->label->setText("");
    // Updating the equation label
    ui->label_2->setText("0");
}

// Slot for equals button press
void MainWindow::on_pushButton_equals_released()
{
    if (user_is_typing_secondNumber)
    {
        secondNum = ui->label->text().toDouble();
        input = equal_handler.Equals_Button_triggered(firstNum, secondNum, ui.data());
        user_is_typing_secondNumber = false;
    }
}

// Slot for unary operation button press
void MainWindow::unary_operation_pressed()
{
    QPushButton *button = (QPushButton *)sender();
    unary_handler.Unary_operation_triggered(button, ui.data());
}

// Slot for binary operation button press
void MainWindow::binary_operation_pressed()
{
    QPushButton *button = (QPushButton *)sender();
    firstNum = ui->label->text().toDouble();
    binary_handler.Binary_operation_pressed(ui.data(), button);
}

// Slot for special number button press
void MainWindow::special_number_pressed()
{
    QPushButton *button = (QPushButton *)sender();
    if (button->text() == "ans")
    {
        if (user_is_typing_secondNumber)
        {
            if (ui->label->text() == "0")
                ui->label_2->setText("answer");
            else
                ui->label_2->setText(ui->label_2->text() + "answer");
            ui->label->setText(QString::number(equal_handler.answer, 'g', 15));
        }
        else
        {
            ui->label_2->setText(equal_handler.arithmetic_expression);
            ui->label->setText(QString::number(equal_handler.answer, 'g', 15));
        }
    }
    else if (button->text() == "π")
    {
        ui->label->setText(QString::number(PI, 'g', 15));
    }
}

// Slot for exit action
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

// Function to apply a theme
void MainWindow::applyTheme(const Theme &theme)
{
    comboBox->setStyleSheet(theme.comboBoxStyle);
    label_2->setStyleSheet(theme.labelStyle);
    label->setStyleSheet(theme.labelStyle);
    verticalWidget->setStyleSheet("QWidget { background-color: rgb(239,239,239); }");
    for (auto b : digitButtons)
    {
        b->setStyleSheet(theme.buttonNormalStyle + theme.buttonPressedStyle + theme.buttonHoverStyle);
    }

    QPixmap bkgnd(theme.backgroundImage, "5");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);

    centralwidget->setStyleSheet("QWidget { background-color: rgba(0,0,0,0); }");
    this->setPalette(palette);
}


void MainWindow::on_actiontheme_2_triggered(){
    comboBox->setStyleSheet("QComboBox {background-color: #EFEFEF;} QAbstractItemView{background-color: #EFEFEF;}");
    label_2->setStyleSheet("QLabel { background-color: rgb(239,239,239);color: #000000; }");
    label->setStyleSheet("QLabel { background-color: rgb(239,239,239);color: #000000; }");
    verticalWidget->setStyleSheet("QWidget { background-color: rgb(239,239,239); }");
    for(auto b : digitButtons)
    {
        QString normalStyle="QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }";
        QString pressedStyle="QPushButton:pressed{background-color: rgb(220,220,220);}";
        QString hoverStyle="QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}";
        b->setStyleSheet(normalStyle+pressedStyle+hoverStyle);
    }

    QPixmap bkgnd(":/resources/Images/theme2.png","5");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);

    //This makes the background transparent again so that the image shows for 100%.
    centralwidget->setStyleSheet("QWidget { background-color: rgba(0,0,0,0); }");

    this->setPalette(palette);
}

// Define theme instances
Theme theme1("QComboBox {background-color: #EFEFEF;}", "QLabel { background-color: rgb(239,239,239);color: #000000; }", "QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }", "QPushButton:pressed{background-color: rgb(220,220,220);}", "QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}", ":/resources/Images/theme1.png");
Theme theme2("QComboBox {background-color: #EFEFEF;} QAbstractItemView{background-color: #EFEFEF;}", "QLabel { background-color: rgb(239,239,239);color: #000000; }", "QPushButton { background-color: rgb(239,239,239); border-radius: 4px; padding: 10px; }", "QPushButton:pressed{background-color: rgb(220,220,220);}", "QPushButton:hover:!pressed {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #8afff7, stop: 1 #73ffff);}", ":/resources/Images/theme2.png");
// Define more themes as needed

// Slot for theme 1 action
void MainWindow::on_actiontheme_1_triggered()
{
    applyTheme(theme1);
}
