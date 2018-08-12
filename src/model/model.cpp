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
    users.status = this->getJsonDouble(this->getByteArray(Data, "status"));
    users.success = this->getJsonBool(this->getByteArray(Data, "success"));

    if (users.status == 200)
    {
        users.result = this->getUserInfo(this->getByteArray(Data, "result"));
        users.token = this->getJsonString(this->getByteArray(Data, "token"));
    }else{
        users.message = this->getJsonString(this->getByteArray(Data, "message"));
        users.code = this->getJsonString(this->getByteArray(Data, "code"));
    }

    return users;
}

UserInfo Model::getUserInfo(const QJsonValue &Data)
{

    userInfo.name = this->getJsonString(this->getJson(Data, "name"));
    userInfo.icon = this->getJsonString(this->getJson(Data, "icon"));
    userInfo.uuid = this->getJsonDouble(this->getJson(Data, "uuid"));
    userInfo.phone = this->getJsonString(this->getJson(Data, "phone"));
    userInfo.spaceCapacity = this->getJsonDouble(this->getJson(Data, "spaceCapacity"));
    userInfo.spaceUsed = this->getJsonDouble(this->getJson(Data, "spaceUsed"));
    return userInfo;
}

Register Model::getRegister(const QByteArray &Data)
{
    reg.status = this->getJsonDouble(this->getByteArray(Data, "status"));
    reg.result = this->getJsonString(this->getByteArray(Data, "result"));
    reg.success = this->getJsonBool(this->getByteArray(Data, "success"));
    return reg;
}

FilesList Model::getList(const QByteArray &Data)
{
    filesList.status = this->getJsonDouble(this->getByteArray(Data, "status"));
    filesList.code = this->getJsonString(this->getByteArray(Data, "code"));
    filesList.success = this->getJsonBool(this->getByteArray(Data, "success"));
    filesList.token = this->getJsonString(this->getByteArray(Data, "token"));
    filesList.result = this->getListData(this->getByteArray(Data, "result"));
    return filesList;
}

ListData Model::getListData(const QJsonValue &Data)
{
    listData.page = this->getJsonDouble(this->getJson(Data, "page"));
    listData.pageSize = this->getJsonDouble(this->getJson(Data, "pageSize"));
    listData.totalCount = this->getJsonDouble(this->getJson(Data, "totalCount"));
    listData.totalPage = this->getJsonDouble(this->getJson(Data, "totalPage"));
    listData.list = this->getJsonArray(Data, "list");
    listData.info = this->getListInfo(this->getJson(Data, "info"));
    return listData;
}

ListInfo Model::getListInfo(const QJsonValue &Data)
{
    info.uuid = this->getJsonString(this->getJson(Data, "uuid"));
    info.storeId = this->getJsonString(this->getJson(Data, "storeId"));
    info.userId = this->getJsonDouble(this->getJson(Data, "userId"));
    info.path = this->getJsonString(this->getJson(Data, "path"));
    info.name = this->getJsonString(this->getJson(Data, "name"));
    info.ext = this->getJsonString(this->getJson(Data, "ext"));
    info.size = this->getJsonDouble(this->getJson(Data, "size"));
    info.parent = this->getJsonString(this->getJson(Data, "parent"));
    info.type = this->getJsonDouble(this->getJson(Data, "type"));
    info.atime = this->getJsonLoog(this->getJson(Data, "atime"));
    info.ctime = this->getJsonLoog(this->getJson(Data, "ctime"));
    info.mtime = this->getJsonLoog(this->getJson(Data, "mtime"));
    info.version = this->getJsonDouble(this->getJson(Data, "version"));
    info.locking = this->getJsonBool(this->getJson(Data, "locking"));
    return info;
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

QJsonArray Model::getJsonArray(const QJsonValue &data, const QString &key)
{
    QJsonObject object = data.toObject();
    QJsonArray array = object.value(key).toArray();
    return array;
}

bool Model::getJsonBool(const QJsonValue &value)
{
    return value.toBool();
}

int Model::getJsonDouble(const QJsonValue &value)
{
    return int(value.toDouble());
}

QString Model::getJsonString(const QJsonValue &value)
{
    return value.toString();
}

long Model::getJsonLoog(const QJsonValue &value)
{
    return long(value.toDouble());
}
