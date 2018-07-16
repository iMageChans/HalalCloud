#ifndef UTIL_H
#define UTIL_H

#include <QObject>
#include <QJsonValue>
class BaseAPI;

class Util : public QObject
{
    Q_OBJECT
public:
    explicit Util(QObject *parent = nullptr);
    void Login(QString username, QString password);
    void LoginOut();
    void getFilesList(QString Token, QString Parent, QString path);
    void getPageFile(QString Token, QString Parent);
    QString getFilesHash(QString filePath);
    QString getToken();
    QString JsonToString(QJsonValue value);
    QJsonValue getJson(QByteArray data, QString key);
    QJsonValue getJsonNest(QByteArray data, QString key, QString lastKey);

    QByteArray JsonData;
    QString Token;
signals:

public slots:

private:
    BaseAPI *response;
    QJsonValue Error;
};

#endif // UTIL_H
