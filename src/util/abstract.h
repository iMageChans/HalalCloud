#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <QNetworkRequest>
#include <QDebug>


template <typename R>
QNetworkRequest DefaultHeader(const R &Token, const R &Url){
    QUrl url("https://api.6pan.cn" + Url);
    QByteArray bearer;
    QNetworkRequest request;
    request.setUrl(url);
    bearer.append("Bearer " + Token);
    request.setRawHeader("Authorization", bearer);
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    return request;
}

template <typename R>
QNetworkRequest LoginHeader(const R &Url){
    QUrl url("https://api.6pan.cn" + Url);
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    return request;
}

template <typename R>
QNetworkRequest multiparUploadHeader(const R &token, const R &Url, const R &uploadId){
    QNetworkRequest request;
    QByteArray Token;
    Token.append(token);
    QByteArray UploadId;
    UploadId.append(uploadId);
    request.setUrl(Url);
    request.setRawHeader("Authorization", Token);
    request.setRawHeader("Content-Type", "application/octet-stream");
    request.setRawHeader("UploadBatch", UploadId);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    return request;
}


#endif // ABSTRACT_H
