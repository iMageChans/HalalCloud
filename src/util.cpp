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
    if(docment.isNull() && jsonError.error != QJsonParseError::NoError){return Error;}
    if(!docment.isObject()){return Error;}
    QJsonObject object = docment.object();
    if (!object.contains(key)){return Error;}
    return object.value(key);
}

QJsonValue Util::getJsonNest(QByteArray data, QString key, QString nestKey){
    QJsonValue datas = this->getJson(data,key);
    QJsonObject object = datas.toObject();
    QJsonValue nestObj =  object.value(key);
    if (nestObj.isObject()){return Error;}
    QJsonObject value = nestObj.toObject();
    if (!value.contains(nestKey)){return Error;}
    return value.value(nestKey);
}

QString Util::JsonToString(QJsonValue value){
    return value.toString();
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

void Util::getFilesList(QString Token, QString Parent, QString path, QString Mime){
    QByteArray datas = FilesListData(Parent, path, Mime);
    JsonData = response->Fire("/v1/files/list", Token, datas, post);
    QJsonValue data = this->getJsonNest(JsonData, "result", "list");
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

void Util::getPageFile(QString Token, QString Parent, QString path){
    QByteArray datas = PageListData(Parent, path);
    JsonData = response->Fire("/v1/files/page", Token, datas, post);
    qDebug() << JsonData;
}

void Util::getFilesInfo(QString Token, QString uuid, QString path){
    QByteArray datas = FliesInfoData(uuid, path);
    JsonData = response->Fire("/v1/files/get", Token, datas, post);
    qDebug() << JsonData;
}

void Util::createFiles(QString Token, QString name, QString path){
    QByteArray datas = CreateDicectory(name, path);
    JsonData = response->Fire("/v1/files/createDirectory", Token, datas, post);
    qDebug() << JsonData;
}

void Util::moveFiles(QString Token, QString uuid, QString path, QString parent){
    QByteArray datas = FilesMove(uuid, path, parent);
    JsonData = response->Fire("/v1/files/move", Token, datas, post);
    qDebug() << JsonData;
}

void Util::renameFiles(QString Token, QString uuid, QString path, QString name){
    QByteArray datas = FilesRename(uuid, path, name);
    JsonData = response->Fire("/v1/files/rename", Token, datas, post);
    qDebug() << JsonData;
}

void Util::recycleFiles(QString Token, QString uuid, QString path){
    QByteArray datas = FilesRecycle(uuid, path);
    JsonData = response->Fire("/v1/files/recycle", Token, datas, post);
    qDebug() << JsonData;
}

void Util::removeFiles(QString Token, QString uuid, QString path){
    QByteArray datas = FilesRemove(uuid, path);
    JsonData = response->Fire("/v1/files/remove", Token, datas, post);
    qDebug() << JsonData;
}

void Util::previewPDF(QString Token, QString uuid, QString path){
    QByteArray datas = PreviewPDF(uuid, path);
    JsonData = response->Fire("/v1/preview/pdf", Token, datas, post);
    qDebug() << JsonData;
}

void Util::previewImage(QString Token, QString uuid, QString path){
    QByteArray datas = PreviewImage(uuid, path);
    JsonData = response->Fire("/v1/preview/image", Token, datas, post);
    qDebug() << JsonData;
}
