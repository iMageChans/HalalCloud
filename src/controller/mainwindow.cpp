#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util/util.h"
#include "view/loginwidget.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    util = new Util;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    ui->name->setText(user.result.name);
    ui->capacity->setText(this->kb_to_gb(user.result.spaceUsed) + "/" + kb_to_gb(user.result.spaceCapacity));

    ui->progressBar->setOrientation(Qt::Horizontal);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(this->progressInt(user.result.spaceUsed,user.result.spaceCapacity));
}


void MainWindow::on_Loginout_clicked()
{
    util->LoginOut();
    LoginWidget *login = new LoginWidget;
    login->show();
    this->close();
}


void MainWindow::userSend(User data)
{
    user = data;
    this->setupUI();
}

QString MainWindow::kb_to_gb(QString number)
{
    double data = number.toDouble();
    return QString::number(data / 1024);
}

int MainWindow::progressInt(QString used, QString capacity)
{
    int use = used.toInt();
    int cap = capacity.toInt();

    return use / cap;
}

void MainWindow::on_dilatation_clicked()
{

}
