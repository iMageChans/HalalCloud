#include "mkdirwidget.h"
#include "ui_mkdirwidget.h"
#include "util/util.h"
#include "model/model.h"
#include <QByteArray>
#include <QDebug>

mkdirWidget::mkdirWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mkdirWidget)
{
    model = new Model;
    util = new Util;
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("输入文件夹名称");
}

mkdirWidget::~mkdirWidget()
{
    delete ui;
}

void mkdirWidget::on_Yes_clicked()
{
    QString name;
    if (ui->lineEdit->text().length() > 0)
    {
        name = ui->lineEdit->text();
    }else{
        name = "新建文件夹";
    }

    QByteArray data = util->createFiles(name, pach);
    if (model->getJsonBool(model->getByteArray(data,"success")))
    {
        emit sendClick(model->getJsonBool(model->getByteArray(data, "success")));
        this->close();
    }else{
        emit sendClick(model->getJsonBool(model->getByteArray(data, "success")));
        this->close();
    }
}

void mkdirWidget::on_No_clicked()
{
    this->close();
}


void mkdirWidget::getPath(const QString &Pach)
{
    if (Pach.length() > 0)
    {
        pach = Pach;
    }else{
        pach = "";
    }

}
