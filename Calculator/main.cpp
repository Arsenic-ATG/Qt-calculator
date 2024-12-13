#include "mainwindow.h"
#include "binary_operation_handler.h"
#include <QApplication>
#include <QGraphicsBlurEffect>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.setWindowOpacity(0.95);
    w.show();
    return a.exec();
}
