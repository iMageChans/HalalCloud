#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QVector>

struct UserInfo
{
    QString name;
    QString uuid;
    QString ban;
};

struct FilesInfo
{
    QString name;
    QString Size;
    QString Mine;
    QString uuid;
    QString Path;
    QString duration;
    QString maxClear;
    QVector<QString> video;
};

struct setData
{
    QString name;
    QString uuid;
    QString Mime;
    QString Parent;
    QString username;
    QString password;
};



class Config
{
public:
    Config();
};

#endif // CONFIG_H
