#include "loginwidget.h"
#include "controller/mainwindow.h"
#include "ui_loginwidget.h"
#include "util/util.h"
#include "view/registerwidget.h"
#include <QLabel>
#include <QByteArray>
#include <QJsonValue>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QDebug>

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
    User user = util->Login(ui->userEdit->text(), ui->passwordEdit->text());
    ui->Login->setEnabled(false);
    if (user.status == "200"){
        ui->Login->setEnabled(true);
        MainWindow *main = new MainWindow;
        main->show();
        this->close();
    }else {
        this->MessageBox(user.code);
        ui->Login->setEnabled(true);
    }
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

void LoginWidget::MessageBox(const QString &code)
{
    QMessageBox box;
    if (code == "USER_LOGIN_FAILED"){
        box.setText("登陆失败");
    }else if (code == "USER_NOT_FOUND"){
        box.setText("用户不存在");
    }else {
        box.setText("密码或者用户错误");
    }
    box.exec();
}
