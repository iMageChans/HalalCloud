#include "multiparuploadmodel.h"
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QDebug>

multiparUploadModel::multiparUploadModel(QObject *parent) : QObject(parent)
{

}

upload_token multiparUploadModel::getTokenInfo(const QByteArray &Data)
{
    tokenInfo.status = this->JsonToString(this->getByteArray(Data, "status"));
    tokenInfo.success = this->JsonToString(this->getByteArray(Data, "success"));
    tokenInfo.code = this->JsonToString(this->getByteArray(Data, "code"));
    tokenInfo.result = this->getToken(this->getByteArray(Data, "result"));
    tokenInfo.token = this->JsonToString(this->getByteArray(Data, "token"));

    return tokenInfo;
}

Token multiparUploadModel::getToken(const QJsonValue &Data)
{

    token.userId = this->JsonToString(this->getJson(Data, "userId"));
    token.token = this->JsonToString(this->getJson(Data, "token"));
    token.type = this->JsonToString(this->getJson(Data, "type"));
    token.uploadUrl = this->JsonToString(this->getJson(Data, "uploadUrl"));
    token.version = this->JsonToString(this->getJson(Data, "version"));
    return token;
}

QJsonValue multiparUploadModel::getByteArray(const QByteArray &data, const QString &key){
    QJsonParseError jsonError;
    QJsonDocument docment = QJsonDocument::fromJson(data, &jsonError);
    if(docment.isNull() && jsonError.error != QJsonParseError::NoError){return "";}
    if(!docment.isObject()){return "";}
    QJsonObject object = docment.object();
    if (!object.contains(key)){return "";}
    return object.value(key);
}

QJsonValue multiparUploadModel::getJson(const QJsonValue &data, const QString &key)
{
    QJsonObject object = data.toObject();
    if (!object.contains(key)){return "";}
    return object.value(key);
}

QString multiparUploadModel::JsonToString(const QJsonValue &value)
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
