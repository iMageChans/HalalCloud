#include "model.h"
#include <QJsonValue>
#include <QDebug>

Model::Model(QObject *parent) : QObject(parent)
{

}

userInfo Model::getUserInfo(const QJsonValue Data)
{
    qDebug() << Data;
}
