#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class QByteArray;
class Util;

typedef struct{
    QString uuid;
    QString name;
    QString icon;
    QString spaceUsed;
    QString spaceCapacity;
}UserInfo;

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0);
    UserInfo getUserInfo(const QByteArray &Data);

signals:

public slots:

private:
    Util *util;
    UserInfo userInfo;
};

#endif // MODEL_H
