#ifndef ANSWER_H
#define ANSWER_H

#include <iostream>

using namespace std;

class Answer
{
public:
    Answer(string text, bool isTrue);
    string getAnswerText();
    void setAnswerText(string text);
    bool getIsCorrectAnswer();
    void setIsCorrectAnswer(bool isCorrect);

private:
    string answerText;
    bool isCorrectAnswer;
};

#endif // ANSWER_H
