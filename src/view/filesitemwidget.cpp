#include "filesitemwidget.h"
#include "ui_filesitemwidget.h"
#include <QDebug>
#include <QDateTime>

FilesItemWidget::FilesItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilesItemWidget)
{
    ui->setupUi(this);
}

FilesItemWidget::~FilesItemWidget()
{
    delete ui;
}

void FilesItemWidget::setName(const QString &name)
{
    ui->Name->setText(name);
}

void FilesItemWidget::setCapacity(long Size)
{
    QString size = QString::number(Size / 1024 / 1024);
    ui->capacity->setText(size + "G");
}

void FilesItemWidget::setTime(long time)
{
    QString Time = QDateTime::fromTime_t(uint(time / 1000)).toString("yyyy.MM.dd hh:mm");
    ui->Timer->setText(Time);
}

void FilesItemWidget::setTextColor(const QString &Color){
    ui->Name->setStyleSheet(Color);
    ui->capacity->setStyleSheet(Color);
    ui->Timer->setStyleSheet(Color);
}
