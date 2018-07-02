#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util.h"
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
    //util->Login("15618537992","bin258963");
    //QJsonValue data = util->getJson(util->JsonData, "token");
    //util->LoginOut(time.toTime_t());
    //util->getFilesList(util->getToken(),"","",1,-1);
//    QString file_path = QFileDialog::getOpenFileName(this,"请选择模板保存路径...","./");
//    util->getFilesHash(file_path);
}

MainWindow::~MainWindow()
{
    delete ui;
}
