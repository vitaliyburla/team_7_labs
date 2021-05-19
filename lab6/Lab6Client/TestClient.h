#ifndef TESTCLIENT_H
#define TESTCLIENT_H

#include <QtNetwork>
#include <test.h>

using namespace std;

class TestClient : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(TestClient)
public:
    explicit TestClient(QObject *parent = nullptr);

public slots:
    void connectToServer(const QHostAddress &address, quint16 port);
    void setTestIndex(const int &index);
    void sendAnswer(const QString &answersIndex);
    void disconnectFromHost();
private slots:
    void onReadyRead();
signals:
    void connected();
    void testIn();
    void testError(const QString &reason);
    void disconnected();
    void testReceived(const Test &test);
    void resultReceived(const double &mark);
    void error(QAbstractSocket::SocketError socketError);
private:
    QTcpSocket *m_clientSocket;
    bool m_testIn;
    void jsonReceived(const QJsonObject &doc);
};

#endif // TESTCLIENT_H
