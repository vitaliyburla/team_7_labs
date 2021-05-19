#ifndef TESTSERVER_H
#define TESTSERVER_H

#include <QtNetwork>
#include <ServerWorker.h>
#include <inmemorydatabase.h>

using namespace std;

class TestServer : public QTcpServer
{
    Q_OBJECT
    Q_DISABLE_COPY(TestServer)
public:
    TestServer(InMemoryDatabase *database, QObject *parent = nullptr);
    TestServer(QObject *parent = nullptr);
protected:
    void incomingConnection(qintptr socketDescriptor) override;
signals:
    void logMessage(const QString &msg);
public slots:
    void stopServer();
private slots:
    void broadcast(const QJsonObject &message, ServerWorker *exclude);
    void jsonReceived(ServerWorker *sender, const QJsonObject &doc);
    void userDisconnected(ServerWorker *sender);
    void userError(ServerWorker *sender);
private:
    InMemoryDatabase *m_database;
    void sendJson(ServerWorker *destination, const QJsonObject &doc);
    QVector<ServerWorker *> m_clients;
};

#endif // TESTSERVER_H
