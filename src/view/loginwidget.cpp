#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QLabel>

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
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
