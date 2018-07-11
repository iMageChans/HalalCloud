#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <QNetworkRequest>

enum request{
    Default,
    noToken,
    multiparUpload
};

template <typename R>
QNetworkRequest RequesBuild(const R &Token, const R &Url, const R &UploadId, request r){
    switch (r) {
    case Default:return defaultHeader(Token, Url);break;
    case noToken:return LoginHeader(Token, Url);break;
    case multiparUpload:return multiparUploadHeader(Token, Url, UploadId);break;
    }
}

template <typename R>
QNetworkRequest defaultHeader(const R &Token, const R &Url){
    QByteArray bearer;
    QNetworkRequest request;
    request.setUrl(Url);
    bearer.append("Bearer " + Token);
    request.setRawHeader("Authorization", bearer);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    return request;
}

template <typename R>
QNetworkRequest LoginHeader(const R &Token, const R &Url){
    QByteArray bearer;
    QNetworkRequest request;
    request.setUrl(Url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    return request;
}

template <typename R>
QNetworkRequest multiparUploadHeader(const R &Token, const R &Url, const R &UploadId){
    QNetworkRequest request;
    request.setUrl(Url);
    request.setRawHeader("Authorization", Token);
    request.setRawHeader("Content-Type", "application/octet-stream");
    request.setHeader("UploadBatch", UploadId);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    return request;
}


#endif // ABSTRACT_H
