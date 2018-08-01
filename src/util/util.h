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
    QByteArray Login(const QString &username, const QString &password);
    void LoginOut();
    void getFilesList(const QString &Parent, const QString &path, const QString &Mime);
    void getPageFile(const QString &Parent, const QString &path);
    void getFilesInfo(const QString &uuid, const QString &path);
    void createFiles(const QString &name, const QString &path);
    void moveFiles(const QString &uuid, const QString &path, const QString &parent);
    void renameFiles(const QString &uuid, const QString &path, const QString &name);
    void recycleFiles(const QString &uuid, const QString &path);
    void removeFiles(const QString &uuid, const QString &path);
    void previewPDF(const QString &uuid, const QString &path);
    void previewImage(const QString &uuid, const QString &path);
    QString getFilesHash(const QString &filePath);
    QString getToken();
    QString JsonToString(const QJsonValue &value);
    QJsonValue getJson(const QByteArray &data, const QString &key);
    QJsonValue getJsonNest(const QByteArray &data, const QString &key, const QString &nestKey);

    QByteArray JsonData;
    QString Token;
signals:

public slots:

private:
    void saveToken(const QByteArray &Token);
    QString SystemPath();

    BaseAPI *response;
    QJsonValue Error;
};

#endif // UTIL_H
