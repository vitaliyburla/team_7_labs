#include "test.h"

Test::Test()
{
}

void Test::setQuestions(vector<Question> newQuestions) {
    questions = newQuestions;
    currentQuestion = questions[numberOfQuestion];
}

vector<Question> Test::getQuestions() {
    return questions;
}

string Test::getTitle() {
    return title;
}

void Test::setTitle(string titleText) {
    title = titleText;
}

Question Test::getCurrentQuestion() {
    return currentQuestion;
}

void Test::setCurrentQuestion(Question question) {
    currentQuestion = question;
}

int Test::getNumberOfQuestion() {
    return numberOfQuestion;
}

void Test::setNumberOfQuestion(int number) {
    numberOfQuestion = number;
}

double Test::getMark() {
    return resultMark;
}

void Test::setMark(double mark) {
    resultMark = mark;
}

void Test::nextQuestion() {
    this->setNumberOfQuestion(this->getNumberOfQuestion() + 1);
    this->setCurrentQuestion(this->getQuestions()[this->getNumberOfQuestion()]);
}
