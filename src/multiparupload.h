#ifndef MULTIPARUPLOAD_H
#define MULTIPARUPLOAD_H

#include <QObject>
#include <QString>

class BaseAPI;
class Util;

class MultiparUpload : public QObject
{
    Q_OBJECT
public:
    explicit MultiparUpload(QObject *parent = nullptr);
    void Upload(QString url, QString token, QString path, QString fileName, QString hash);
    void defineConfig(QString path, QString upload_id);
signals:

public slots:

private:
    void getUploadToken(QString url, QString token, QString path, QString fileName, QString hash);
    void uploadProgress(QString size);

    BaseAPI *fire;
    Util *util;

    QString Token;
    QString Key;
    QString Url;
    QString Path;
    QString UploadBatch;
    int Size;
    int Progress;
    int Block_size;
    int Bput_size;
    int Blocknum;
};

#endif // MULTIPARUPLOAD_H
