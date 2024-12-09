// calculator_tests.h
#ifndef CALCULATOR_TESTS_H
#define CALCULATOR_TESTS_H

#include <QTest>
#include <QSignalSpy>
#include "mainwindow.h"
#include "unary_operation_handler.h"
#include "ui_mainwindow.h"

class CalculatorTests : public QObject
{
    Q_OBJECT

private:
    MainWindow* window;
    Unary_operation_handler* unaryHandler;

private slots:
    // Setup and cleanup
    void initTestCase();
    void cleanupTestCase();

    // UI Element Tests
    void testInitialState();
    void testDigitButtons();
    void testDecimalPoint();

    // Unary Operation Tests
    void testNegation();
    void testSquareRoot();
    void testFactorial();
    void testLogarithm();

    // Binary Operation Tests
    void testAddition();
    void testTrigonometricFunctions();

    // Theme Tests
    void testThemeChanges();

    // Special Number Tests
    void testPiConstant();
    void testMemoryOperations();
};

#endif // CALCULATOR_TESTS_H
