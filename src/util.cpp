#include "util.h"
#include "baseapi.h"
#include "networkdata.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QSettings>
#include <QJsonParseError>
#include <QFile>
#include <QCryptographicHash>
#include <QDateTime>

Util::Util(QObject *parent) : QObject(parent)
{
    response = new BaseAPI;
}

QJsonValue Util::getJson(QByteArray data, QString key){
    QJsonParseError jsonError;
    QJsonDocument docment = QJsonDocument::fromJson(data, &jsonError);
    if (!docment.isNull() && jsonError.error == QJsonParseError::NoError){
        if(docment.isObject()){
            QJsonObject object = docment.object();
            if (object.contains(key)){
                return object.value(key);
            }
        }
    }
}

QJsonValue Util::getJsonLast(QByteArray data, QString key, QString lastKey){
    QJsonParseError jsonError;
    QJsonDocument docment = QJsonDocument::fromJson(data, &jsonError);
    if (!docment.isNull() && jsonError.error == QJsonParseError::NoError){
        if(docment.isObject()){
            QJsonObject object = docment.object();
            if (object.contains(key)){
                QJsonValue lastObj =  object.value(key);
                if (lastObj.isObject()){
                    QJsonObject value = lastObj.toObject();
                    if (value.contains(lastKey)){
                        return value.value(lastKey);
                    }
                }
            }
        }
    }
}

QString Util::JsonToString(QJsonValue value){
    if (value.isString()){
        return value.toString();
    }
}

void Util::Login(QString username, QString password){
    QByteArray datas = LoginData(username,password);
    JsonData = response->Fire("/v1/user/login","",datas, post_no_token);
    QSettings setting("C:/Users/Chans/Desktop/i.ini",QSettings::IniFormat);
    setting.beginGroup(tr("AotuLogin"));
    QJsonValue data = this->getJson(JsonData, "token");
    QString key("token");
    QString value = this->JsonToString(data);
    setting.setValue(key,value);
    setting.endGroup();
}

QString Util::getToken(){
    QSettings setting("C:/Users/Chans/Desktop/i.ini",QSettings::IniFormat);
    if (setting.contains(tr("AotuLogin/Token"))){
        Token = setting.value("AotuLogin/Token").toString();
    }
    return Token;
}

void Util::LoginOut(){
    QDateTime time = QDateTime::currentDateTime();
    qDebug() << QString::number(time.toTime_t());
    QByteArray datas = LoginOutData(time.toTime_t());
    QByteArray rsp = response->Fire("/v1/user/logout", this->getToken(), datas, post);
    if (this->getJson(rsp, "status") == 200){
        QSettings setting("C:/Users/Chans/Desktop/i.ini",QSettings::IniFormat);
        if (setting.contains(tr("AotuLogin/token"))){
            setting.beginGroup(tr("AotuLogin"));
            setting.remove( "token");
            setting.endGroup();
        }
    }
}

void Util::getFilesList(QString Token, QString Parent, QString path, int orderBy, int type){
    QByteArray datas = FilesListData(Parent, path, QString::number(orderBy), QString::number(type));
    JsonData = response->Fire("/v1/files/page", Token, datas, post);
    QJsonValue data = this->getJsonLast(JsonData, "result", "list");
    qDebug() << this->JsonToString(data);
}

QString Util::getFilesHash(QString filePath){
    QFile localFile(filePath);
    if(!localFile.open(QFile::ReadOnly)){
        qDebug() << "file open error";
        return 0;
    }
    localFile.open(QFile::ReadOnly);
    QByteArray ba = QCryptographicHash::hash(localFile.readAll(),QCryptographicHash::Sha1);
    localFile.close();
    qDebug() << ba.toHex().constData();
    return ba.toHex().constData();
}
