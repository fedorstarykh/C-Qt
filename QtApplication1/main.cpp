//#include "Test1.h"
#include <QtWidgets/QApplication>
#include <QtGui>
#include <QPushButton>
#include <QBoxLayout>
#include <QSplitter>
#include <QTextEdit>
#include <QListWidget>
#include <QList>
#include <QCheckBox>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QObject>
//#include "main.h"
#include "MyWindow.h"
#include "sigsnslots.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

  //  QObject::connect(MyWindow::up, SIGNAL(cliced(), &app, SLOT(quit())));

    std::unique_ptr<MyWindow> window( new MyWindow());
    window->show();
    return app.exec();
}