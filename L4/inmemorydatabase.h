#ifndef INMEMORYDATABASE_H
#define INMEMORYDATABASE_H

#include <iostream>
#include <vector>
#include <test.h>
#include <QString>

class InMemoryDatabase
{
public:
    InMemoryDatabase();

    void setListOfTests(vector<Test> list);
    vector<Test> getListOfTests();
    vector<Test> getTestFromFile(string filename);
    vector<Test> getTestFromPath(QString path);

    Test getTest(int index);

private:
    vector<Test> listOfTests;

};

#endif // INMEMORYDATABASE_H
