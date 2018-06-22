#include "util.h"
#include "baseapi.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QSettings>
#include <QJsonParseError>

Util::Util(QObject *parent) : QObject(parent)
{

}

void Util::Login(QString username, QString password){
    QByteArray datas;
    datas.append("value=" + username);
    datas.append("&password=" + password);
    BaseAPI *fire = new BaseAPI;
    fire->post("/v1/user/login","",datas);
   JsonData = fire->datas;
   QSettings setting("C:/Users/Chans/Desktop/i.ini",QSettings::IniFormat);
   if (setting.contains(tr("AotuLogin/token"))){
       Token = setting.value("AotuLogin/token").toString();
   }else{
       setting.beginGroup(tr("AotuLogin"));
       QJsonValue data = this->getJson(JsonData, "token");
       QString key("token");
       QString value = this->JsonToString(data);
       setting.setValue(key,value);
       setting.endGroup();
   }
}

QString Util::getToken(){
    QSettings setting("C:/Users/Chans/Desktop/i.ini",QSettings::IniFormat);
    if (setting.contains(tr("AotuLogin/Token"))){
        Token = setting.value("AotuLogin/Token").toString();
    }
    return Token;
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
