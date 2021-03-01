#include <QtWidgets/QApplication>
#include <QListWidget>
#include <QCheckBox>
#include <QAction>
#include <QMenuBar>
#include <QObject>
#include "MyWindow.h"
#include "MyAction.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    std::unique_ptr<MyWindow> window( new MyWindow());
   // window->show();
    return app.exec();
}
