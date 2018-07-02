#include "baseapi.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QEventLoop>
#include <QDebug>

BaseAPI::BaseAPI(QObject *parent) : QObject(parent)
{
}

void BaseAPI::post(QString url, QString token, QByteArray data){
    QUrl Url("http://api.blog120.com" + url);

    QEventLoop temp_loop;
    QNetworkRequest request;
    request.setUrl(Url);
    QByteArray bearer;
    qDebug() << token.length();
    if(token.length() > 0){
        bearer.append("Bearer " + token);
        request.setRawHeader("Authorization", bearer);
    }
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkAccessManager *manage = new QNetworkAccessManager(this);
    QNetworkReply *reply = manage->post( request, data);
    connect(reply, SIGNAL(finished()), &temp_loop, SLOT(quit()));
    temp_loop.exec();
    qDebug() << "start";
    QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    QVariant redirectionTargetUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    qDebug() << reply->errorString();
    if (reply->error() == QNetworkReply::NoError){
        QByteArray bytes = reply->readAll();
        datas = bytes;
    }
    reply->deleteLater();
    qDebug() << "finished";
}
