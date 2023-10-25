#include "readinfo.h"

ReadInfo* ReadInfo::mInstance = NULL;

ReadInfo::ReadInfo(QObject *parent)
    :QObject(parent)
{
    mInstance=this;
}

ReadInfo *ReadInfo::getInstance()
{
    return mInstance;
}

QString ReadInfo::getUserId() const
{
    return userId;
}

void ReadInfo::setUserId(const QString &value)
{
    userId = value;
}

//bool ReadInfo::saveJson()
//{
//    this->jsonObj["userId"] = userId;

//    QFile saveFile(QStringLiteral("test.json"));

//    if(!saveFile.open(QIODevice::WriteOnly)){
//        qWarning("Cound not open json file to save");
//        return false;
//    }

//    QJsonDocument saveDoc(jsonObj);
//    saveFile.write(saveDoc.toJson());
//    showInfo();

//    return true;
//}

bool ReadInfo::loadJson()
{
    QFile loadFile(QStringLiteral("../JsonParsing/test.json"));

    if(!loadFile.open(QIODevice::ReadOnly)){
        qWarning("Could not open json file to read");
        return false;
    }
    QByteArray loadData = loadFile.readAll();
    std::cout << loadData.toStdString() <<std::endl;
    QJsonDocument loadDoc = QJsonDocument::fromJson(loadData);
    jsonObj = loadDoc.object();

    QJsonValue jusersobj = jsonObj.value("users");
    QJsonArray juserArr = jusersobj.toArray();

    for (int i = 0 ; i < juserArr.count();i++){
        QJsonObject subobj = juserArr.at(i).toObject();
        userId = QString::number(subobj.value("userId").toInt());
        showInfo();
    }

    return true;
}

void ReadInfo::showInfo()
{
    qDebug() << ":: userId: " << userId;
}
