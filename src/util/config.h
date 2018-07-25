#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

struct UserInfo{
    QString name;
};

struct FilesInfo{
    QString name;
    QString Size;
    QString Mine;
    QString uuid;
    QString Path;
};

class Config
{
public:
    Config();
};

#endif // CONFIG_H
