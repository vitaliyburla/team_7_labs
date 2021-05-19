#include <QtNetwork>
#include <ServerWorker.h>

using namespace std;

ServerWorker::ServerWorker(InMemoryDatabase *database, QObject *parent) : QObject(parent)
  , m_serverSocket(new QTcpSocket(this)) {
    m_database = database;
    connect(m_serverSocket, &QTcpSocket::readyRead, this, &ServerWorker::receiveJson);
    connect(m_serverSocket, &QTcpSocket::disconnected, this, &ServerWorker::disconnectedFromClient);
    connect(m_serverSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &ServerWorker::error);
}
bool ServerWorker::setSocketDescriptior(qintptr socketDescriptior) {
    return m_serverSocket->setSocketDescriptor(socketDescriptior);
}

void ServerWorker::disconnectFromClient() {
    m_serverSocket->disconnectFromHost();
}

void ServerWorker::receiveJson() {
    QByteArray jsonData;
    QDataStream clientStream(m_serverSocket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    for (;;) {
        clientStream.startTransaction();
        clientStream >> jsonData;
        if (clientStream.commitTransaction()) {
            QJsonParseError parseError;
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
            if (parseError.error == QJsonParseError::NoError) {
                if (jsonDoc.isObject()) {
                    emit jsonReceived(jsonDoc.object());
                    const QJsonValue typeVal = jsonDoc.object().value(QLatin1String("type"));
                    if (typeVal.isNull() || !typeVal.isString())
                        return;
                    if (typeVal.toString().compare(QLatin1String("testIndex"), Qt::CaseInsensitive) == 0) {
                        const QJsonValue index = jsonDoc.object().value(QLatin1String("index"));
                        if (index.isNull() || !index.isDouble())
                            return;
                        getTest((int)index.toDouble());
                    } else if (typeVal.toString().compare(QLatin1String("answer"), Qt::CaseInsensitive) == 0) {
                        const QJsonValue index = jsonDoc.object().value(QLatin1String("indexes"));
                        if (index.isNull() || !index.isString())
                            return;
                        getMark(index.toString());
                    }
                }
                else
                    emit logMessage("Invalid message: " + QString::fromUtf8(jsonData));
            } else {
                emit logMessage("Invalid message: " + QString::fromUtf8(jsonData));
            }
        } else {
            break;
        }
    }
}

void ServerWorker::sendJson(const QJsonObject &jsonData) {
    const QByteArray json = QJsonDocument(jsonData).toJson(QJsonDocument::Compact);
    emit logMessage("Sending: " + QString::fromUtf8(json));
    QDataStream socketStream(m_serverSocket);
    socketStream.setVersion(QDataStream::Qt_5_7);
    socketStream << json;
}

Test ServerWorker::test() const {
    return m_test;
}
void ServerWorker::getTest(const int &index) {
    m_test = m_database->getTestFromDatabase(index);
    QJsonObject test;
    test.insert(QString::fromStdString("type"), QJsonValue("test"));
    test.insert(QString::fromStdString("title"), QJsonValue(QString::fromStdString(m_test.getTitle())));
    QJsonArray questions;
    for (Question &quest : m_test.getQuestions()) {
        QJsonObject question;
        question.insert(QString::fromStdString("title"), QJsonValue(QString::fromStdString(quest.getQuestionText())));
        question.insert(QString::fromStdString("many"), QJsonValue((double)quest.getManyAnswers()));
        QJsonArray answers;
        for (Answer &ans : quest.getAnswers()) {
            answers.append(QJsonValue(QString::fromStdString(ans.getAnswerText())));
        }
        question.insert(QString::fromStdString("answers"), QJsonValue(answers));
        questions.append(QJsonValue(question));
    }
    test.insert(QString::fromStdString("questions"), QJsonValue(questions));
    sendJson(test);
}

void ServerWorker::getMark(const QString &indexes) {
    Question choosenQuestion = m_test.getCurrentQuestion();
    string answers = indexes.toStdString();

    double mark = 0;
        if (choosenQuestion.getManyAnswers() > 1) {
            if (answers[0] == '1' && choosenQuestion.getAnswers()[0].getIsCorrectAnswer()) {
                mark += (double)1.0/choosenQuestion.getManyAnswers();
            }
            if (answers[1] == '1' && choosenQuestion.getAnswers()[1].getIsCorrectAnswer()) {
                mark += (double)1.0/choosenQuestion.getManyAnswers();
            }
            if (answers[2] == '1' && choosenQuestion.getAnswers()[2].getIsCorrectAnswer()) {
                mark += (double)1.0/choosenQuestion.getManyAnswers();
            }
            if (answers[3] == '1' && choosenQuestion.getAnswers()[3].getIsCorrectAnswer()) {
                mark += (double)1.0/choosenQuestion.getManyAnswers();
            }
        } else {
            if (answers[0] == '1' && choosenQuestion.getAnswers()[0].getIsCorrectAnswer()) {
                mark++;
            }
            if (answers[1] == '1' && choosenQuestion.getAnswers()[1].getIsCorrectAnswer()) {
                mark++;
            }
            if (answers[2] == '1' && choosenQuestion.getAnswers()[2].getIsCorrectAnswer()) {
                mark++;
            }
            if (answers[3] == '1' && choosenQuestion.getAnswers()[3].getIsCorrectAnswer()) {
                mark++;
            }
        }
        m_test.setMark(m_test.getMark() + mark);
        if (m_test.getNumberOfQuestion() + 1 == m_test.getQuestions().size()) {
            QJsonObject result;
            result.insert(QString::fromStdString("type"), QJsonValue("result"));
            result.insert(QString::fromStdString("mark"), QJsonValue(m_test.getMark()));
            sendJson(result);
            m_database->addNewResult(m_test.getMark());
        } else {
            m_test.nextQuestion();
        }
}
