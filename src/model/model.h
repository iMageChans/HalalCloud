#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class QJsonValue;

struct userInfo{
    QString uuid;
    QString name;
    QString icon;
    QString spaceUsed;
    QString spaceCapacity;
};

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0);
    userInfo getUserInfo(const QJsonValue Data);

signals:

public slots:
};

#endif // MODEL_H
