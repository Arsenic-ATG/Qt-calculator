// calculator_tests.cpp
#include "calculator_tests.h"

void CalculatorTests::initTestCase() {
    window = new MainWindow(nullptr);
    unaryHandler = new Unary_operation_handler();
}

void CalculatorTests::cleanupTestCase() {
    delete window;
    delete unaryHandler;
}

void CalculatorTests::testInitialState() {
    QCOMPARE(window->findChild<QLabel*>("label")->text(), QString("0"));
    QCOMPARE(window->findChild<QLabel*>("label_2")->text(), QString("0"));
    QCOMPARE(window->findChild<QLabel*>("Error_Label")->text(), QString(""));
}

void CalculatorTests::testDigitButtons() {
    // Test clicking digits 0-9
    for(int i = 0; i < 10; i++) {
        QString buttonName = QString("pushButton_%1").arg(i);
        QPushButton* button = window->findChild<QPushButton*>(buttonName);
        QTest::mouseClick(button, Qt::LeftButton);

        // For first digit, it should replace the initial 0
        if(i == 1) {
            QCOMPARE(window->findChild<QLabel*>("label")->text(), QString::number(i));
        } else {
            // For subsequent digits, they should be appended
            QVERIFY(window->findChild<QLabel*>("label")->text().endsWith(QString::number(i)));
        }
    }
}

void CalculatorTests::testDecimalPoint() {
    window->findChild<QLabel*>("label")->setText("0");

    // Test single decimal point
    QTest::mouseClick(window->findChild<QPushButton*>("pushButton_dot"), Qt::LeftButton);
    QCOMPARE(window->findChild<QLabel*>("label")->text(), QString("0."));

    // Test that second decimal point is ignored
    QTest::mouseClick(window->findChild<QPushButton*>("pushButton_dot"), Qt::LeftButton);
    QCOMPARE(window->findChild<QLabel*>("label")->text(), QString("0."));
}

void CalculatorTests::testNegation() {
    window->findChild<QLabel*>("label")->setText("5");
    QPushButton* negateButton = window->findChild<QPushButton*>("pushButton_negate");
    QTest::mouseClick(negateButton, Qt::LeftButton);
    QCOMPARE(window->findChild<QLabel*>("label")->text(), QString("-5"));
}

void CalculatorTests::testSquareRoot() {
    window->findChild<QLabel*>("label")->setText("16");
    QPushButton* sqrtButton = window->findChild<QPushButton*>("pushButton_sqrt");
    QTest::mouseClick(sqrtButton, Qt::LeftButton);
    QCOMPARE(window->findChild<QLabel*>("label")->text(), QString("4"));
}

void CalculatorTests::testFactorial() {
    window->findChild<QLabel*>("label")->setText("5");
    QPushButton* factorialButton = window->findChild<QPushButton*>("pushButton_factorial");
    QTest::mouseClick(factorialButton, Qt::LeftButton);
    QCOMPARE(window->findChild<QLabel*>("label")->text(), QString("120"));
}

void CalculatorTests::testLogarithm() {
    // Test valid input
    window->findChild<QLabel*>("label")->setText("100");
    QPushButton* logButton = window->findChild<QPushButton*>("pushButton_Log");
    QTest::mouseClick(logButton, Qt::LeftButton);
    QCOMPARE(window->findChild<QLabel*>("label")->text(), QString("2"));

    // Test invalid input (negative number)
    window->findChild<QLabel*>("label")->setText("-1");
    QTest::mouseClick(logButton, Qt::LeftButton);
    QCOMPARE(window->findChild<QLabel*>("Error_Label")->text(),
             QString("Error message: Log input cant be less then 0"));
}

void CalculatorTests::testAddition() {
    window->findChild<QLabel*>("label")->setText("5");
    QPushButton* addButton = window->findChild<QPushButton*>("pushButton_add");
    QTest::mouseClick(addButton, Qt::LeftButton);

    window->findChild<QLabel*>("label")->setText("3");
    QPushButton* equalsButton = window->findChild<QPushButton*>("pushButton_equals");
    QTest::mouseClick(equalsButton, Qt::LeftButton);

    QCOMPARE(window->findChild<QLabel*>("label")->text(), QString("8"));
}

void CalculatorTests::testTrigonometricFunctions() {
    // Test sin in radians
    window->findChild<QComboBox*>("comboBox")->setCurrentIndex(0);
    window->findChild<QLabel*>("label")->setText("0");
    QPushButton* sinButton = window->findChild<QPushButton*>("pushButton_sin");
    QTest::mouseClick(sinButton, Qt::LeftButton);
    QCOMPARE(window->findChild<QLabel*>("label")->text(), QString("0"));

    // Test cos in degrees
    window->findChild<QComboBox*>("comboBox")->setCurrentIndex(1);
    window->findChild<QLabel*>("label")->setText("90");
    QPushButton* cosButton = window->findChild<QPushButton*>("pushButton_cos");
    QTest::mouseClick(cosButton, Qt::LeftButton);
    QVERIFY(qAbs(window->findChild<QLabel*>("label")->text().toDouble()) < 0.0001);
}

void CalculatorTests::testThemeChanges() {
    // Test dark theme
    QAction* darkAction = window->findChild<QAction*>("actionDark");
    darkAction->trigger();
    QVERIFY(window->findChild<QWidget*>("centralwidget")
                ->styleSheet().contains("background-color: #000"));

    // Test light theme
    QAction* lightAction = window->findChild<QAction*>("actionLight");
    lightAction->trigger();
    QVERIFY(window->findChild<QWidget*>("centralwidget")
                ->styleSheet().contains("background-color: #fff"));
}

void CalculatorTests::testPiConstant() {
    QPushButton* piButton = window->findChild<QPushButton*>("pushButton_pi");
    QTest::mouseClick(piButton, Qt::LeftButton);
    QVERIFY(qAbs(window->findChild<QLabel*>("label")->text().toDouble() - M_PI) < 0.0001);
}

void CalculatorTests::testMemoryOperations() {
    // Test previous answer functionality
    window->findChild<QLabel*>("label")->setText("10");
    QPushButton* equalsButton = window->findChild<QPushButton*>("pushButton_equals");
    QTest::mouseClick(equalsButton, Qt::LeftButton);

    QPushButton* ansButton = window->findChild<QPushButton*>("pushButton_previos_answer");
    QTest::mouseClick(ansButton, Qt::LeftButton);
    QCOMPARE(window->findChild<QLabel*>("label")->text(), QString("10"));
}

// Main function to run the tests
QTEST_MAIN(CalculatorTests)
#include "calculator_tests.moc"
