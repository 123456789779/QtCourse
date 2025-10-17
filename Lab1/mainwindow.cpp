#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtDebug>
#include<math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    digitBTNs = {{Qt::Key_0, ui->btnNum0},
        {Qt::Key_1, ui->btnNum1},
        {Qt::Key_2, ui->btnNum2},
        {Qt::Key_3, ui->btnNum3},
        {Qt::Key_4, ui->btnNum4},
        {Qt::Key_5, ui->btnNum5},
        {Qt::Key_6, ui->btnNum6},
        {Qt::Key_7, ui->btnNum7},
        {Qt::Key_8, ui->btnNum8},
        {Qt::Key_9, ui->btnNum9},
    };

    operatorBTNs = {
        {Qt::Key_Plus, ui->btnPlus},       // +
        {Qt::Key_Minus, ui->btnMinus},     // -
        {Qt::Key_Asterisk, ui->btnMultiple},// *
        {Qt::Key_Slash, ui->btnDivide},    // /
        {Qt::Key_Equal, ui->btnEqual},     // =
        {Qt::Key_Return, ui->btnEqual},    // 回车键也映射到等于
        {Qt::Key_Enter, ui->btnEqual}      // 小键盘回车键也映射到等于
    };

    foreach (auto btn, digitBTNs )
        connect(btn, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum0, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum1, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum2, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum3, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum4, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum5, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum6, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum7, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum8, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum9, SIGNAL(clicked()), this, SLOT(btnNumClicked()));

    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiple, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));

    connect(ui->btnPercentage, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//2)按键事件处理，完成操作数的输入，小数点的处理，退格操作
void MainWindow::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton *>(sender())->text();
    if (operand == "0" || ui->display->text() == "0") {
        operand = digit;
    } else {
        operand += digit;
    }
    ui->display->setText(operand);
}


void MainWindow::on_btnPeriod_clicked()
{
    if (!operand.contains("."))
        operand += qobject_cast<QPushButton *>(sender())->text();
    ui->display->setText(operand);
}


void MainWindow::on_btnDel_clicked()
{
    operand = operand.left(operand.length() - 1);
    ui->display->setText(operand);
}


void MainWindow::on_btnClear_clicked()
{
    operand.clear();
    operands.clear();
    opcodes.clear();
    ui->display->setText(operand);
}
void MainWindow::on_btnClearAlll_clicked()
{
    operand.clear();
    operands.clear();
    opcodes.clear();
    ui->display->setText(operand);
}
//3)双操作符处理，完成计算器逻辑代码
QString MainWindow::calculation(bool *ok)
{
    double result = 0;
    if (operands.size() == 2 && opcodes.size() > 0) {
        //取数
        double operand1 = operands.front().toDouble();
        operands.pop_front();
        double operand2 = operands.front().toDouble();
        operands.pop_front();
        //取操作符
        QString op = opcodes.front();
        opcodes.pop_front();
        if (op == "+") {
            result = operand1 + operand2;
        } else if (op == "-") {
            result = operand1 - operand2;
        } else if (op == "×") {
            result = operand1 * operand2;
        } else if (op == "/") {
            result = operand1 / operand2;
        }
        operands.push_back(QString::number(result));
    }
    return QString::number(result);

}
void MainWindow::btnBinaryOperatorClicked()
{
    QString opcode = qobject_cast<QPushButton *>(sender())->text();
    if (operand != "") {
        operands.push_back(operand);
        operand = "";
        opcodes.push_back(opcode);
        QString result = calculation();
        ui->display->setText(result);
    }
}
void MainWindow::on_btnEqual_clicked()
{
    if (operand != "") {
        operands.push_back(operand);
        operand = "";
    }
    QString result = calculation();
    ui->display->setText(result);
}
//4)单操作符处理
void MainWindow::btnUnaryOperatorClicked()
{
    if (operand != "") {
        double result = operand.toDouble();
        operand = "";
        QString op = qobject_cast<QPushButton *>(sender())->text();

        if (op == "%") {
            result /= 100.0;
        } else if (op == "1/x") {
            result = 1 / result;
        } else if (op == "√") {
            result = sqrt(result);
        } else if (op == "x^2") {
            result = result * result;
        }
        ui->display->setText(QString::number(result));
    }
}


void MainWindow::on_btnSign_clicked()
{
    if (operand.isEmpty()) {
        operand = "0";
    }
    if (operand.startsWith('-')) {
        operand = operand.mid(1);
    } else {
        operand = "-" + operand;
    }
    ui->display->setText(operand);
}
//键盘事件
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach (auto btnKey, digitBTNs.keys()) {
        if (event->key() == btnKey) {
            digitBTNs[btnKey]->animateClick(100);
            return;
        }
    }
    foreach (auto btnKey, operatorBTNs.keys()) {
        if (event->key() == btnKey) {
            operatorBTNs[btnKey]->animateClick(100);
            return;
        }
    }
    if (event->key() == Qt::Key_Backspace) {
        ui->btnDel->animateClick(100);
        return;
    }
}

