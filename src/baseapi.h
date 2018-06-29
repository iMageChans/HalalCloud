#ifndef BASEAPI_H
#define BASEAPI_H

#include <QObject>

class BaseAPI : public QObject
{
    Q_OBJECT
public:
    explicit BaseAPI(QObject *parent = nullptr);
    void post(QString url, QString token, QByteArray data);

    QByteArray datas;

signals:

public slots:
};

#endif // BASEAPI_H
