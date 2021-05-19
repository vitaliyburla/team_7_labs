#ifndef TESTSWINDOW_H
#define TESTSWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include <test.h>
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
    TestsWindow(Test test, QWidget *parent = nullptr);
    TestsWindow(QWidget *parent = nullptr);
    ~TestsWindow();

    double getMark();

    void setQuest(QGroupBox *box);

private slots:
    void handleNextButton();

private:
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
    QLabel *title;
    QLabel *question;

    QGroupBox *box;
};
#endif // TESTSWINDOW_H
