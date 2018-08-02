#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "util/util.h"
#include "model/model.h"
#include "view/registerwidget.h"
#include <QLabel>
#include <QByteArray>
#include <QJsonValue>
#include <QDesktopServices>
#include <QUrl>

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    util = new Util;
    ui->setupUi(this);
    this->setupUI();

    connect(ui->autoLogin, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));
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

void LoginWidget::onStateChanged(int state)
{
    if (state == Qt::Checked){
        ui->savePassword->setCheckState(Qt::Checked);
    }
}

void LoginWidget::on_regis_clicked()
{
    RegisterWidget *reg = new RegisterWidget;
    reg->show();
    this->close();
}

void LoginWidget::on_forget_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("http://www.baidu.com/")));
}
