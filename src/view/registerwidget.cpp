#include "registerwidget.h"
#include "ui_registerwidget.h"
#include "view/loginwidget.h"

RegisterWidget::RegisterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);
    this->setupUI();
}

void RegisterWidget::setupUI()
{
    ui->name->setPlaceholderText("昵称");
    ui->username->setPlaceholderText("手机号码");
    ui->password->setPlaceholderText("密码");
    ui->code->setPlaceholderText("验证码");
}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

void RegisterWidget::on_back_clicked()
{
    LoginWidget *login = new LoginWidget;
    login->show();
    this->close();
}
