#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "util/util.h"
#include <QLabel>

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    util = new Util;
    ui->setupUi(this);
    this->setupUI();
}

void LoginWidget::setupUI()
{

}

void LoginWidget::setupTitleIcon()
{


}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::on_Login_clicked()
{
    util->Login(ui->userEdit->text(), ui->passwordEdit->text());
}
