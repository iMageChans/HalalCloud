#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class QByteArray;
class QJsonValue;

typedef struct{
    QString uuid;
    QString name;
    QString icon;
    QString phone;
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

typedef struct{
    QString status;
    QString result;
}Register;



class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0);
    User getUser(const QByteArray &Data);
    Register getRegister(const QByteArray &Data);
    QString JsonToString(const QJsonValue &value);
    QJsonValue getJson(const QJsonValue &data, const QString &key);
    QJsonValue getByteArray(const QByteArray &data, const QString &key);
signals:

public slots:

private:
    UserInfo getUserInfo(const QJsonValue &Data);

    UserInfo userInfo;
    User users;
    Register reg;
};

#endif // MODEL_H
