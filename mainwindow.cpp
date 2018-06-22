#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util.h"
#include <QDebug>
#include <QJsonValue>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Util *util = new Util;
    util->Login("15618537992","bin258963");
    QJsonValue data = util->getJson(util->JsonData, "token");
    qDebug() << util->getToken();
}

MainWindow::~MainWindow()
{
    delete ui;
}
