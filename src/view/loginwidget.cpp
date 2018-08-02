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
#include <QTimer>

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    util = new Util;
    ui->setupUi(this);
    this->setupUI();

    ui->userEdit->setText(util->getSystemConfig("username","AotuLogin"));

    connect(ui->autoLogin, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));
}

void LoginWidget::setupUI()
{
    ui->userEdit->setPlaceholderText("用户名");
    ui->passwordEdit->setPlaceholderText("密码");

    if(util->getSystemConfig("autoLogin", "AotuLogin") == "2")
    {
        ui->autoLogin->setCheckState(Qt::Checked);
        ui->savePassword->setCheckState(Qt::Checked);
        ui->Login->setEnabled(false);
        ui->Login->setStyleSheet("background:rgb(215, 215, 215);border:none;color:rgb(255, 255, 255);border:1px rgb(255, 255, 255);border-radius:5px;");
        autoTime = 0.5;
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(showTimelimit()));
        timer->start(1000);
    }
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
    qDebug() << user.code;
    ui->Login->setEnabled(false);
    ui->Login->setStyleSheet("background:rgb(215, 215, 215);border:none;color:rgb(255, 255, 255);border:1px rgb(255, 255, 255);border-radius:5px;");
    if (user.status == "200"){
        util->systemConfig("username", user.result.phone, "AotuLogin");
        MainWindow *main = new MainWindow;
        main->show();
        this->close();
    }else {
        this->MessageBox(user.code);
        ui->Login->setEnabled(true);
        ui->Login->setStyleSheet("background:rgb(46, 193, 124);border:none;color:rgb(255, 255, 255);border:1px rgb(255, 255, 255);border-radius:5px;");
    }
}

void LoginWidget::onStateChanged(int state)
{
    if (state == Qt::Checked){
        ui->savePassword->setCheckState(Qt::Checked);
    }
    util->systemConfig("autoLogin", QString::number(state), "AotuLogin");
    util->systemConfig("savePassword", QString::number(state), "AotuLogin");
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
    }else if (code == "{PASSWORD}_REQUIRED") {
        box.setText("密码不能为空");
    }else if (code == "{PHONE}_REQUIRED") {
        box.setText("用户不能为空");
    }else{
        box.setText("登陆失败");
    }
    box.exec();
}

void LoginWidget::autoLogins()
{
    if(ui->autoLogin->isChecked() == true)
    {
        User user = util->getUserInfo();
        if (user.status == "200")
        {
            MainWindow *main = new MainWindow;
            main->show();
            this->close();
        }else if(user.code == "CREDENTIALS_REQUIRED"){
            QMessageBox box;
            box.setText("登陆过期，请重新登陆");
            box.exec();
            ui->Login->setEnabled(true);
            ui->Login->setStyleSheet("background:rgb(46, 193, 124);border:none;color:rgb(255, 255, 255);border:1px rgb(255, 255, 255);border-radius:5px;");
        }
    }

}

void LoginWidget::showTimelimit()
{
    if(autoTime != 0)
     {
         autoTime -= 1;
     }
     else
     {
        this->autoLogins();
        timer->stop();
     }

}
