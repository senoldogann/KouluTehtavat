#include "mainwindow.h"
#include <QGridLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), state(1), result(0), operand(0)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    QGridLayout *layout = new QGridLayout(centralWidget);
    layout->setSpacing(2);  
    layout->setContentsMargins(5, 5, 5, 5);  

    num1LineEdit = new QLineEdit(this);
    num2LineEdit = new QLineEdit(this);
    resultLineEdit = new QLineEdit(this);
    
    QString lineEditStyle = "QLineEdit { "
                          "background-color: #f0f0f0; "
                          "border: 1px solid #ccc; "
                          "border-radius: 4px; "
                          "padding: 5px; "
                          "font-size: 14px; }";
    
    QString activeLineEditStyle = lineEditStyle + 
                                "QLineEdit { "
                                "border: 2px solid #007bff; "
                                "background-color: white; }";
    
    num1LineEdit->setReadOnly(true);
    num2LineEdit->setReadOnly(true);
    resultLineEdit->setReadOnly(true);
    
    num1LineEdit->setStyleSheet(activeLineEditStyle);
    num2LineEdit->setStyleSheet(lineEditStyle);
    resultLineEdit->setStyleSheet(lineEditStyle);
    
    num1LineEdit->setMinimumHeight(30);
    num2LineEdit->setMinimumHeight(30);
    resultLineEdit->setMinimumHeight(30);
    
    layout->addWidget(new QLabel("Number 1"), 0, 0);
    layout->addWidget(new QLabel("Number 2"), 0, 1);
    layout->addWidget(new QLabel("Result"), 0, 2);
    
    layout->addWidget(num1LineEdit, 1, 0);
    layout->addWidget(num2LineEdit, 1, 1);
    layout->addWidget(resultLineEdit, 1, 2);

    for(int i = 0; i < 10; i++) {
        QPushButton *button = createButton(QString::number(i));
        connect(button, &QPushButton::clicked, this, &MainWindow::numberButtonClicked);
        layout->addWidget(button, 2 + (i / 3), i % 3);
    }

    QPushButton *addButton = createButton("+");
    QPushButton *subButton = createButton("-");
    QPushButton *mulButton = createButton("*");
    QPushButton *divButton = createButton("/");
    
    connect(addButton, &QPushButton::clicked, this, &MainWindow::operatorButtonClicked);
    connect(subButton, &QPushButton::clicked, this, &MainWindow::operatorButtonClicked);
    connect(mulButton, &QPushButton::clicked, this, &MainWindow::operatorButtonClicked);
    connect(divButton, &QPushButton::clicked, this, &MainWindow::operatorButtonClicked);

    layout->addWidget(addButton, 2, 3);
    layout->addWidget(subButton, 3, 3);
    layout->addWidget(mulButton, 4, 3);
    layout->addWidget(divButton, 5, 3);

    QPushButton *clearButton = createButton("clear");
    QPushButton *equalsButton = createButton("=");
    
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearButtonClicked);
    connect(equalsButton, &QPushButton::clicked, this, &MainWindow::enterButtonClicked);

    layout->addWidget(clearButton, 5, 1);
    layout->addWidget(equalsButton, 5, 2);

    setWindowTitle("Calculator");
    setFixedSize(300, 400);

    
    clearButtonClicked();
}

QPushButton* MainWindow::createButton(const QString &text)
{
    QPushButton *button = new QPushButton(text, this);
    
    // Temel buton stili
    QString baseStyle = "QPushButton { "
                       "border: 1px solid #999; "
                       "border-radius: 4px; "
                       "background-color: #f8f9fa; "
                       "font-size: 14px; "
                       "} "
                       "QPushButton:hover { "
                       "background-color: #e9ecef; "
                       "} "
                       "QPushButton:pressed { "
                       "background-color: #dee2e6; "
                       "}";

    if (text == "enter" || text == "clear") {
        button->setFixedSize(70, 50);
        QString specialStyle = baseStyle + 
                             "QPushButton { "
                             "font-weight: bold; "
                             "background-color: #007bff; "
                             "color: white; "
                             "} "
                             "QPushButton:hover { "
                             "background-color: #0056b3; "
                             "}";
        button->setStyleSheet(specialStyle);
    } else if (text == "+" || text == "-" || text == "*" || text == "/") {
        button->setFixedSize(50, 50);
        QString operatorStyle = baseStyle +
                              "QPushButton { "
                              "background-color: #ffc107; "
                              "font-weight: bold; "
                              "} "
                              "QPushButton:hover { "
                              "background-color: #e0a800; "
                              "}";
        button->setStyleSheet(operatorStyle);
    } else {
        // Sayı butonları için normal stil
        button->setFixedSize(50, 50);
        button->setStyleSheet(baseStyle);
    }
    
    return button;
}

