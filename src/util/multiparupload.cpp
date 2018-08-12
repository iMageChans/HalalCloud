#include "util/multiparupload.h"
#include "baseapi.h"
#include "util.h"
#include <QFileInfo>
#include <QByteArray>
#include <QDebug>
#include <QUuid>
#include <QFile>
#include <QCryptographicHash>
#include "util/util.h"
#include "networkdata.h"

MultiparUpload::MultiparUpload(QObject *parent) : QObject(parent)
{
    model = new multiparUploadModel;
    response = new BaseAPI;
    util = new Util;
}

void MultiparUpload::setDefaultInfo(const QFileInfo &files, const QString &parent, const QString &filespath)
{
     if (files.isFile())
     {
         Size = files.size();
         name = files.fileName();
         path = files.filePath();
         block_num = 0;
         block_size = 4 * 1024 * 1024;
         progress = 0;
         QUuid id = QUuid::createUuid();
         uploadID = id.toString();
         QString hash = this->getFilesHash(path);
         QByteArray datas = getUploadToken(name, parent, filespath, hash);
         QByteArray rsp = response->Fire("/v1/store/token",util->getToken(), datas, post);
         TokenInfo = model->getTokenInfo(rsp);
         token = TokenInfo.result.token;
         url = TokenInfo.result.uploadUrl;
     }
}

QString MultiparUpload::getFilesHash(const QString &filePath)
{
    QFile localFile(filePath);
    if(!localFile.open(QFile::ReadOnly)){
        qDebug() << "file open error";
    }
    localFile.open(QFile::ReadOnly);
    QByteArray ba = QCryptographicHash::hash(localFile.readAll(),QCryptographicHash::Sha1);
    localFile.close();
    qDebug() << ba.toHex().constData();
    return ba.toHex().constData();
}
