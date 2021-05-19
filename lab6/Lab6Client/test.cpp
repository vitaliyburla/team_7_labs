#include "test.h"

Test::Test()
{
}

Test::Test(QString titleText) {
    title = titleText;
}

void Test::setQuestions(vector<Question> newQuestions) {
    questions = newQuestions;
    currentQuestion = questions[numberOfQuestion];
}

vector<Question> Test::getQuestions() {
    return questions;
}

QString Test::getTitle() {
    return title;
}

void Test::setTitle(QString titleText) {
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

void Test::nextQuestion() {
    this->setNumberOfQuestion(this->getNumberOfQuestion() + 1);
    this->setCurrentQuestion(this->getQuestions()[this->getNumberOfQuestion()]);
}
