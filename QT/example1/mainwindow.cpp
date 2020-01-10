#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = b = 0;

    ui -> lineEdit->setText(QString("0"));
    ui -> lineEdit_2 ->setText(QString("0"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_main_btn_clicked()
{
    ui ->result -> setNum(a + b);
}

void MainWindow::on_lineEdit_editingFinished()
{
    auto s = ui -> lineEdit ->text();
    a = s.toInt();
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    auto s = ui -> lineEdit_2 ->text();
    b = s.toInt();
}
