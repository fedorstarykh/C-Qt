//#include "Test1.h"
#include <QtWidgets/QApplication>
#include <QListWidget>
#include <QCheckBox>
#include <QAction>
#include <QMenuBar>
#include <QObject>
//#include "main.h"
#include "MyWindow.h"
#include "sigsnslots.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    std::unique_ptr<MyWindow> window( new MyWindow());
 
    //window->show();
    return app.exec();
}