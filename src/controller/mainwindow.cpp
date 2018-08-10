#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util/util.h"
#include "view/loginwidget.h"
#include <QDebug>
#include <QListWidgetItem>
#include <QFileInfo>
#include <QFileDialog>
#include "util/multiparupload.h"

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

void MainWindow::on_MyFlies_itemClicked(QListWidgetItem *item)
{
    this->sendButtonState();

    if (ui->MyFlies->item(0) == item)
    {
        util->getPageFile("","/");
    }else if (ui->MyFlies->item(1) == item)
    {

    }else if (ui->MyFlies->item(2) == item)
    {

    }
}

void MainWindow::on_send_itemClicked(QListWidgetItem *item)
{
    this->fliesButtonState();

    if (ui->send->item(0) == item)
    {

    }else if (ui->send->item(1) == item)
    {

    }else if (ui->send->item(2) == item)
    {

    }else if (ui->send->item(3) == item)
    {

    }
}

void MainWindow::fliesButtonState()
{
    QListWidgetItem *item = ui->MyFlies->item(0);
    item->setSelected(false);
    QListWidgetItem *item1 = ui->MyFlies->item(1);
    item1->setSelected(false);
    QListWidgetItem *item2 = ui->MyFlies->item(2);
    item2->setSelected(false);
}

void MainWindow::sendButtonState()
{
    QListWidgetItem *item = ui->send->item(0);
    item->setSelected(false);
    QListWidgetItem *item1 = ui->send->item(1);
    item1->setSelected(false);
    QListWidgetItem *item2 = ui->send->item(2);
    item2->setSelected(false);
    QListWidgetItem *item3 = ui->send->item(3);
    item3->setSelected(false);
}

void MainWindow::on_upload_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this);

    QFileInfo files = QFileInfo(dir);

    MultiparUpload *upload = new MultiparUpload;
    upload->setDefaultInfo(files, "", "");

}
