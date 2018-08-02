#include "model.h"
#include <QByteArray>
#include <QDebug>
#include "util/util.h"

Model::Model(QObject *parent) : QObject(parent)
{
    util = new Util;
}

UserInfo Model::getUserInfo(const QByteArray &Data)
{
    userInfo.name = util->JsonToString(util->getJsonNest(Data, "result", "name"));
    userInfo.icon = util->JsonToString(util->getJsonNest(Data, "result", "icon"));
    userInfo.uuid = util->JsonToString(util->getJsonNest(Data, "result", "uuid"));
    userInfo.spaceCapacity = util->JsonToString(util->getJsonNest(Data, "result", "spaceCapacity"));
    userInfo.spaceUsed = util->JsonToString(util->getJsonNest(Data, "result", "spaceUsed"));
    return userInfo;
}
