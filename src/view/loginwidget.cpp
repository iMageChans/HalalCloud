#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "util/util.h"
#include "model/model.h"
#include <QLabel>
#include <QByteArray>
#include <QJsonValue>

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
    ui->userEdit->setPlaceholderText("用户名");
    ui->passwordEdit->setPlaceholderText("密码");
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
    QByteArray Data = util->Login(ui->userEdit->text(), ui->passwordEdit->text());
    Model *model = new Model;
    model->getUserInfo(Data);
}
