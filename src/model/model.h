#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QJsonArray>
#include "model/struct.h"

class QByteArray;
class QJsonValue;

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0);
    User getUser(const QByteArray &Data);
    Register getRegister(const QByteArray &Data);
    FilesList getList(const QByteArray &Data);
    ListData getListData(const QJsonValue &Data);
    ListInfo getListInfo(const QJsonValue &Data);
    filesListData getFilesListData(const QJsonValue &Data);
    QString getJsonString(const QJsonValue &value);
    QJsonValue getJson(const QJsonValue &data, const QString &key);
    QJsonArray getJsonArray(const QJsonValue &data, const QString &key);
    bool getJsonBool(const QJsonValue &value);
    int getJsonDouble(const QJsonValue &value);
    long getJsonLoog(const QJsonValue &value);
    QJsonValue getByteArray(const QByteArray &data, const QString &key);
signals:

public slots:

private:
    UserInfo getUserInfo(const QJsonValue &Data);

    UserInfo userInfo;
    User users;
    Register reg;
    FilesList filesList;
    ListData listData;
    ListInfo info;
    filesListData filesData;
};

#endif // MODEL_H
