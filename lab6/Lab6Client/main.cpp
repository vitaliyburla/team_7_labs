#include "testswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestsWindow *w = new TestsWindow();
    w->show();

    return a.exec();
}
