#ifndef UTIL_H
#define UTIL_H

#include <QObject>
#include <QJsonValue>
#include "model/model.h"
#include "model/struct.h"

class BaseAPI;
class Model;
class QPixmap;

class Util : public QObject
{
    Q_OBJECT
public:
    explicit Util(QObject *parent = nullptr);
    User Login(const QString &username, const QString &password);
    Register Cap(const QString &phone);
    User Registers(const QString &name, const QString &phoneInfo, const QString &password, const QString &code);
    User getUserInfo();
    void LoginOut();
    void getFilesList(const QString &Parent, const QString &path, const QString &Mime);
    FilesList getPageFile(const QString &Parent, const QString &path);
    void getFilesInfo(const QString &uuid, const QString &path);
    QByteArray createFiles(const QString &name, const QString &path);
    void moveFiles(const QString &uuid, const QString &path, const QString &parent);
    void renameFiles(const QString &uuid, const QString &path, const QString &name);
    void recycleFiles(const QString &uuid, const QString &path);
    void removeFiles(const QString &uuid, const QString &path);
    void previewPDF(const QString &uuid, const QString &path);
    void previewImage(const QString &uuid, const QString &path);
    QString getToken();

    void systemConfig(const QString &key, const QString &data, const QString &Group);
    void deleteSystemConfig(const QString &key, const QString &Group);
    QString getSystemConfig(const QString &key, const QString &Group);

    QPixmap PixmapToRound(QPixmap &src, int radius);

    QByteArray JsonData;
    QString Token;
signals:

public slots:

private:
//    void saveToken(const QByteArray &Token);
    QString SystemPath();

    BaseAPI *response;
    QJsonValue Error;
    Model *model;
};

#endif // UTIL_H
