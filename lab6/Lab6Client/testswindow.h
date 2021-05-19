#ifndef TESTSWINDOW_H
#define TESTSWINDOW_H

#include <QListWidget>
#include "test.h"
#include "question.h"
#include <QMainWindow>
#include <TestClient.h>
#include <QRadioButton>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QGroupBox>
#include <QLayout>

class TestsWindow : public QMainWindow
{
    Q_OBJECT

public:
    TestsWindow(QWidget *parent = nullptr);
    ~TestsWindow();

private slots:
    void handleNextButton();
    void attemptConnection();
    void connectedToServer();
    void attemptTest(const int &index);
    void testIn();
    void testFailed(const QString &reason);
    void testReceived(const Test &test);
    void resultReceived(const double &mark);
    void sendAnswer();
    void disconnectedFromServer();
    void error(QAbstractSocket::SocketError socketError);
private:
    void setQuest(QGroupBox *box);

    TestClient *m_testClient;
    int *m_testIndex;
    double *mark;

    Test choosenTest;
    Question choosenQuestion;

    QCheckBox *check1;
    QCheckBox *check2;
    QCheckBox *check3;
    QCheckBox *check4;

    QRadioButton *button1;
    QRadioButton *button2;
    QRadioButton *button3;
    QRadioButton *button4;

    QPushButton *nextbtn;
    QPushButton *connectbtn;
    QLabel *title;
    QLabel *question;
    QLabel *result;

    QGroupBox *box;
};
#endif // TESTSWINDOW_H
