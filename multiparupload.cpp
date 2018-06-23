#include "multiparupload.h"
#include "baseapi.h"

MultiparUpload::MultiparUpload(QObject *parent) : QObject(parent)
{
    Block_size = 1024 * 1024 * 4;
    Bput_size = 512 * 1024;
}

void MultiparUpload::Upload(QString url, QString, token, QString uuid, QString path){
}

void MultiparUpload::getUploadToken(QString url, QString token, QString key){
}
