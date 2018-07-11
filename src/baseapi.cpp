#include "baseapi.h"
#include "abstract.h"
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

QByteArray BaseAPI::Fire(QString url, QString token, QByteArray data, method m){

    switch (m) {
    case get:return this->Get(url,token);break;
    case post:return this->Post(url,token,data);break;
    case post_no_token:return this->noTokenPost(url,data);break;
    }
}

QByteArray BaseAPI::Get(QString url, QString token){
    QNetworkRequest request = DefaultHeader(token, url);
    QNetworkAccessManager *manage = new QNetworkAccessManager(this);
    QNetworkReply *reply = manage->get(request);
    return this->wrapper_response(reply);

}

QByteArray BaseAPI::noTokenPost(QString url, QByteArray data){
    QNetworkRequest request = LoginHeader(url);
    QNetworkAccessManager *manage = new QNetworkAccessManager(this);
    QNetworkReply *reply = manage->post(request, data);
    return this->wrapper_response(reply);
}

QByteArray BaseAPI::Post(QString url, QString token, QByteArray data){
    QNetworkRequest request = DefaultHeader(token, url);
    QNetworkAccessManager *manage = new QNetworkAccessManager(this);
    QNetworkReply *reply = manage->post(request, data);
    return this->wrapper_response(reply);
}

QByteArray BaseAPI::wrapper_response(QNetworkReply *reply){

    QEventLoop temp_loop;
    connect(reply, SIGNAL(finished()), &temp_loop, SLOT(quit()));
    temp_loop.exec();
    qDebug() << "start";
    QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    QVariant redirectionTargetUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    QByteArray bytes = reply->readAll();
    if (reply->error() != QNetworkReply::NoError){
        qDebug() << reply->error();
    }
    qDebug() << bytes;
    reply->deleteLater();
    qDebug() << "finished";
    return bytes;
}
