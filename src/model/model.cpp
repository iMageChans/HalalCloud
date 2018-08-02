#include "model.h"
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QDebug>

Model::Model(QObject *parent) : QObject(parent)
{

}

User Model::getUser(const QByteArray &Data)
{
    users.status = this->JsonToString(this->getByteArray(Data, "status"));
    users.success = this->JsonToString(this->getByteArray(Data, "success"));

    if (users.status == "200")
    {
        users.result = this->getUserInfo(this->getByteArray(Data, "result"));
        users.token = this->JsonToString(this->getByteArray(Data, "token"));
    }else{
        users.message = this->JsonToString(this->getByteArray(Data, "message"));
        users.code = this->JsonToString(this->getByteArray(Data, "code"));
    }

    return users;
}

UserInfo Model::getUserInfo(const QJsonValue &Data)
{
    userInfo.name = this->JsonToString(this->getJson(Data, "name"));
    userInfo.icon = this->JsonToString(this->getJson(Data, "icon"));
    userInfo.uuid = this->JsonToString(this->getJson(Data, "uuid"));
    userInfo.phone = this->JsonToString(this->getJson(Data, "phone"));
    userInfo.spaceCapacity = this->JsonToString(this->getJson(Data, "spaceCapacity"));
    userInfo.spaceUsed = this->JsonToString(this->getJson(Data, "spaceUsed"));
    return userInfo;
}

Register Model::getRegister(const QByteArray &Data)
{
    reg.status = this->JsonToString(this->getByteArray(Data, "status"));
    reg.result = this->JsonToString(this->getByteArray(Data, "result"));
    return reg;
}

QJsonValue Model::getByteArray(const QByteArray &data, const QString &key){
    QJsonParseError jsonError;
    QJsonDocument docment = QJsonDocument::fromJson(data, &jsonError);
    if(docment.isNull() && jsonError.error != QJsonParseError::NoError){return "";}
    if(!docment.isObject()){return "";}
    QJsonObject object = docment.object();
    if (!object.contains(key)){return "";}
    return object.value(key);
}

QJsonValue Model::getJson(const QJsonValue &data, const QString &key)
{
    QJsonObject object = data.toObject();
    if (!object.contains(key)){return "";}
    return object.value(key);
}

QString Model::JsonToString(const QJsonValue &value)
{
    if (value.isString())
    {
        return value.toString();

    }else if (value.isDouble())
    {
        return QString::number(value.toDouble());
    }

    return value.toString();
}
