#ifndef INMEMORYDATABASE_H
#define INMEMORYDATABASE_H

#include <iostream>
#include <vector>
#include <test.h>

class InMemoryDatabase
{
public:
    InMemoryDatabase();
    void setListOfTests(vector<Test> list);
    vector<Test> getListOfTests();
    Test getTest(int index);

private:
    vector<Test> listOfTests;

};

#endif // INMEMORYDATABASE_H
