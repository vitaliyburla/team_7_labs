#ifndef TEST_H
#define TEST_H
#include <question.h>
#include <iostream>
#include <vector>

using namespace std;

class Test
{
public:
    Test();
    void setQuestions(vector<Question>);
    vector<Question> getQuestions();
    void setTitle(string text);
    string getTitle();
    void setCurrentQuestion(Question question);
    Question getCurrentQuestion();
    void nextQuestion();
    void getResultOfTest();
    int getNumberOfQuestion();
    void setNumberOfQuestion(int number);
    void setMark(double mark);
    double getMark();

private:
    vector<Question> questions;
    string title;
    Question currentQuestion;
    int numberOfQuestion = 0;
    double resultMark = 0;
};

#endif // TEST_H
