#ifndef NETWORKDATA_H
#define NETWORKDATA_H

#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>

template <typename JsonData>
QByteArray getJsonData(const JsonData &Json){
    QByteArray datas;
    QJsonDocument docum;
    docum.setObject(Json);
    datas = docum.toJson(QJsonDocument::Compact);
    return datas;
}

template <typename data>
QByteArray LoginData(const data &value, const data &password){
    QJsonObject Json;
    Json.insert("value", value);
    Json.insert("password", password);
    return getJsonData(Json);
}

template <typename data>
QByteArray LoginOutData(const data &time){
    QJsonObject Json;
    Json.insert("time", int(time));
    return getJsonData(Json);
}

template <typename List>
QByteArray FilesListData(const List &Parent, const List &Path, const List &Mime){
    QJsonObject Json;
    Json.insert("parent", Parent);
    Json.insert("path", Path);
    Json.insert("mime", Mime);
    Json.insert("recycle", -1);
    Json.insert("orderBy", 1);
    Json.insert("type", -1);
    return getJsonData(Json);
}

template <typename Page>
QByteArray PageListData(const Page &Parent, const Page &Path){
    QJsonObject Json;
    Json.insert("parent", Parent);
    Json.insert("path",Path);
    Json.insert("orderBy", 1);
    Json.insert("type", -1);
    return getJsonData(Json);
}

template <typename FileInfo>
QByteArray FliesInfoData(const FileInfo &uuid, const FileInfo &Path){
    QJsonObject Json;
    Json.insert("uuid",uuid);
    Json.insert("path",Path);
    return getJsonData(Json);
}

template <typename Dict>
QByteArray CreateDicectory(const Dict &Name, const Dict &Path){
    QJsonObject Json;
    Json.insert("name",Name);
    Json.insert("path",Path);
    return getJsonData(Json);
}

template <typename Move>
QByteArray FilesMove(const Move &uuid, const Move &Path, const Move &Parent){
    QJsonObject Json;
    Json.insert("uuid",uuid);
    Json.insert("path",Path);
    Json.insert("parent", Parent);
    Json.insert("overwrite", "flase");
    return getJsonData(Json);
}

template <typename Rename>
QByteArray FilesRename(const Rename &uuid, const Rename &Path, const Rename &Name){
    QJsonObject Json;
    Json.insert("uuid",uuid);
    Json.insert("path",Path);
    Json.insert("name", Name);
    Json.insert("overwrite", "flase");
    return getJsonData(Json);
}

template <typename Recycle>
QByteArray FilesRecycle(const Recycle &uuid, const Recycle &Path){
    QJsonObject Json;
    Json.insert("uuid",uuid);
    Json.insert("path",Path);
    return getJsonData(Json);
}

template <typename Remove>
QByteArray FilesRemove(const Remove &uuid, const Remove &Path){
    QJsonObject Json;
    Json.insert("uuid",uuid);
    Json.insert("path",Path);
    return getJsonData(Json);
}

template <typename PDF>
QByteArray PreviewPDF(const PDF &uuid, const PDF &Path){
    QJsonObject Json;
    Json.insert("uuid",uuid);
    Json.insert("path",Path);
    return getJsonData(Json);
}

template <typename Image>
QByteArray PreviewImage(const Image &uuid, const Image &Path){
    QJsonObject Json;
    Json.insert("uuid",uuid);
    Json.insert("path",Path);
    return getJsonData(Json);
}



#endif // NETWORKDATA_H
