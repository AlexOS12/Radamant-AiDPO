#include "serverconnector.h"

ServerConnector::ServerConnector() {
    manager = new QNetworkAccessManager(this);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), eventLoop, SLOT(quit()));
}

void ServerConnector::setHost(QString host)
{
    this->host = host;
}

int ServerConnector::Authorize(QString login, QString pass)
{
    QUrl url("http://" + this->host + "/api/Staffs");
    QUrlQuery query;
    query.addQueryItem("login", login);
    query.addQueryItem("pass", pass);

    url.setQuery(query.query());

    qDebug() << "Sending request to" << url.toString();

    QNetworkRequest req(url);
    QNetworkReply *reply = manager->get(req);
    eventLoop->exec();

    if (reply->error() == QNetworkReply::NoError) {
        QString rep = reply->readAll();
        qDebug() << "Got: " << rep;
        delete reply;

        try {
            return rep.toInt();
        } catch (...) {
            return -1;
        }
    } else {
        qDebug() << "Error: " << reply->errorString();
        return -1;
    }

}

bool ServerConnector::ManualPass(Person *person, int wicketId)
{
    QUrl url("http://" + this->host + "/api/WicketLogs");

    QUrlQuery query;
    query.addQueryItem("wicketId", QString::number(wicketId));
    query.addQueryItem("lastName", person->lastname);
    query.addQueryItem("passport", person->passport);
    query.addQueryItem("message",  "Manual Pass");

    url.setQuery(query.query());

    qDebug() << "Sending request to: " << url.toString();

    QNetworkRequest req(url);
    QNetworkReply *reply = manager->get(req);

    eventLoop->exec();

    if (reply->error() == QNetworkReply::NoError) {
        QString rep = reply->readAll();
        qDebug() << "Got: " << rep;
        if (rep == "1") {
            return true;
        } else {
            return false;
        }
    }
    else {
        qDebug() << "Failed: " << reply->errorString();
        return false;
    }
    delete reply;
}

void ServerConnector::SOS(int checkPointId)
{
    QUrl url("http://" + this->host + "/api/SOS");

    QUrlQuery query;
    query.addQueryItem("checkPointId", QString::number(checkPointId));

    url.setQuery(query.query());

    qDebug() << "Sending request to: " << url.toString();

    QNetworkRequest req(url);
    QNetworkReply *reply = manager->get(req);


    eventLoop->exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Got: " << reply->readAll();
    } else {
        qDebug() << "Failed: " << reply->errorString();
    }
    delete reply;
}



void ServerConnector::ReplyFinished(QNetworkReply *reply)
{
    qDebug() << "123";
    QString answer = reply->readAll();
    qDebug() << "Answer: " << answer;
}

