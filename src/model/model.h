#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class QByteArray;
class QJsonValue;

typedef struct{
    QString uuid;
    QString name;
    QString icon;
    QString spaceUsed;
    QString spaceCapacity;
}UserInfo;

typedef struct{
    QString status;
    UserInfo result;
    QString code;
    QString success;
    QString message;
    QString token;
}User;



class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0);
    User getUser(const QByteArray &Data);

signals:

public slots:

private:
    QJsonValue getJson(const QJsonValue &data, const QString &key);
    QJsonValue getByteArray(const QByteArray &data, const QString &key);
    QString JsonToString(const QJsonValue &value);

    UserInfo getUserInfo(const QJsonValue &Data);

    UserInfo userInfo;
    User users;
};

#endif // MODEL_H
