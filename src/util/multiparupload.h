#ifndef MULTIPARUPLOAD_H
#define MULTIPARUPLOAD_H

#include <QObject>
#include <QString>

class BaseAPI;
class QFileInfo;

class MultiparUpload : public QObject
{
    Q_OBJECT
public:
    explicit MultiparUpload(QObject *parent = nullptr);
    void setDefaultInfo(const QFileInfo &files);
signals:

public slots:

private:
    QString url;
    QString token;
    long long Size;
    QString uploadID;
    int progress;
    int block_size;
    int block_num;
    QString name;
    QString path;

};

#endif // MULTIPARUPLOAD_H
