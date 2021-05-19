#ifndef INMEMORYDATABASE_H
#define INMEMORYDATABASE_H

#include <iostream>
#include <vector>
#include <test.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtNetwork>

class InMemoryDatabase
{
public:
    InMemoryDatabase();
    InMemoryDatabase(string path);

    QSqlDatabase db;

    void setDBfromFile(string path);

    void setListOfTests(vector<Test> list);
    void setListOfTests();
    //vector<Test> getTestFromFile(string filename);
    Test getTestFromDatabase(int id);

    void addNewResult(double mark);

    Test getTest(int index);

private:
    vector<Test> listOfTests;

};

#endif // INMEMORYDATABASE_H
