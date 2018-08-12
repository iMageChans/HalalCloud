#include "mkdirhlep.h"
#include "ui_mkdirhlep.h"
#include <QTimer>

mkdirHlep::mkdirHlep(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mkdirHlep)
{
    ui->setupUi(this);

    autoTime = 1;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTimelimit()));
    timer->start(500);
}

void mkdirHlep::helpText(const QString &help)
{
    ui->label->setText(help);
}

mkdirHlep::~mkdirHlep()
{
    delete ui;
}

void mkdirHlep::showTimelimit()
{
    if(autoTime != 0)
     {
         autoTime -= 1;
     }
     else
     {
        this->close();
        timer->stop();
     }

}
