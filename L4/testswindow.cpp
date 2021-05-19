#include "testswindow.h"
#include <QLineEdit>
#include <QWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QListView>
#include <QListWidget>
#include <iostream>
#include <QRadioButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QLayout>
#include <test.h>
#include <QAbstractListModel>
#include <QDialog>
#include <inmemorydatabase.h>
#include <QMessageBox>
#include <fstream>
#include <QFileDialog>
#include <QTextStream>


using namespace std;

TestsWindow::TestsWindow(Test test, QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Testing App");
    setGeometry(100, 100, 400, 400);
    setMinimumSize(400, 400);
    choosenTest = test;

    title = new  QLabel();
    title->setGeometry(10, 20, 300, 100);
    title->setText(QString::fromStdString(choosenTest.getTitle()));

    nextbtn = new QPushButton();
    nextbtn->setText("Next question");
    nextbtn->setGeometry(10, 620, 200, 80);

    box = new QGroupBox();
    setQuest(box);

    QWidget *central = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(title);
    layout->addWidget(box);
    layout->addWidget(nextbtn);

    layout->addStretch(1);
    central->setLayout(layout);
    setCentralWidget(central);

    QObject::connect(nextbtn, SIGNAL (clicked()), this, SLOT (handleNextButton()));
}

void TestsWindow::handleNextButton() {
    choosenTest.setMark(choosenTest.getMark() + getMark());
    //saveAnswerToFile("answers.txt");
    saveAnswer();

    if (choosenTest.getNumberOfQuestion() + 2 == choosenTest.getQuestions().size()) {
        nextbtn->setText("Get result");
    }
    if (choosenTest.getNumberOfQuestion() + 1 == choosenTest.getQuestions().size()) {
        this->hide();

        QString path = QFileDialog::getOpenFileName(nullptr, "Opne Text File to write answers",
                                                    "C:/Users/Admin/Documents/Study/SP/build-L4-Desktop_Qt_5_12_10_MinGW_64_bit-Debug",
                                                    "Text files(*.txt);;All files(*.*)");
        QFile file(path);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << QString::fromStdString(answers) << "\n";
            out << "result: " + QString::number(choosenTest.getMark()) << "\n";
            file.close();
        }

        //std::ofstream file;
        //file.open("answers.txt", std::ios_base::app);
        //file << "result: " + std::to_string(choosenTest.getMark()) << "\n";
        //file.close();

        QWidget *resWin = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        QLabel *text = new  QLabel();
        text->setGeometry(10, 20, 300, 100);
        text->setText("Your result is:");

        QLabel *res = new  QLabel();
        res->setGeometry(10, 70, 300, 100);
        res->setText(QString::number(choosenTest.getMark()));

        layout->addWidget(text);
        layout->addWidget(res);
        layout->addStretch(1);

        resWin->setLayout(layout);
        resWin->resize(400, 150);
        resWin->setWindowTitle("Result");
        resWin->show();

        //cout << answers << endl;

        //QMessageBox::about(this, "Result", "Your result is: " + QString::number(choosenTest.getMark()));
    } else {
        choosenTest.nextQuestion();
    }

    setQuest(box);
}

TestsWindow::~TestsWindow()
{
}

double TestsWindow::getMark() {
    double mark = 0;
    if (choosenQuestion.getManyAnswers() > 1) {
        if (check1->isChecked() && choosenQuestion.getAnswers()[0].getIsCorrectAnswer()) {
            mark += (double)1.0/choosenQuestion.getManyAnswers();
        }
        if (check2->isChecked() && choosenQuestion.getAnswers()[1].getIsCorrectAnswer()) {
            mark += (double)1.0/choosenQuestion.getManyAnswers();
        }
        if (check3->isChecked() && choosenQuestion.getAnswers()[2].getIsCorrectAnswer()) {
            mark += (double)1.0/choosenQuestion.getManyAnswers();
        }
        if (check4->isChecked() && choosenQuestion.getAnswers()[3].getIsCorrectAnswer()) {
            mark += (double)1.0/choosenQuestion.getManyAnswers();
        }
    } else {
        if (button1->isChecked() && choosenQuestion.getAnswers()[0].getIsCorrectAnswer()) {
            mark++;
        }
        if (button2->isChecked() && choosenQuestion.getAnswers()[1].getIsCorrectAnswer()) {
            mark++;
        }
        if (button3->isChecked() && choosenQuestion.getAnswers()[2].getIsCorrectAnswer()) {
            mark++;
        }
        if (button4->isChecked() && choosenQuestion.getAnswers()[3].getIsCorrectAnswer()) {
            mark++;
        }
    }
    return mark;
}

