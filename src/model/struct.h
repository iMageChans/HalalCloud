#ifndef STRUCT_H
#define STRUCT_H

#include <QString>
#include <QJsonArray>

typedef struct{
    QString uuid;
    QString storeId;
    int userId;
    QString path;
    QString name;
    QString ext;
    int size;
    QString parent;
    int type;
    long atime;
    long ctime;
    long mtime;
    int version;
    bool locking;
}ListInfo;

typedef struct{
    int page;
    int pageSize;
    int totalCount;
    int totalPage;
    QJsonArray list;
    ListInfo info;
}ListData;

typedef struct{
    int uuid;
    QString name;
    QString icon;
    QString phone;
    int spaceUsed;
    int spaceCapacity;
}UserInfo;

typedef struct{
    int status;
    UserInfo result;
    QString code;
    bool success;
    QString message;
    QString token;
}User;

typedef struct{
    int status;
    QString result;
    bool success;
}Register;

typedef struct{
    int status;
    QString code;
    bool success;
    QString token;
    ListData result;
}FilesList;



#endif // STRUCT_H
