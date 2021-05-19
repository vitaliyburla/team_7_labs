#include "answer.h"

Answer::Answer(string text, bool isTrue)
{
    answerText = text;
    isCorrectAnswer = isTrue;
}

string Answer::getAnswerText() {
    return answerText;
}

void Answer::setAnswerText(string text) {
    answerText = text;
}

bool Answer::getIsCorrectAnswer() {
    return isCorrectAnswer;
}

void Answer::setIsCorrectAnswer(bool isCorrect) {
    isCorrectAnswer = isCorrect;
}
