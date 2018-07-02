#include "multiparupload.h"
#include "baseapi.h"
#include <QFileInfo>
#include <QDebug>

MultiparUpload::MultiparUpload(QObject *parent) : QObject(parent)
{
    Block_size = 1024 * 1024 * 4;
    Bput_size = 512 * 1024;
    fire = new BaseAPI;
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

void MultiparUpload::Upload(QString url, QString token, QString uuid, QString path, QString fileName, QString hash){
    this->getUploadToken(url, token, path, fileName, hash);
}

void MultiparUpload::getUploadToken(QString url, QString token, QString path, QString fileName, QString hash){
    QByteArray datas;
    datas.append("name=" + fileName);
    datas.append("&hash=" + hash);
    datas.append("&path=" + path);
    fire->post(url, token, datas);
    QByteArray JsonData = fire->datas;
}