void TestsWindow::setQuest(QGroupBox *box) {
    choosenQuestion = choosenTest.getCurrentQuestion();
    qDeleteAll(box->children());
    box->setTitle(QString::fromStdString(choosenQuestion.getQuestionText()));
    QVBoxLayout *layout = new QVBoxLayout;
    if (choosenQuestion.getManyAnswers() > 1) {

        check1  = new QCheckBox();
        check1->setChecked(false);
        check1->setGeometry(10, 70, 300, 100);
        check1->setText(QString::fromStdString(choosenQuestion.getAnswers()[0].getAnswerText()));

        check2  = new QCheckBox();
        check2->setChecked(false);
        check2->setGeometry(10, 120, 300, 100);
        check2->setText(QString::fromStdString(choosenQuestion.getAnswers()[1].getAnswerText()));

        check3  = new QCheckBox();
        check3->setChecked(false);
        check3->setGeometry(10, 170, 300, 100);
        check3->setText(QString::fromStdString(choosenQuestion.getAnswers()[2].getAnswerText()));

        check4  = new QCheckBox();
        check4->setChecked(false);
        check4->setGeometry(10, 220, 300, 100);
        check4->setText(QString::fromStdString(choosenQuestion.getAnswers()[3].getAnswerText()));

        layout->addWidget(check1);
        layout->addWidget(check2);
        layout->addWidget(check3);
        layout->addWidget(check4);
    } else {

        button1  = new QRadioButton();
        button1->setGeometry(10, 70, 300, 100);
        button1->setText(QString::fromStdString(choosenQuestion.getAnswers()[0].getAnswerText()));

        button2  = new QRadioButton();
        button2->setGeometry(10, 120, 300, 100);
        button2->setText(QString::fromStdString(choosenQuestion.getAnswers()[1].getAnswerText()));

        button3  = new QRadioButton();
        button3->setGeometry(10, 170, 300, 100);
        button3->setText(QString::fromStdString(choosenQuestion.getAnswers()[2].getAnswerText()));

        button4  = new QRadioButton();
        button4->setGeometry(10, 220, 300, 100);
        button4->setText(QString::fromStdString(choosenQuestion.getAnswers()[3].getAnswerText()));

        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        layout->addWidget(button4);
    }
    layout->addStretch(1);
    box->setLayout(layout);
}
void TestsWindow::saveAnswerToFile(string filename) {
    std::ofstream file;
    file.open(filename, std::ios_base::app);
    std::string answer = "";

    if (choosenQuestion.getManyAnswers() > 1){
        if (check1->isChecked()){
            answer += choosenQuestion.getAnswers()[0].getAnswerText() + "; ";}
        if (check2->isChecked()){
            answer += choosenQuestion.getAnswers()[1].getAnswerText() + "; ";}
        if (check3->isChecked()){
            answer += choosenQuestion.getAnswers()[2].getAnswerText() + "; ";}
        if (check4->isChecked()){
            answer += choosenQuestion.getAnswers()[3].getAnswerText() + "; ";}
    } else {
    if (button1->isChecked()){
        answer += choosenQuestion.getAnswers()[0].getAnswerText() + "; ";}
    if (button2->isChecked()){
        answer += choosenQuestion.getAnswers()[1].getAnswerText() + "; ";}
    if (button3->isChecked()){
        answer += choosenQuestion.getAnswers()[2].getAnswerText() + "; ";}
    if (button4->isChecked()){
        answer += choosenQuestion.getAnswers()[3].getAnswerText() + "; ";}
        }

    if (file.is_open()){
        file << std::to_string(choosenTest.getNumberOfQuestion() + 1) + " " + answer + " " + std::to_string(getMark()) << "\n";
        file.close();
    }

    answers += std::to_string(choosenTest.getNumberOfQuestion() + 1) + " " + answer + " " + std::to_string(getMark()) + "\n";
}

void TestsWindow::saveAnswer() {
    std::string answer = "";
    if (choosenQuestion.getManyAnswers() > 1){
        if (check1->isChecked()){
            answer += choosenQuestion.getAnswers()[0].getAnswerText() + "; ";}
        if (check2->isChecked()){
            answer += choosenQuestion.getAnswers()[1].getAnswerText() + "; ";}
        if (check3->isChecked()){
            answer += choosenQuestion.getAnswers()[2].getAnswerText() + "; ";}
        if (check4->isChecked()){
            answer += choosenQuestion.getAnswers()[3].getAnswerText() + "; ";}
    } else {
    if (button1->isChecked()){
        answer += choosenQuestion.getAnswers()[0].getAnswerText() + "; ";}
    if (button2->isChecked()){
        answer += choosenQuestion.getAnswers()[1].getAnswerText() + "; ";}
    if (button3->isChecked()){
        answer += choosenQuestion.getAnswers()[2].getAnswerText() + "; ";}
    if (button4->isChecked()){
        answer += choosenQuestion.getAnswers()[3].getAnswerText() + "; ";}
        }
    answers += std::to_string(choosenTest.getNumberOfQuestion() + 1) + " " + answer + " " + std::to_string(getMark()) + "\n";
}
