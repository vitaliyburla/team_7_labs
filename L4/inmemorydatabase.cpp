#include "inmemorydatabase.h"
#include "question.h"
#include "test.h"
#include <answer.h>
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>

InMemoryDatabase::InMemoryDatabase()
{
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

vector<Test> InMemoryDatabase::getTestFromFile(string filename){
    std::ifstream file;
    file.open(filename);

    Test *test1 = new Test();
    test1->setTitle(filename);

    if(file.is_open()){
        std::string line;
        //std::string text;

        bool quest = true;
        int manyAns = 0;

        std::vector<Answer> answers;
        std::vector<Question> questions;

        Question *question = new Question();

        while (getline(file, line)){
            //text.append(line);
            //text.push_back('\n');
            if (line == "=="){
                question->setAnswers(answers);
                question->setManyAnswers(manyAns);

                questions.push_back(*question);

                manyAns = 0;
                quest = true;
            } else {
                if (quest) {
                    question->setQuestionText(line);

                    answers.clear();
                    quest = false;
                } else {
                    bool a = false;

                    if (line.substr(line.find("=") + 1) == "t") {
                        manyAns++;
                        a = true;}

                    line.pop_back();
                    line.pop_back();

                    Answer *answer = new Answer(line, a);
                    answers.push_back(*answer);
                }
            }
        }
        file.close();
        test1->setQuestions(questions);
        //cout << text << endl;
    }

    setListOfTests({*test1});
    return listOfTests;
}
vector<Test> InMemoryDatabase::getTestFromPath(QString path) {
    QFile file(path);

    Test *test1 = new Test();
    test1->setTitle("Test");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::string line;
        //std::string text;

        bool quest = true;
        int manyAns = 0;

        std::vector<Answer> answers;
        std::vector<Question> questions;

        Question *question = new Question();

        QTextStream in(&file);

        while (!in.atEnd()){
            //text.append(line);
            //text.push_back('\n');
            std::string line = in.readLine().toLocal8Bit().constData();
            if (line == "=="){
                question->setAnswers(answers);
                question->setManyAnswers(manyAns);

                questions.push_back(*question);

                manyAns = 0;
                quest = true;
            } else {
                if (quest) {
                    question->setQuestionText(line);

                    answers.clear();
                    quest = false;
                } else {
                    bool a = false;

                    if (line.substr(line.find("=") + 1) == "t") {
                        manyAns++;
                        a = true;}

                    line.pop_back();
                    line.pop_back();

                    Answer *answer = new Answer(line, a);
                    answers.push_back(*answer);
                }
            }
        }
        file.close();
        test1->setQuestions(questions);
        //cout << text << endl;
    }

    setListOfTests({*test1});
    return listOfTests;
}
