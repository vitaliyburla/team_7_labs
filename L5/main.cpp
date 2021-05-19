#include "testswindow.h"
#include "inmemorydatabase.h"
#include <QLayout>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InMemoryDatabase *imd = new InMemoryDatabase();
    vector<Test> tests = imd->getTestFromDatabase(1);
    Test t = imd->getTest(0);
    TestsWindow *w = new TestsWindow(t);
    w->show();

    return a.exec();
}
