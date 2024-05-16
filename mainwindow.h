#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numberPressed();
    void operationPressed();
    void equalsPressed();
    void clearPressed();

private:
    Ui::MainWindow *ui;

    double currentNumber = 0.0;
    double previousNumber = 0.0;
    QString currentOperation = "";
    bool isOperatorPressed = false;

    QLineEdit *display;
    QPushButton *button0;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;
    QPushButton *buttonDot;
    QPushButton *buttonPlus;
    QPushButton *buttonMinus;
    QPushButton *buttonMultiply;
    QPushButton *buttonDivide;
    QPushButton *buttonEquals;
    QPushButton *buttonClear;

    void updateDisplay(double value);
};

#endif
