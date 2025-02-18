#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QString number1, number2;    
    int state;                   
    float result;               
    short operand;              

    QLineEdit *num1LineEdit;
    QLineEdit *num2LineEdit;
    QLineEdit *resultLineEdit;
    
    QPushButton *createButton(const QString &text);
    void calculateResult();     

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numberButtonClicked();
    void operatorButtonClicked();
    void clearButtonClicked();
    void enterButtonClicked();
    void resetLineEdits();
};

#endif 