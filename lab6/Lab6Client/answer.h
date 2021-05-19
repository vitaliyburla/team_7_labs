#ifndef ANSWER_H
#define ANSWER_H

#include <iostream>

using namespace std;

class Answer
{
public:
    Answer(string text);
    string getAnswerText();
    void setAnswerText(string text);

private:
    string answerText;
};

#endif // ANSWER_H
