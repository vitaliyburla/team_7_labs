#include "question.h"
#include <iostream>
#include <answer.h>

using namespace std;

Question::Question()
{
}

vector<Answer> Question::getAnswers() {
    return answers;
}

void Question::setAnswers(vector<Answer> ans) {
    answers = ans;
}

void Question::setQuestionText(string questionText) {
    question = questionText;
}

string Question::getQuestionText() {
    return question;
}

void Question::setManyAnswers(int many) {
    manyAnswers = many;
}
int Question::getManyAnswers() {
    return manyAnswers;
}
