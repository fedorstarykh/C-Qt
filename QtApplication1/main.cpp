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
//#include "main.h"
#include "MyWindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
   
    std::unique_ptr<MyWindow> window( new MyWindow());
    window->show();
    return app.exec();
}