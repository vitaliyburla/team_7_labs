#include "inmemorydatabase.h"
#include "question.h"
#include "test.h"
#include <answer.h>

InMemoryDatabase::InMemoryDatabase()
{
    Question *question1 = new Question();
    question1->setQuestionText("2 + 2 = ?");
    Answer *answer1 = new Answer("3", false);
    Answer *answer2 = new Answer("4", true);
    Answer *answer3 = new Answer("5", false);
    Answer *answer4 = new Answer("6", false);
    vector<Answer> answers1 = {*answer1, *answer2, *answer3, *answer4};
    question1->setAnswers(answers1);
    question1->setManyAnswers(1);

    Question *question2 = new Question();
    question2->setQuestionText("8 = ?");
    Answer *answer5 = new Answer("3 + 3", false);
    Answer *answer6 = new Answer("7 + 1", true);
    Answer *answer7 = new Answer("2 + 7", false);
    Answer *answer8 = new Answer("9 - 1", true);
    vector<Answer> answers2 = {*answer5, *answer6, *answer7, *answer8};
    question2->setAnswers(answers2);
    question2->setManyAnswers(2);

    Question *question3 = new Question();
    question3->setQuestionText("3 + 5 = ?");
    Answer *answer9 = new Answer("8", true);
    Answer *answer10 = new Answer("9", false);
    Answer *answer11 = new Answer("10", false);
    Answer *answer12 = new Answer("11", false);
    vector<Answer> answers3 = {*answer9, *answer10, *answer11, *answer12};
    question3->setAnswers(answers3);
    question3->setManyAnswers(1);

    Question *question4 = new Question();
    question4->setQuestionText("42 = ?");
    Answer *answer13 = new Answer("3 * 14", true);
    Answer *answer14 = new Answer("88 / 2", false);
    Answer *answer15 = new Answer("10 + 22", false);
    Answer *answer16 = new Answer("40 + 2", true);
    vector<Answer> answers4 = {*answer13, *answer14, *answer15, *answer16};
    question4->setAnswers(answers4);
    question4->setManyAnswers(2);

    Question *question5 = new Question();
    question5->setQuestionText("10 + 10 = ?");
    Answer *answer17 = new Answer("20", true);
    Answer *answer18 = new Answer("30", false);
    Answer *answer19 = new Answer("10", false);
    Answer *answer20 = new Answer("0", false);
    vector<Answer> answers5 = {*answer17, *answer18, *answer19, *answer20};
    question5->setAnswers(answers5);
    question5->setManyAnswers(1);

    Test *test1 = new Test();
    vector<Question> questions = {*question1, *question2, *question3, *question4, *question5};
    test1->setQuestions(questions);
    test1->setTitle("Some simple math");

    listOfTests = {*test1};

}

Test InMemoryDatabase::getTest(int index) {
    return listOfTests[index];
}

void InMemoryDatabase::setListOfTests(vector<Test> list) {
    listOfTests = list;
}

vector<Test> InMemoryDatabase::getListOfTests() {
    return listOfTests;
}