void MainWindow::numberButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (state == 1) {
        if (!resultLineEdit->text().isEmpty()) {
            number1.clear();
            number2.clear();
            result = 0;
            operand = 0;
            num1LineEdit->clear();
            num2LineEdit->clear();
            resultLineEdit->clear();
            
            QString lineEditStyle = "QLineEdit { "
                                  "background-color: #f0f0f0; "
                                  "border: 1px solid #ccc; "
                                  "border-radius: 4px; "
                                  "padding: 5px; "
                                  "font-size: 14px; }";
            
            QString activeLineEditStyle = lineEditStyle + 
                                        "QLineEdit { "
                                        "border: 2px solid #007bff; "
                                        "background-color: white; }";
            
            num1LineEdit->setStyleSheet(activeLineEditStyle);
            num2LineEdit->setStyleSheet(lineEditStyle);
            resultLineEdit->setStyleSheet(lineEditStyle);
        }
        
        number1 += button->text();
        num1LineEdit->setText(number1);
    } else if (state == 2) {
        number2 += button->text();
        num2LineEdit->setText(number2);
    }
}

void MainWindow::operatorButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (!number1.isEmpty() && !number2.isEmpty() && operand != 0) {
        calculateResult();
    }

    if (number1.isEmpty()) {
        return;
    }

    QString op = button->text();
    if (op == "+") operand = 1;
    else if (op == "-") operand = 2;
    else if (op == "*") operand = 3;
    else if (op == "/") operand = 4;

    state = 2;
    QString lineEditStyle = "QLineEdit { "
                          "background-color: #f0f0f0; "
                          "border: 1px solid #ccc; "
                          "border-radius: 4px; "
                          "padding: 5px; "
                          "font-size: 14px; }";
    
    QString activeLineEditStyle = lineEditStyle + 
                                "QLineEdit { "
                                "border: 2px solid #007bff; "
                                "background-color: white; }";
    
    num1LineEdit->setStyleSheet(lineEditStyle);
    num2LineEdit->setStyleSheet(activeLineEditStyle);
    resultLineEdit->setStyleSheet(lineEditStyle);
}

void MainWindow::calculateResult()
{
    bool ok1, ok2;
    float num1 = number1.toFloat(&ok1);
    float num2 = number2.toFloat(&ok2);

    if (!ok1 || !ok2) {
        resultLineEdit->setText("Error");
        return;
    }

    switch(operand) {
        case 1: 
            result = num1 + num2; 
            break;
        case 2: 
            result = num1 - num2; 
            break;
        case 3: 
            result = num1 * num2; 
            break;
        case 4: 
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                resultLineEdit->setText("Error: Div by 0");
                return;
            }
            break;
        default:
            return;
    }

    QString resultStr;
    if (result == (int)result) {
        resultStr = QString::number((int)result);
    } else {
        resultStr = QString::number(result, 'f', 2);
    }
    
    resultLineEdit->setText(resultStr);
    
    number1 = QString::number(result);
    num1LineEdit->clear();
    number2.clear();
    num2LineEdit->clear();
    state = 1;   
}

void MainWindow::clearButtonClicked()
{
    state = 1;
    number1.clear();
    number2.clear();
    result = 0;
    operand = 0;
    resetLineEdits();
    
    QString lineEditStyle = "QLineEdit { "
                          "background-color: #f0f0f0; "
                          "border: 1px solid #ccc; "
                          "border-radius: 4px; "
                          "padding: 5px; "
                          "font-size: 14px; }";
    
    QString activeLineEditStyle = lineEditStyle + 
                                "QLineEdit { "
                                "border: 2px solid #007bff; "
                                "background-color: white; }";
    
    num1LineEdit->setStyleSheet(activeLineEditStyle);
    num2LineEdit->setStyleSheet(lineEditStyle);
    resultLineEdit->setStyleSheet(lineEditStyle);
}

void MainWindow::enterButtonClicked()
{
    if (state == 1) {
        if (!number1.isEmpty()) {
            state = 2;
        }
        return;
    }

    if (!number1.isEmpty() && !number2.isEmpty() && operand != 0) {
        calculateResult();
    }
}

void MainWindow::resetLineEdits()
{
    num1LineEdit->clear();
    num2LineEdit->clear();
    resultLineEdit->clear();
}

MainWindow::~MainWindow()
{
} 