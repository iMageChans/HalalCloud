#ifndef MULTIPARUPLOADMODEL_H
#define MULTIPARUPLOADMODEL_H

#include <QObject>

class QByteArray;
class QJsonValue;

typedef struct{
    QString userId;
    QString token;
    QString type;
    QString uploadUrl;
    QString version;
    QString uuid;
    QString storeId;
    QString pathId;
    QString lft;
    QString rgt;
    QString path;
    QString name;
    QString ext;
    QString size;
    QString parent;
    QString atime;
    QString ctime;
    QString mtime;
}Token;

typedef struct{
    QString status;
    Token result;
    QString code;
    QString success;
    QString token;
}upload_token;





class multiparUploadModel : public QObject
{
    Q_OBJECT
public:
    explicit multiparUploadModel(QObject *parent = nullptr);
    upload_token getTokenInfo(const QByteArray &Data);

signals:

public slots:

private:
    Token getToken(const QJsonValue &Data);
    QJsonValue getJson(const QJsonValue &data, const QString &key);
    QJsonValue getByteArray(const QByteArray &data, const QString &key);
    QString JsonToString(const QJsonValue &value);

    upload_token tokenInfo;
    Token token;
};

#endif // MULTIPARUPLOADMODEL_H
