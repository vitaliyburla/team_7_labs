#include "serverwindow.h"
#include <QMessageBox>
#include <QLayout>

ServerWindow::ServerWindow(QWidget *parent)
: QMainWindow(parent)
, m_testServer(new TestServer(this)){
    setWindowTitle("Server App");
    setGeometry(100, 100, 400, 400);
    setMinimumSize(400, 400);

    logs = new QTextEdit();
    logs->setText("");
    logs->setGeometry(10, 40, 200, 200);

    toggle = new QPushButton();
    toggle->setText("Start server");
    toggle->setGeometry(10, 20, 200, 80);

    QWidget *central = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(toggle);
    layout->addWidget(logs);

    layout->addStretch(1);
    central->setLayout(layout);
    setCentralWidget(central);

    QObject::connect(toggle, SIGNAL (clicked()), this, SLOT (toggleStartServer()));
    connect(m_testServer, &TestServer::logMessage, this, &ServerWindow::logMessage);
}
ServerWindow::~ServerWindow() {
}

void ServerWindow::toggleStartServer() {
    if (m_testServer->isListening()) {
        m_testServer->stopServer();
        logMessage(QStringLiteral("Server stopped"));
        toggle->setText("Start server");
    } else {
        if (!m_testServer->listen(QHostAddress::Any, 1967)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to start server"));
            return;
        }
        logMessage(QStringLiteral("Server started"));
        toggle->setText("Stop server");
    }
}

void ServerWindow::logMessage(const QString &msg) {
    logs->append(msg);
}
