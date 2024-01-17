// do not try to play with comments
#include "binary_operation_handler.h"

Binary_Operation_Handler::Binary_Operation_Handler()
{

}

void Binary_Operation_Handler::Binary_operation_pressed(Ui::MainWindow* ui,QPushButton* button){
    ui->Error_Label->setText("");
    ui->label_2->setText(ui->label->text() + " " + button->text());

    ui->label->setText("0");
}

