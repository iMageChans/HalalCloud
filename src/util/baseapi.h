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

    QByteArray Fire(const QString &url,const QString &token, const QByteArray &data, method m);

    QByteArray datas;

signals:

public slots:

private:
    QByteArray wrapper_response(QNetworkReply *reply);
    QByteArray Post(const QString &url, const QString &token, const QByteArray &data);
    QByteArray noTokenPost(const QString &url, const QByteArray &data);
    QByteArray Get(const QString &url, const QString &token);
};

#endif // BASEAPI_H
