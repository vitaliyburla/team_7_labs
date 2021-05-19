#include "testswindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QListView>
#include <QListWidget>
#include <iostream>
#include <QRadioButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QLayout>
#include <TestClient.h>
#include <QAbstractListModel>
#include <QDialog>
#include <QMessageBox>
#include <fstream>

using namespace std;

TestsWindow::TestsWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_testClient(new TestClient(this))
{
    setWindowTitle("Testing App");
    setGeometry(100, 100, 400, 400);
    setMinimumSize(400, 400);

    connectbtn = new QPushButton();
    connectbtn->setText("Get Test");
    connectbtn->setGeometry(10, 10, 200, 80);

    title = new  QLabel();
    title->setGeometry(10, 30, 300, 100);
    title->setText(choosenTest.getTitle());

    nextbtn = new QPushButton();
    nextbtn->setText("Next question");
    nextbtn->setGeometry(10, 620, 200, 80);
    nextbtn->setEnabled(false);

    result = new  QLabel();
    result->setGeometry(10, 70, 300, 100);
    result->setText("");

    box = new QGroupBox();

    QWidget *central = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(connectbtn);
    layout->addWidget(title);
    layout->addWidget(box);
    layout->addWidget(nextbtn);

    layout->addStretch(1);
    central->setLayout(layout);
    setCentralWidget(central);

    connect(m_testClient, &TestClient::connected, this, &TestsWindow::connectedToServer);
    connect(m_testClient, &TestClient::testIn, this, &TestsWindow::testIn);
    connect(m_testClient, &TestClient::testError, this, &TestsWindow::testFailed);
    connect(m_testClient, &TestClient::testReceived, this, &TestsWindow::testReceived);
    connect(m_testClient, &TestClient::resultReceived, this, &TestsWindow::resultReceived);
    connect(m_testClient, &TestClient::disconnected, this, &TestsWindow::disconnectedFromServer);
    connect(m_testClient, &TestClient::error, this, &TestsWindow::error);
    connect(m_testClient, &TestClient::connected, this, &TestsWindow::connectedToServer);

    QObject::connect(connectbtn, SIGNAL (clicked()), this, SLOT (attemptConnection()));
    QObject::connect(nextbtn, SIGNAL (clicked()), this, SLOT (handleNextButton()));
}

void TestsWindow::handleNextButton() {
    sendAnswer();

    if (choosenTest.getNumberOfQuestion() + 2 == choosenTest.getQuestions().size()) {
        nextbtn->setText("Get result");
    }
    if (choosenTest.getNumberOfQuestion() + 1 == choosenTest.getQuestions().size()) {
        this->hide();

        QWidget *resWin = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        QLabel *text = new  QLabel();
        text->setGeometry(10, 20, 300, 100);
        text->setText("Your result is:");

        layout->addWidget(text);
        layout->addWidget(result);
        layout->addStretch(1);

        resWin->setLayout(layout);
        resWin->resize(400, 150);
        resWin->setWindowTitle("Result");
        resWin->show();

    } else {
        choosenTest.nextQuestion();
    }

    setQuest(box);
}

TestsWindow::~TestsWindow()
{
}

void TestsWindow::setQuest(QGroupBox *box) {
    choosenQuestion = choosenTest.getCurrentQuestion();
    qDeleteAll(box->children());
    box->setTitle(choosenQuestion.getQuestionText());
    QVBoxLayout *layout = new QVBoxLayout;
    if (choosenQuestion.getManyAnswers() > 1) {

        check1  = new QCheckBox();
        check1->setChecked(false);
        check1->setGeometry(10, 70, 300, 100);
        check1->setText(choosenQuestion.getAnswers()[0]);

        check2  = new QCheckBox();
        check2->setChecked(false);
        check2->setGeometry(10, 120, 300, 100);
        check2->setText(choosenQuestion.getAnswers()[1]);

        check3  = new QCheckBox();
        check3->setChecked(false);
        check3->setGeometry(10, 170, 300, 100);
        check3->setText(choosenQuestion.getAnswers()[2]);

        check4  = new QCheckBox();
        check4->setChecked(false);
        check4->setGeometry(10, 220, 300, 100);
        check4->setText(choosenQuestion.getAnswers()[3]);

        layout->addWidget(check1);
        layout->addWidget(check2);
        layout->addWidget(check3);
        layout->addWidget(check4);
    } else {

        button1  = new QRadioButton();
        button1->setGeometry(10, 70, 300, 100);
        button1->setText(choosenQuestion.getAnswers()[0]);

        button2  = new QRadioButton();
        button2->setGeometry(10, 120, 300, 100);
        button2->setText(choosenQuestion.getAnswers()[1]);

        button3  = new QRadioButton();
        button3->setGeometry(10, 170, 300, 100);
        button3->setText(choosenQuestion.getAnswers()[2]);

        button4  = new QRadioButton();
        button4->setGeometry(10, 220, 300, 100);
        button4->setText(choosenQuestion.getAnswers()[3]);

        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        layout->addWidget(button4);
    }
    layout->addStretch(1);
    box->setLayout(layout);
}

