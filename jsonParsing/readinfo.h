#ifndef READINFO_H
#define READINFO_H

#include <stdio.h>
#include <iostream>
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>

class ReadInfo :public QObject {
    Q_OBJECT
public:
    ReadInfo(QObject *parent = nullptr);
    static ReadInfo *getInstance();
    static ReadInfo *mInstance;

    QJsonObject jsonObj;
    QString getUserId() const;
    void setUserId(const QString &value);

    //    Q_INVOKABLE bool saveJson();
    Q_INVOKABLE bool loadJson();

    void showInfo();
    QString userId;
};
#endif // READINFO_H
