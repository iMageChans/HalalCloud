#ifndef MULTIPARUPLOAD_H
#define MULTIPARUPLOAD_H

#include <QObject>

class MultiparUpload : public QObject
{
    Q_OBJECT
public:
    explicit MultiparUpload(QObject *parent = nullptr);
//    void Upload(QString url, QString, token, QString uuid, QString path);
signals:

public slots:

private:
    void getUploadToken(QString url, QString token, QString key);
    void defaultConfig(QString path, QString token, QString uploadbatch);

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
