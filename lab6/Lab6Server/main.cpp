#include "serverwindow.h"
#include "inmemorydatabase.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //InMemoryDatabase *db = new InMemoryDatabase();
    //Test test = db->getTestFromDatabase(1);
    //cout << test.getTitle() << endl;
    ServerWindow *w = new ServerWindow();
    w->show();

    return a.exec();
}
