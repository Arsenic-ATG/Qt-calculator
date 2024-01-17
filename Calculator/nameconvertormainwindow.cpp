#include "nameconvertormainwindow.h"
#include "ui_nameconvertormainwindow.h"
#include <QLineEdit>
#include <QMouseEvent>
#include <QObject>
#include <QEvent>
#include <QMessageBox>
#include <QRegularExpression>

nameconvertorMainWindow::nameconvertorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nameconvertorMainWindow)
{
    ui->setupUi(this);

    // Apply the style sheet to the QMainWindow
    QString mainStyle = "QMainWindow {"
                        "    background-color: #2c3e50;" // Dark blue background
                        "}";

    this->setStyleSheet(mainStyle);

    // Apply the style sheet to the QPushButton
    QString buttonStyle = "QPushButton {"
                          "    background-color: #3498db;" // Bright blue background
                          "    color: white;" // White text
                          "    border: none;" // No border
                          "    border-radius: 5px;" // Rounded corners
                          "    padding: 5px 10px;" // Some padding
                          "}"
                          "QPushButton:hover {"
                          "    background-color: #2980b9;" // Slightly darker blue when hovered over
                          "}"
                          "QPushButton:pressed {"
                          "    background-color: #1a5276;" // Even darker when pressed
                          "}";

    ui->convertButton->setStyleSheet(buttonStyle);

    // Apply the style sheet to the QLineEdit
    QString lineEditStyle = "QLineEdit {"
                            "    background-color: #ecf0f1;" // Light gray background
                            "    color: #2c3e50;" // Dark blue text
                            "    border: 2px solid #2c3e50;" // Dark blue border
                            "    border-radius: 10px;" // Rounded corners
                            "    padding: 5px;" // Some padding
                            "}";

    ui->lineEdit_name->setStyleSheet(lineEditStyle);

    // Assuming this code is inside the constructor or initialization function
    ui->lineEdit_name->installEventFilter(this);


    // Apply the style sheet to the QLabel
    QString labelStyle = "QLabel {"
                         "    background-color: #ecf0f1;" // Light gray background
                         "    color: #2c3e50;" // Dark blue text
                         "    border: 2px solid #2c3e50;" // Dark blue border
                         "    border-radius: 10px;" // Rounded corners
                         "    padding: 5px;" // Some padding
                         "}";

    ui->label_ASCIIResult->setStyleSheet(labelStyle);



    // Connect signals and slots
    connect(ui->lineEdit_name, &QLineEdit::returnPressed, this, &nameconvertorMainWindow::onConvertButtonClicked);
    connect(ui->convertButton, &QPushButton::clicked, this, &nameconvertorMainWindow::onConvertButtonClicked);
    connect(ui->backButton,&QPushButton::clicked,[=](){
        emit this->backButton();
    });
}

// ...

bool nameconvertorMainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->lineEdit_name && event->type() == QEvent::MouseButtonPress) {
        // Handle the mouse press event
        ui->lineEdit_name->clear();
        return true; // Event handled
    }

    // Call the base class implementation for other events
    return QMainWindow::eventFilter(obj, event);
}

void nameconvertorMainWindow::cleartext() {
    ui->lineEdit_name->clear();
}

void nameconvertorMainWindow::onPlainTextEditTextChangedLength() {
    // Your implementation here
}

void nameconvertorMainWindow::onConvertNameToASCII() {
    // Get the input value from the QLineEdit
    QString name = ui->lineEdit_name->text();

    int maxLength = 30;  // Adjust the value as needed

    // Check if the input exceeds the maximum length
        if (name.length() > maxLength) {

            QMessageBox::critical(this, "Error", "Your name is too long ye sayang:)");
            return;

            } else if (name.length() <= maxLength && name.contains(QRegularExpression("^[a-zA-Z ]+$"))) {
                // Enable input if it's within the maximum length
                ui->lineEdit_name->setReadOnly(false);

                // Convert the name to ASCII
                QString asciiResult;
                for (QChar character : name) {
                asciiResult += QString::number(character.toLatin1()) + " ";
            }

            // Prepare the final message to display
            QString finalMessage = "" + asciiResult.trimmed();

            // Clear the label and set the new text
            ui->label_ASCIIResult->clear();
            ui->label_ASCIIResult->setPlainText(finalMessage);

            } else if (name.contains(QRegularExpression("[0-9!@#$%^&*()_+{}|:\"<>?`\\-=\\[\\];',./\\\\]"))){

                QMessageBox::critical(this, "Error", "Where got a person's name is number? Jangan main-main ye pandai:)");
                return;

            }
}

void nameconvertorMainWindow::onConvertButtonClicked() {
    // Trigger the conversion when the button is clicked
    onConvertNameToASCII();
}

nameconvertorMainWindow::~nameconvertorMainWindow()
{
    delete ui;
}
