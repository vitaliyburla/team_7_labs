#ifndef TEST_H
#define TEST_H
#include <question.h>
#include <iostream>
#include <vector>
#include <QString>

using namespace std;

class Test
{
public:
    Test();
    Test(QString title);

    void setQuestions(vector<Question>);
    vector<Question> getQuestions();
    void setTitle(QString text);
    QString getTitle();
    void setCurrentQuestion(Question question);
    Question getCurrentQuestion();
    void nextQuestion();

    int getNumberOfQuestion();
    void setNumberOfQuestion(int number);

private:
    vector<Question> questions;
    QString title;
    Question currentQuestion;
    int numberOfQuestion = 0;
};

#endif // TEST_H
