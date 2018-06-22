#ifndef MULTIPARUPLOAD_H
#define MULTIPARUPLOAD_H

#include <QObject>

class MultiparUpload : public QObject
{
    Q_OBJECT
public:
    explicit MultiparUpload(QObject *parent = nullptr);
    void Upload(QString url, QString, token, QString uuid);
signals:

public slots:

private:
    QString Token;
    QString key;
    QString Url;
    QString path;
    QString iploadBatch;
    int Size;
    int Progress;
    int block_size;
    int bput_size;
    int blocknum;
};

#endif // MULTIPARUPLOAD_H
