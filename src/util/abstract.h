#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <QNetworkRequest>
#include <QDebug>

enum request{
    Default,
    noToken
};

template <typename R>
QNetworkRequest RequesBuild(const R &Token, const R &Url, const R &UploadId, request r){
    switch (r) {
    case Default:return defaultHeader(Token, Url);break;
    case noToken:return LoginHeader(Url);break;
    }
}

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

//template <typename R>
//QNetworkRequest multiparUploadHeader(const R &Token, const R &Url, const R &UploadId){
//    QNetworkRequest request;
//    request.setUrl(Url);
//    request.setRawHeader("Authorization", Token);
//    request.setRawHeader("Content-Type", "application/octet-stream");
//    request.setHeader("UploadBatch", UploadId);
//    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
//    return request;
//}


#endif // ABSTRACT_H
