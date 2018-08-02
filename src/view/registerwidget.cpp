#include "registerwidget.h"
#include "ui_registerwidget.h"
#include "view/loginwidget.h"
#include "controller/mainwindow.h"
#include "util/util.h"
#include <QRegExp>
#include <QValidator>
#include <QMessageBox>
#include <QTimer>

RegisterWidget::RegisterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWidget)
{
    util = new Util;
    ui->setupUi(this);
    this->setupUI();
}

void RegisterWidget::setupUI()
{
    ui->name->setPlaceholderText("昵称");
    ui->username->setPlaceholderText("手机号码");
    ui->password->setPlaceholderText("密码");
    ui->code->setPlaceholderText("验证码");

    QRegExp regx("[0-9]+$");
    QValidator *username = new QRegExpValidator(regx, ui->username);
    ui->username->setValidator(username);
    QValidator *code = new QRegExpValidator(regx, ui->code);
    ui->code->setValidator(code);
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

void RegisterWidget::on_regis_clicked()
{
    User user = util->Registers(ui->name->text(), reg.result, ui->password->text(), ui->code->text());
    ui->regis->setEnabled(false);
    ui->regis->setStyleSheet("background:rgb(215, 215, 215);border:none;color:rgb(255, 255, 255);border:1px rgb(255, 255, 255);border-radius:5px;");
    if (user.status == "200"){
        util->systemConfig("token", user.token, "AotuLogin");
        util->systemConfig("username", user.result.phone, "AotuLogin");
        LoginWidget *login = new LoginWidget;
        login->show();
        this->close();
    }else {
        this->MessageBox(user.code);
        ui->regis->setEnabled(true);
        ui->regis->setStyleSheet("background:rgb(46, 193, 124);border:none;color:rgb(255, 255, 255);border:1px rgb(255, 255, 255);border-radius:5px;");
    }
}

void RegisterWidget::MessageBox(const QString &code)
{
    QMessageBox box;
    if (code == "USER_PHONE_EXIST"){
        box.setText("用户已存在");
    }else if (code == "PHONE_NOT_VALIDATE"){
        box.setText("没有此手机号码");
    }else {
        box.setText("注册失败");
    }
    box.exec();
}

void RegisterWidget::on_codeButton_clicked()
{
    reg = util->Cap(ui->username->text());
    ui->codeButton->setEnabled(false);
    msgTime = 60;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTimelimit()));
    timer->start( 1000 );
}


void RegisterWidget::showTimelimit()
{
    if(msgTime != 0)
     {
         msgTime -= 1; //注意字符类型
         QString num = QString::number(msgTime);
         ui->codeButton->setText(num);
     }
     else
     {
        ui->codeButton->setEnabled(true);
        ui->codeButton->setText("获取验证码");
     }

}
