#include "util.h"
#include "baseapi.h"
#include "networkdata.h"
#include "model/model.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QSettings>
#include <QJsonParseError>
#include <QFile>
#include <QCryptographicHash>
#include <QDateTime>
#include <QSettings>
#include <QDir>

Util::Util(QObject *parent) : QObject(parent)
{
    response = new BaseAPI;
    model = new Model;
}

User Util::Login(const QString &username, const QString &password){
    QByteArray datas = LoginData(username,password);
    JsonData = response->Fire("/v1/user/login","",datas, post_no_token);
    users = model->getUser(JsonData);
    this->systemConfig("token", users.token, "AotuLogin");
    return users;
}

User Util::Registers(const QString &name, const QString &password, const QString &code, const QString &phone)
{
    QByteArray Cap = Captcha(phone);
    JsonData = response->Fire("/v1/user/sendRegisterMessage","",Cap,post_no_token);
    Register regis = model->getRegister(JsonData);
    if(regis.status == "200"){
        QByteArray reg = registerUser(name, password, code, regis.result);
        JsonData = response->Fire("/v1/user/register","",reg,post_no_token);
        users = model->getUser(JsonData);
        return users;
    }
}

QString Util::getToken(){
    QSettings settings(this->SystemPath(), QSettings::NativeFormat);
    Token = settings.value("AotuLogin/token").toString();
    if (settings.contains(tr("AotuLogin/token"))){
        Token = settings.value("AotuLogin/token").toString();
    }
    return Token;
}

void Util::LoginOut(){
    QDateTime time = QDateTime::currentDateTime();
    QByteArray datas = LoginOutData(time.toTime_t());
    QByteArray rsp = response->Fire("/v1/user/logout", this->getToken(), datas, post);
//    if (this->getJson(rsp, "status") == 200){
//        this->deleteSystemConfig("token", "AotuLogin");
//    }
}

QString Util::getFilesHash(const QString &filePath){
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

void Util::getFilesList(const QString &Parent, const QString &path, const QString &Mime){
    QByteArray datas = FilesListData(Parent, path, Mime);
    JsonData = response->Fire("/v1/files/list", this->getToken(), datas, post);
//    QJsonValue data = model->getJsonNest(JsonData, "result", "list");
//    qDebug() << model->JsonToString(data);
}

void Util::getPageFile(const QString &Parent, const QString &path){
    QByteArray datas = PageListData(Parent, path);
    JsonData = response->Fire("/v1/files/page", this->getToken(), datas, post);
    qDebug() << JsonData;
}

void Util::getFilesInfo(const QString &uuid, const QString &path){
    QByteArray datas = FliesInfoData(uuid, path);
    JsonData = response->Fire("/v1/files/get", this->getToken(), datas, post);
    qDebug() << JsonData;
}

void Util::createFiles(const QString &name, const QString &path){
    QByteArray datas = CreateDicectory(name, path);
    JsonData = response->Fire("/v1/files/createDirectory", this->getToken(), datas, post);
    qDebug() << JsonData;
}

void Util::moveFiles(const QString &uuid, const QString &path, const QString &parent){
    QByteArray datas = FilesMove(uuid, path, parent);
    JsonData = response->Fire("/v1/files/move", this->getToken(), datas, post);
    qDebug() << JsonData;
}

void Util::renameFiles(const QString &uuid, const QString &path, const QString &name){
    QByteArray datas = FilesRename(uuid, path, name);
    JsonData = response->Fire("/v1/files/rename", this->getToken(), datas, post);
    qDebug() << JsonData;
}

void Util::recycleFiles(const QString &uuid, const QString &path){
    QByteArray datas = FilesRecycle(uuid, path);
    JsonData = response->Fire("/v1/files/recycle", this->getToken(), datas, post);
    qDebug() << JsonData;
}

void Util::removeFiles(const QString &uuid, const QString &path){
    QByteArray datas = FilesRemove(uuid, path);
    JsonData = response->Fire("/v1/files/remove", this->getToken(), datas, post);
    qDebug() << JsonData;
}

void Util::previewPDF(const QString &uuid, const QString &path){
    QByteArray datas = PreviewPDF(uuid, path);
    JsonData = response->Fire("/v1/preview/pdf", this->getToken(), datas, post);
    qDebug() << JsonData;
}

void Util::previewImage(const QString &uuid, const QString &path){
    QByteArray datas = PreviewImage(uuid, path);
    JsonData = response->Fire("/v1/preview/image", this->getToken(), datas, post);
    qDebug() << JsonData;
}

QString Util::SystemPath(){
#ifdef Q_OS_MAC
    {
        return QDir::homePath() + "/Library/Preferences/com.HalalCloud.plist";
    }
#else
    {
        return ""HKEY_CURRENT_USER\\Software\\Microsoft\\HalalCloud"
    }
#endif
}

void Util::systemConfig(const QString &key, const QString &data, const QString &Group)
{
    QSettings settings(this->SystemPath(), QSettings::NativeFormat);
    settings.beginGroup(Group);
    settings.setValue(key,data);
    settings.endGroup();
}

void Util::deleteSystemConfig(const QString &key, const QString &Group)
{
    QSettings setting(this->SystemPath(),QSettings::IniFormat);
    if (setting.contains(Group + "/" + key)){
        setting.beginGroup(Group);
        setting.remove(key);
        setting.endGroup();
    }
}
