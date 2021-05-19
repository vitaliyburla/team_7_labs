#ifndef SERVERWORKER_H
#define SERVERWORKER_H

#include <QtNetwork>
#include <test.h>
#include <inmemorydatabase.h>

using namespace std;

class ServerWorker : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ServerWorker)
public:
    ServerWorker(InMemoryDatabase *database, QObject *parent = nullptr);
    virtual bool setSocketDescriptior(qintptr socketDescriptior);
    Test test() const;
    void getTest(const int &index);
    void getMark(const QString &indexes);
    void sendJson(const QJsonObject &jsonData);
signals:
    void jsonReceived(const QJsonObject &jsonDoc);
    void error();
    void disconnectedFromClient();
    void logMessage(const QString &msg);
public slots:
    void disconnectFromClient();
private slots:
    void receiveJson();

private:
    InMemoryDatabase *m_database;
    Test m_test;
    QTcpSocket *m_serverSocket;
};

#endif // SERVERWORKER_H
