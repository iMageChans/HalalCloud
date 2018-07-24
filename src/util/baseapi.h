#ifndef BASEAPI_H
#define BASEAPI_H

#include <QObject>

enum method{
    get ,
    post,
    post_no_token
};

class QNetworkReply;

class BaseAPI : public QObject
{
    Q_OBJECT
public:
    explicit BaseAPI(QObject *parent = nullptr);

    QByteArray Fire(QString url, QString token, QByteArray data, method m);

    QByteArray datas;

signals:

public slots:

private:
    QByteArray wrapper_response(QNetworkReply *reply);
    QByteArray Post(QString url, QString token, QByteArray data);
    QByteArray noTokenPost(QString url, QByteArray data);
    QByteArray Get(QString url, QString token);
};

#endif // BASEAPI_H
