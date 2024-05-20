#ifndef SERVERCONNECTOR_H
#define SERVERCONNECTOR_H

#include <QApplication>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>
#include "Person.h"

class ServerConnector : public QObject
{
    Q_OBJECT
public:
    ServerConnector();

    void setHost(QString host);

    int Authorize(QString login, QString pass);
    bool ManualPass(Person *person, int wicketId);
    void SOS(int checkPointId);

private slots:
    void ReplyFinished(QNetworkReply *reply);

private:
    QString host = "127.0.0.1";
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    QEventLoop *eventLoop = new QEventLoop;

};

#endif // SERVERCONNECTOR_H
