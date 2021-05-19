#include "testswindow.h"
#include "inmemorydatabase.h"
#include <QLayout>
#include <QString>
#include <QFileDialog>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InMemoryDatabase *imd = new InMemoryDatabase();
    QString path = QFileDialog::getOpenFileName(nullptr, "Opne Text File with questions",
                                                "C:/Users/Admin/Documents/Study/SP/build-L4-Desktop_Qt_5_12_10_MinGW_64_bit-Debug",
                                                "Text files(*.txt);;All files(*.*)");
    //vector<Test> tests = imd->getTestFromFile("quest.txt");
    vector<Test> tests = imd->getTestFromPath(path);
    Test t = imd->getTest(0);
    TestsWindow *w = new TestsWindow(t);
    w->show();
    return a.exec();
}
