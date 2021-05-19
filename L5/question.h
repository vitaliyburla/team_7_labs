#ifndef QUESTION_H
#define QUESTION_H

#include <map>
#include <iostream>
#include <vector>
#include <answer.h>

using namespace std;

class Question
{
public:
    Question();

    vector<Answer> getAnswers();
    void setAnswers(vector<Answer> ans);

    void setQuestionText(string question);
    string getQuestionText();

    void setManyAnswers(int many);
    int getManyAnswers();

private:
    vector<Answer> answers;
    string question;
    int manyAnswers;
};

#endif // QUESTION_H
