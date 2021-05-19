#include "inmemorydatabase.h"
#include "question.h"
#include "test.h"
#include <answer.h>
#include <fstream>
#include <chrono>
#include <ctime>
#include <QVariant>
#include <QtSql>
#include <QSqlQuery>

InMemoryDatabase::InMemoryDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("myDatabase.sqlite");
    setListOfTests();
}

InMemoryDatabase::InMemoryDatabase(string path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString::fromStdString(path));
    setListOfTests();
}

Test InMemoryDatabase::getTest(int index) {
    return listOfTests[index];
}

void InMemoryDatabase::setListOfTests(vector<Test> list) {
    listOfTests = list;
}

void InMemoryDatabase::setListOfTests() {
    db.open();
    if (db.isOpen()) {

    QSqlQuery *q0 = new QSqlQuery();
    q0->exec("SELECT * FROM Tests");
    int id = 1;
        while (q0->next()) {

    QSqlQuery *q = new QSqlQuery();

    Test *test = new Test();

    q->exec("SELECT Name FROM Tests WHERE ID=" + QString::number(id));
    while (q->next()) {
        test->setTitle(q->value(0).toString().toStdString());
    }

    vector<Question> questions = {};

    q->exec("SELECT QuestionID FROM TestQuestion WHERE TestID=" + QString::number(id));
    while (q->next()) {
        QSqlQuery q1;
        q1.exec("SELECT QuestionText FROM Questions WHERE ID=" + q->value(0).toString());

        Question *question = new Question();
        vector<Answer> answers = {};
        int manyAns = 0;

        while (q1.next()) {
            question->setQuestionText(q1.value(0).toString().toStdString());
        }

        QSqlQuery q2;
        q2.exec("SELECT AnswerID FROM QuestionAnswer WHERE QuestionID=" + q->value(0).toString());
        while (q2.next()) {

            QSqlQuery q3;
            q3.exec("SELECT AnswerText, IsCorrect FROM Answers WHERE ID=" + q2.value(0).toString());
            while (q3.next()) {
                if (q3.value(1).toBool() == 1) {
                    manyAns++;
                }
                Answer *answer = new Answer(q3.value(0).toString().toStdString(), q3.value(1).toBool());
                answers.push_back(*answer);
            }
            question->setAnswers(answers);
            question->setManyAnswers(manyAns);
        }
        questions.push_back(*question);
    }
    test->setQuestions(questions);

    listOfTests.push_back(*test);
    id++;
        }
    db.close();
    }
}

void InMemoryDatabase::setDBfromFile(string path) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString::fromStdString(path));
}

void InMemoryDatabase::addNewResult(double mark) {
    db.open();
    if (db.isOpen()) {
    QSqlQuery q;

    time_t now = time(0);

    tm *ltm = localtime(&now);

    string year = std::to_string(1900 + ltm->tm_year);
    string month = std::to_string(1 + ltm->tm_mon);
    string day = std::to_string(ltm->tm_mday);
    string hours = std::to_string(ltm->tm_hour);
    string mins = std::to_string(ltm->tm_min);
    string sec = std::to_string(ltm->tm_sec);

    string datestring = year + "-" + month + "-" + day + " " + hours + ":" + mins + ":" + sec;
    cout << datestring << endl;

    string str = "INSERT INTO Results (Mark, EndDate) VALUES (" + std::to_string(mark) + ", '" + datestring +"');";
    if (q.exec(QString::fromStdString(str))) {
        cout << "ok" << endl;
    } else {
        cout << "error: " + q.lastError().text().toStdString() << endl;
    }
    db.close();
    }
}

Test InMemoryDatabase::getTestFromDatabase(int id){
    db.open();
    if (db.isOpen()) {
    QSqlQuery *q = new QSqlQuery();

    Test *test = new Test();

    q->exec("SELECT Name FROM Tests WHERE ID=" + QString::number(id));
    while (q->next()) {
        test->setTitle(q->value(0).toString().toStdString());
    }

    vector<Question> questions = {};

    q->exec("SELECT QuestionID FROM TestQuestion WHERE TestID=" + QString::number(id));
    while (q->next()) {
        QSqlQuery q1;
        q1.exec("SELECT QuestionText FROM Questions WHERE ID=" + q->value(0).toString());

        Question *question = new Question();
        vector<Answer> answers = {};
        int manyAns = 0;

        while (q1.next()) {
            question->setQuestionText(q1.value(0).toString().toStdString());
        }

        QSqlQuery q2;
        q2.exec("SELECT AnswerID FROM QuestionAnswer WHERE QuestionID=" + q->value(0).toString());
        while (q2.next()) {

            QSqlQuery q3;
            q3.exec("SELECT AnswerText, IsCorrect FROM Answers WHERE ID=" + q2.value(0).toString());
            while (q3.next()) {
                if (q3.value(1).toBool() == 1) {
                    manyAns++;
                }
                Answer *answer = new Answer(q3.value(0).toString().toStdString(), q3.value(1).toBool());
                answers.push_back(*answer);
            }
            question->setAnswers(answers);
            question->setManyAnswers(manyAns);
        }
        questions.push_back(*question);
    }
    test->setQuestions(questions);
    db.close();
    return *test;
    }
}
