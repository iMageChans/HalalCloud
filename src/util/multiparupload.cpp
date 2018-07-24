#include "multiparupload.h"
#include "baseapi.h"
#include "util.h"
#include <QFileInfo>
#include <QDebug>
#include <QUuid>

MultiparUpload::MultiparUpload(QObject *parent) : QObject(parent)
{
    Block_size = 1024 * 1024 * 4;
    Bput_size = 512 * 1024;
    fire = new BaseAPI;
    util = new Util;
}

void MultiparUpload::defineConfig(QString path, QString upload_id){
    Path = path;
    QFileInfo fileInfo(path);
    Size = fileInfo.size();
    Key = fileInfo.fileName();

    if(Size % Block_size != 0){
        Blocknum = Size / Block_size + 1;
    }else{
        Blocknum = Size / Block_size;
    }
    UploadBatch = upload_id;
    Progress = 0;
    qDebug() << Size;
    qDebug() << Key;
    qDebug() << Blocknum;
}

//int MultiparUpload::uploadProgress(int size){
//    return Progress += size;
//}

//void MultiparUpload::makeBlock(int offset){
//    QString url = this->mlkUrl(offset);

    
//}

//void MultiparUpload::makeBput(int offset){

//}

//QString MultiparUpload::getBlockUrl(int size, int blocknum){
//    return QString("%1/mkblk/%2/%3").arg(Url,QString::number(size),QString::number(blocknum));
//}

//QString MultiparUpload::getBputkUrl(QString ctx, int offset){
//    return QString("%1/bput/%2/%3").arg(Url, ctx, QString::number(offset));
//}

//QString MultiparUpload::getFileUrl(){
//    return QString("%1/mkfile/%2").arg(Url, Size);
//}

//void MultiparUpload::Upload(QString url, QString token, QString path, QString fileName, QString hash){
//    this->getUploadToken(url, token, path, fileName, hash);

//}

//QString MultiparUpload::mlkUrl(int offset){
//    int blockid = offset / Block_size;
//    int size = 0;
//    if(blockid < Blocknum - 1){
//        size = Block_size;
//    }else{
//        size = Size - (blockid * Block_size);
//    }
//    return this->getBlockUrl(size, blockid);
//}



//void MultiparUpload::getUploadToken(QString url, QString token, QString path, QString fileName, QString hash){
//    QByteArray datas;
//    datas.append("name=" + fileName);
//    datas.append("&hash=" + hash);
//    datas.append("&path=" + path);
//    fire->post(url, token, datas);
//    QByteArray JsonData = fire->datas;
//    Token = util->JsonToString(util->getJsonLast(JsonData,"result","uploadUrl"));
//    Url =util->JsonToString(util->getJsonLast(JsonData,"result","token"));
//    QUuid id = QUuid::createUuid();
//    UploadBatch = id.toString();
//}
