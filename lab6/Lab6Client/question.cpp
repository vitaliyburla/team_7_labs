#include "question.h"
#include <iostream>

using namespace std;

Question::Question()
{
}

Question::Question(QString text) {
    question = text;
}

vector<QString> Question::getAnswers() {
    return answers;
}

void Question::setAnswers(vector<QString> ans) {
    answers = ans;
}

void Question::setQuestionText(QString questionText) {
    question = questionText;
}

QString Question::getQuestionText() {
    return question;
}

void Question::setManyAnswers(int many) {
    manyAnswers = many;
}
int Question::getManyAnswers() {
    return manyAnswers;
}
