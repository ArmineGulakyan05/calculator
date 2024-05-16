#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFixedHeight(50); // Increase the height of the display

    button0 = new QPushButton("0");
    button1 = new QPushButton("1");
    button2 = new QPushButton("2");
    button3 = new QPushButton("3");
    button4 = new QPushButton("4");
    button5 = new QPushButton("5");
    button6 = new QPushButton("6");
    button7 = new QPushButton("7");
    button8 = new QPushButton("8");
    button9 = new QPushButton("9");
    buttonDot = new QPushButton(".");
    buttonPlus = new QPushButton("+");
    buttonMinus = new QPushButton("-");
    buttonMultiply = new QPushButton("*");
    buttonDivide = new QPushButton("/");
    buttonEquals = new QPushButton("=");
    buttonClear = new QPushButton("C");

    connect(button0, SIGNAL(clicked()), this, SLOT(numberPressed()));
    connect(button1, SIGNAL(clicked()), this, SLOT(numberPressed()));
    connect(button2, SIGNAL(clicked()), this, SLOT(numberPressed()));
    connect(button3, SIGNAL(clicked()), this, SLOT(numberPressed()));
    connect(button4, SIGNAL(clicked()), this, SLOT(numberPressed()));
    connect(button5, SIGNAL(clicked()), this, SLOT(numberPressed()));
    connect(button6, SIGNAL(clicked()), this, SLOT(numberPressed()));
    connect(button7, SIGNAL(clicked()), this, SLOT(numberPressed()));
    connect(button8, SIGNAL(clicked()), this, SLOT(numberPressed()));
    connect(button9, SIGNAL(clicked()), this, SLOT(numberPressed()));
    connect(buttonDot, SIGNAL(clicked()), this, SLOT(numberPressed()));

    connect(buttonPlus, SIGNAL(clicked()), this, SLOT(operationPressed()));
    connect(buttonMinus, SIGNAL(clicked()), this, SLOT(operationPressed()));
    connect(buttonMultiply, SIGNAL(clicked()), this, SLOT(operationPressed()));
    connect(buttonDivide, SIGNAL(clicked()), this, SLOT(operationPressed()));

    connect(buttonEquals, SIGNAL(clicked()), this, SLOT(equalsPressed()));
    connect(buttonClear, SIGNAL(clicked()), this, SLOT(clearPressed()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(display);

    QHBoxLayout *numberLayout1 = new QHBoxLayout;
    numberLayout1->addWidget(button7);
    numberLayout1->addWidget(button8);
    numberLayout1->addWidget(button9);
    numberLayout1->addWidget(buttonDivide);

    QHBoxLayout *numberLayout2 = new QHBoxLayout;
    numberLayout2->addWidget(button4);
    numberLayout2->addWidget(button5);
    numberLayout2->addWidget(button6);
    numberLayout2->addWidget(buttonMultiply);

    QHBoxLayout *numberLayout3 = new QHBoxLayout;
    numberLayout3->addWidget(button1);
    numberLayout3->addWidget(button2);
    numberLayout3->addWidget(button3);
    numberLayout3->addWidget(buttonMinus);

    QHBoxLayout *numberLayout4 = new QHBoxLayout;
    numberLayout4->addWidget(button0);
    numberLayout4->addWidget(buttonDot);
    numberLayout4->addWidget(buttonClear);
    numberLayout4->addWidget(buttonPlus);

    QHBoxLayout *equalsLayout = new QHBoxLayout;
    equalsLayout->addWidget(buttonEquals);

    mainLayout->addLayout(numberLayout1);
    mainLayout->addLayout(numberLayout2);
    mainLayout->addLayout(numberLayout3);
    mainLayout->addLayout(numberLayout4);
    mainLayout->addLayout(equalsLayout);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString buttonText = button->text();

    if (isOperatorPressed)
    {
        currentNumber = 0.0;
        isOperatorPressed = false;
    }

    if (buttonText == ".")
    {
        if (!display->text().contains("."))
        {
            currentNumber = currentNumber * 10 + buttonText.toDouble();
            updateDisplay(currentNumber);
        }
    }
    else
    {
        currentNumber = currentNumber * 10 + buttonText.toDouble();
        updateDisplay(currentNumber);
    }
}

void MainWindow::operationPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString buttonText = button->text();

    previousNumber = currentNumber;
    currentOperation = buttonText;
    isOperatorPressed = true;
}

void MainWindow::equalsPressed()
{
    double result = 0.0;

    if (currentOperation == "+")
    {
        result = previousNumber + currentNumber;
    }
    else if (currentOperation == "-")
    {
        result = previousNumber - currentNumber;
    }
    else if (currentOperation == "*")
    {
        result = previousNumber * currentNumber;
    }
    else if (currentOperation == "/")
    {
        if (currentNumber == 0.0)
        {
         //   updateDisplay("Error");
            return;
        }
        result = previousNumber / currentNumber;
    }

    updateDisplay(result);
    currentNumber = result;
    previousNumber = 0.0;
    currentOperation = "";
    isOperatorPressed = false;
}

void MainWindow::clearPressed()
{
    currentNumber = 0.0;
    previousNumber = 0.0;
    currentOperation = "";
    isOperatorPressed = false;
    updateDisplay(0.0);
}

void MainWindow::updateDisplay(double value)
{
    display->setText(QString::number(value, 'g', 10));
}
