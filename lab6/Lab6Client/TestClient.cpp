#include <QtNetwork>
#include <TestClient.h>
#include <test.h>

using namespace std;

TestClient::TestClient(QObject *parent) : QObject(parent)
  , m_testIn(false)
  , m_clientSocket(new QTcpSocket(this)) {
    connect(m_clientSocket, &QTcpSocket::connected, this, &TestClient::connected);
    connect(m_clientSocket, &QTcpSocket::disconnected, this, &TestClient::disconnected);
    connect(m_clientSocket, &QTcpSocket::readyRead, this, &TestClient::onReadyRead);
    connect(m_clientSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &TestClient::error);
    connect(m_clientSocket, &QTcpSocket::disconnected, this, [this]()->void{m_testIn = false;});
}

void TestClient::sendAnswer(const QString &answersIndex) {
    QDataStream clientStream(m_clientSocket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    QJsonObject message;
    message["type"] = QStringLiteral("answer");
    message["indexes"] = answersIndex;
    clientStream << QJsonDocument(message).toJson();
}

void TestClient::connectToServer(const QHostAddress &address, quint16 port) {
    m_clientSocket->connectToHost(address, port);
}

void TestClient::disconnectFromHost() {
    m_clientSocket->disconnectFromHost();
}

void TestClient::jsonReceived(const QJsonObject &doc) {
    const QJsonValue typeVal = doc.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("test"), Qt::CaseInsensitive) == 0) {

        if(m_testIn)
            return;

        const QJsonValue testTitle = doc.value(QLatin1String("title"));
        if (testTitle.isNull() || !testTitle.isString())
            return;

        Test *test = new Test(testTitle.toString());

        const QJsonValue testQuestions = doc.value(QLatin1String("questions"));
        if (testQuestions.isNull() || !testQuestions.isArray())
            return;

        vector<Question> quests = {};
        QJsonArray questArray = testQuestions.toArray();
        foreach (const QJsonValue &quest, questArray) {

            const QJsonValue questTitle = quest.toObject().value(QLatin1String("title"));
            if (questTitle.isNull() || !questTitle.isString())
                return;
            Question *question = new Question(questTitle.toString());

            const QJsonValue questMany = quest.toObject().value(QLatin1String("many"));
            if (questMany.isNull() || !questMany.isDouble())
                return;
            question->setManyAnswers((int)questMany.toDouble());

            const QJsonValue questAnswers = quest.toObject().value(QLatin1String("answers"));
            if (questAnswers.isNull() || !questAnswers.isArray())
                return;

            vector<QString> answers = {};
            QJsonArray answersArray = questAnswers.toArray();
            foreach (const QJsonValue answer, answersArray) {
                if (answer.isNull() || !answer.isString())
                    return;
                answers.push_back(answer.toString());
            }
            question->setAnswers(answers);
            quests.push_back(*question);
        }
        test->setQuestions(quests);
        emit testReceived(*test);

    } else if (typeVal.toString().compare(QLatin1String("result"), Qt::CaseInsensitive) == 0) {
        const QJsonValue markVal = doc.value(QLatin1String("mark"));
        if (markVal.isNull() || !markVal.isDouble())
            return;
        emit resultReceived(markVal.toDouble());
    }
}

void TestClient::onReadyRead() {
    QByteArray jsonData;
    QDataStream clientStream(m_clientSocket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    for (;;) {
        clientStream.startTransaction();
        clientStream >> jsonData;
        if (clientStream.commitTransaction()) {
            QJsonParseError parseError;
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
            if (parseError.error == QJsonParseError::NoError) {
                if (jsonDoc.isObject())
                    jsonReceived(jsonDoc.object());
            }
        } else {
            break;
        }
    }
}

void TestClient::setTestIndex(const int &index) {
    QDataStream clientStream(m_clientSocket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    QJsonObject message;
    message["type"] = QStringLiteral("testIndex");
    message["index"] = (double)index;
    clientStream << QJsonDocument(message).toJson();
}
