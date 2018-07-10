#ifndef NETWORKDATA_H
#define NETWORKDATA_H

#include <QByteArray>

template <typename data>
QByteArray LoginData(const data &value, const data &password){
    QByteArray datas;
    datas.append("value=" + value);
    datas.append("&password=" + password);
    return datas;
};

template <typename data>
QByteArray LoginOutData(const data &time){
    QByteArray datas;
    datas.append("time=" + QString::number(time));
    return datas;
};

template <typename List>
QByteArray FilesListData(const List &Parent, const List &Path, const List &OrderBy, const List &Type){
    QByteArray datas;
    datas.append("parent=" + Parent);
    datas.append("&path=" + Path);
    datas.append("&recycle=-1");
    datas.append("&orderBy=" +  OrderBy);
    datas.append("&type=" +  Type);
    return datas;
};

#endif // NETWORKDATA_H
