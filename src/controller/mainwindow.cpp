#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util/util.h"
#include "util/multiparupload.h"
#include <QDebug>
#include <QJsonValue>
#include <QDateTime>
#include <QFileInfo>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Util *util = new Util;
    util->Login("15618537992","bin258963");
}

MainWindow::~MainWindow()
{
    delete ui;
}
