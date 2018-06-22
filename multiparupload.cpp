#include "multiparupload.h"

MultiparUpload::MultiparUpload(QObject *parent) : QObject(parent)
{
    block_size = 1024 * 1024 * 4;
    bput_size = 512 * 1024;
}
