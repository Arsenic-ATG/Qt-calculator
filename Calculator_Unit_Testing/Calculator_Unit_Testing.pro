QT += testlib
QT += core gui
CONFIG += qt warn_on depend_includepath testcase
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

SOURCES +=  tst_unit_tests.cpp \
    ../Calculator/mainwindow.cpp


HEADERS += \
    ../Calculator/mainwindow.h
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    ../Calculator/mainwindow.ui
