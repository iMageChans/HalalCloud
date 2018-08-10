#include "util/multiparupload.h"
#include "baseapi.h"
#include "util.h"
#include <QFileInfo>
#include <QDebug>
#include <QUuid>

MultiparUpload::MultiparUpload(QObject *parent) : QObject(parent)
{

}

void MultiparUpload::setDefaultInfo(const QFileInfo &files)
{
    Size = files.size();
    name = files.fileName();
    path = files.filePath();
    block_num = 0;
    block_size = 4 * 1024 * 1024;
    progress = 0;
    QUuid id = QUuid::createUuid();
    uploadID = id.toString();

}
