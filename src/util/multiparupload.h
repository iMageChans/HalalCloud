#ifndef MULTIPARUPLOAD_H
#define MULTIPARUPLOAD_H

#include <QObject>
#include <QString>
#include "model/multiparuploadmodel.h"

class BaseAPI;
class QFileInfo;
class multiparUploadModel;
class Util;


class MultiparUpload : public QObject
{
    Q_OBJECT
public:
    explicit MultiparUpload(QObject *parent = nullptr);
    void setDefaultInfo(const QFileInfo &files, const QString &parent, const QString &filespath);

signals:

public slots:

private:
    QString getFilesHash(const QString &filePath);
    int BlockSize(int Size);
    QString makeBlockUrl(int offset, const QString &url);
    QString url;
    QString token;
    long long Size;
    QString uploadID;
    int progress;
    int block_size;
    int block_num;
    QString name;
    QString path;
    multiparUploadModel *model;
    BaseAPI *response;
    Util *util;
    upload_token TokenInfo;
    int upload_bolck_Size;
    int block_id;
};

#endif // MULTIPARUPLOAD_H
