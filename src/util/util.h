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
    void getFilesList(QString Parent, QString path, QString Mime);
    void getPageFile(QString Parent, QString path);
    void getFilesInfo(QString uuid, QString path);
    void createFiles(QString name, QString path);
    void moveFiles(QString uuid, QString path, QString parent);
    void renameFiles(QString uuid, QString path, QString name);
    void recycleFiles(QString uuid, QString path);
    void removeFiles(QString uuid, QString path);
    void previewPDF(QString uuid, QString path);
    void previewImage(QString uuid, QString path);
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
    void saveToken(QByteArray Token);
    QString SystemPath();

    BaseAPI *response;
    QJsonValue Error;
};

#endif // UTIL_H
