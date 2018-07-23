#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util.h"
#include "multiparupload.h"
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
    MultiparUpload *upload = new MultiparUpload;
    util->Login("15618537992","bin258963");
    QString Token = util->JsonToString(util->getJson(util->JsonData, "token"));
    qDebug() << Token;
    util->getFilesList(Token,"","","");
    util->getPageFile(Token,"","");
    util->getFilesInfo(Token,"1820","");
    util->createFiles(Token,"moximoxipayaya","/");
//    util->moveFiles(Token,"1831","","");
    util->renameFiles(Token,"1831","","payaya");
    util->recycleFiles(Token,"1831","");
    util->removeFiles(Token,"1831","");

}

MainWindow::~MainWindow()
{
    delete ui;
}
