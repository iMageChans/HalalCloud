#ifndef UTIL_H
#define UTIL_H

#include <QObject>
class QJsonValue;
class BaseAPI;

class Util : public QObject
{
    Q_OBJECT
public:
    explicit Util(QObject *parent = nullptr);
    void Login(QString username, QString password);
    void LoginOut();
    void getFilesList(QString Token, QString Parent, QString path, int orderBy, int type);
    QString getFilesHash(QString filePath);
    QString getToken();
    QString JsonToString(QJsonValue value);
    QJsonValue getJson(QByteArray data, QString key);
    QJsonValue getJsonLast(QByteArray data, QString key, QString lastKey);

    QByteArray JsonData;
    QString Token;
signals:

public slots:

private:
    BaseAPI *response;
};

#endif // UTIL_H
