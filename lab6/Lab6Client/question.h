#ifndef QUESTION_H
#define QUESTION_H

#include <map>
#include <iostream>
#include <vector>
#include <QString>

using namespace std;

class Question
{
public:
    Question();
    Question(QString text);

    vector<QString> getAnswers();
    void setAnswers(vector<QString> ans);

    void setQuestionText(QString question);
    QString getQuestionText();

    void setManyAnswers(int many);
    int getManyAnswers();

private:
    vector<QString> answers;
    QString question;
    int manyAnswers;
};

#endif // QUESTION_H
