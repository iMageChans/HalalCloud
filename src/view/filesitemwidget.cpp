#include "filesitemwidget.h"
#include "ui_filesitemwidget.h"
#include <QDebug>

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

void FilesItemWidget::on_pushButton_2_clicked(bool checked)
{
    qDebug() << checked;
}