void TestsWindow::attemptConnection() {
    const QString hostAdress = QStringLiteral("127.0.0.1");
    connectbtn->setEnabled(false);
    m_testClient->connectToServer(QHostAddress(hostAdress), 1967);
    attemptTest(1);
}

void TestsWindow::attemptTest(const int &index) {
    m_testClient->setTestIndex(index);
}
void TestsWindow::connectedToServer() {
}

void TestsWindow::testIn() {
}
void TestsWindow::testFailed(const QString &reason) {
    QMessageBox::critical(this, tr("Error"), reason);
    connectedToServer();
}

void TestsWindow::testReceived(const Test &test) {
    choosenTest = test;
    choosenQuestion = choosenTest.getCurrentQuestion();
    setQuest(box);
    title->setText(choosenTest.getTitle());
    nextbtn->setEnabled(true);
}

void TestsWindow::resultReceived(const double &markTotal) {
    result->setText(QString::number(markTotal));
}
void TestsWindow::sendAnswer() {
    string answers = "0000";
        if (choosenQuestion.getManyAnswers() > 1) {
            if (check1->isChecked()) {
                answers[0] = '1';
            }
            if (check2->isChecked()) {
                answers[1] = '1';
            }
            if (check3->isChecked()) {
                answers[2] = '1';
            }
            if (check4->isChecked()) {
                answers[3] = '1';
            }
        } else {
            if (button1->isChecked()) {
                answers[0] = '1';
            }
            if (button2->isChecked()) {
                answers[1] = '1';
            }
            if (button3->isChecked()) {
                answers[2] = '1';
            }
            if (button4->isChecked()) {
                answers[3] = '1';
            }
        }
        m_testClient->sendAnswer(QString::fromStdString(answers));
}
void TestsWindow::disconnectedFromServer() {
    QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
}
void TestsWindow::error(QAbstractSocket::SocketError socketError) {
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
        case QAbstractSocket::ProxyConnectionClosedError:
            return; // handled by disconnectedFromServer
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::critical(this, tr("Error"), tr("The host refused the connection"));
            break;
        case QAbstractSocket::ProxyConnectionRefusedError:
            QMessageBox::critical(this, tr("Error"), tr("The proxy refused the connection"));
            break;
        case QAbstractSocket::ProxyNotFoundError:
            QMessageBox::critical(this, tr("Error"), tr("Could not find the proxy"));
            break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::critical(this, tr("Error"), tr("Could not find the server"));
            break;
        case QAbstractSocket::SocketAccessError:
            QMessageBox::critical(this, tr("Error"), tr("You don't have permissions to execute this operation"));
            break;
        case QAbstractSocket::SocketResourceError:
            QMessageBox::critical(this, tr("Error"), tr("Too many connections opened"));
            break;
        case QAbstractSocket::SocketTimeoutError:
            QMessageBox::warning(this, tr("Error"), tr("Operation timed out"));
            return;
        case QAbstractSocket::ProxyConnectionTimeoutError:
            QMessageBox::critical(this, tr("Error"), tr("Proxy timed out"));
            break;
        case QAbstractSocket::NetworkError:
            QMessageBox::critical(this, tr("Error"), tr("Unable to reach the network"));
            break;
        case QAbstractSocket::UnknownSocketError:
            QMessageBox::critical(this, tr("Error"), tr("An unknown error occured"));
            break;
        case QAbstractSocket::UnsupportedSocketOperationError:
            QMessageBox::critical(this, tr("Error"), tr("Operation not supported"));
            break;
        case QAbstractSocket::ProxyAuthenticationRequiredError:
            QMessageBox::critical(this, tr("Error"), tr("Your proxy requires authentication"));
            break;
        case QAbstractSocket::ProxyProtocolError:
            QMessageBox::critical(this, tr("Error"), tr("Proxy comunication failed"));
            break;
        case QAbstractSocket::TemporaryError:
        case QAbstractSocket::OperationError:
            QMessageBox::warning(this, tr("Error"), tr("Operation failed, please try again"));
            return;
        default:
            Q_UNREACHABLE();
        }
        connectbtn->setEnabled(true);
}
