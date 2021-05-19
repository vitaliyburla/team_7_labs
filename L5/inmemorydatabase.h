#ifndef INMEMORYDATABASE_H
#define INMEMORYDATABASE_H

#include <iostream>
#include <vector>
#include <test.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class InMemoryDatabase
{
public:
    InMemoryDatabase();
    InMemoryDatabase(string path);

    QSqlDatabase db;

    void setDBfromFile(string path);

    void setListOfTests(vector<Test> list);
    //vector<Test> getListOfTests();
    //vector<Test> getTestFromFile(string filename);
    vector<Test> getTestFromDatabase(int id);
    void addNewResult(double mark);

    Test getTest(int index);

private:
    vector<Test> listOfTests;

};

#endif // INMEMORYDATABASE_H
