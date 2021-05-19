#include <QtNetwork>
#include <ServerWorker.h>
#include <TestServer.h>

using namespace std;

TestServer::TestServer(InMemoryDatabase *database, QObject *parent) : QTcpServer(parent) {
    m_database = database;
}

TestServer::TestServer(QObject *parent) : QTcpServer(parent) {
    m_database = new InMemoryDatabase();
}

void TestServer::incomingConnection(qintptr socketDescriptor) {
    ServerWorker *worker = new ServerWorker(m_database, this);
    if (!worker->setSocketDescriptior(socketDescriptor)) {
        worker->deleteLater();
        return;
    }
    connect(worker, &ServerWorker::disconnectedFromClient, this, std::bind(&TestServer::userDisconnected, this, worker));
    connect(worker, &ServerWorker::error, this, std::bind(&TestServer::userError, this, worker));
    connect(worker, &ServerWorker::jsonReceived, this, std::bind(&TestServer::jsonReceived, this, worker, std::placeholders::_1));
    connect(worker, &ServerWorker::logMessage, this, &TestServer::logMessage);
    m_clients.append(worker);
    emit logMessage(QStringLiteral("New client Connected"));
}

void TestServer::sendJson(ServerWorker *destination, const QJsonObject &doc) {
    Q_ASSERT(destination);
    destination->sendJson(doc);
}

void TestServer::broadcast(const QJsonObject &message, ServerWorker *exclude) {
    for (ServerWorker *worker : m_clients) {
        if (worker == exclude)
            continue;
        sendJson(worker, message);
    }
}

void TestServer::stopServer() {
    for (ServerWorker *worker : m_clients) {
        worker->disconnectFromClient();
    }
    close();
}

void TestServer::jsonReceived(ServerWorker *sender, const QJsonObject &doc) {
    Q_ASSERT(sender);
    emit logMessage(QStringLiteral("Main server JSON received ") + QString::fromUtf8(QJsonDocument(doc).toJson()));
}

void TestServer::userDisconnected(ServerWorker *sender) {
    m_clients.removeAll(sender);
    emit logMessage(QStringLiteral("Disconnected"));
    sender->deleteLater();
}

void TestServer::userError(ServerWorker *sender) {
    Q_UNUSED(sender);
    emit logMessage(QStringLiteral("Error"));
}
