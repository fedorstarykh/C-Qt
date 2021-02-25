#include "Test1.h"
#include <QtWidgets/QApplication>
#include <QtGui>
#include "label.h"
#include <QPushButton>
#include <QBoxLayout>
#include <QSplitter>
#include <QTextEdit>
#include <QListWidget>
#include <QCheckBox>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include "main.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QMenuBar mnuBar;
    QWidget wgt; // пока не соединено с выводом

    QMenu* pcopy = new QMenu("&Copy ");
    QMenu* pcut = new QMenu("&Cut ");
    QMenu* ppaste = new QMenu("&Paste");
    QMenu* pdelete = new QMenu("&Delete ");
    QMenu* pmore = new QMenu("&More");
  
    QBoxLayout* pvbxLayout = new QVBoxLayout();
   
    //pmore->addSeparator();

    QAction* pCheckableAction = pmore->addAction("&Copy");

    pCheckableAction->setCheckable(true);
    pCheckableAction->setChecked(true);
    pmore->addSeparator();
    QAction* pCheckableAction_2 = pmore->addAction("&Cut");
    pCheckableAction_2->setCheckable(true);
    pCheckableAction_2->setChecked(true);
    pmore->addSeparator();
    QAction* pCheckableAction_3 = pmore->addAction("&Paste");
    pCheckableAction_3->setCheckable(true);
    pCheckableAction_3->setChecked(true);
    pmore->addSeparator();
    QAction* pCheckableAction_4 = pmore->addAction("&Delete");
    pCheckableAction_4->setCheckable(true);
    pCheckableAction_4->setChecked(true);

    pmore->addSeparator();

    QMenu* pmore_extendedmenu = new QMenu("&More than more", pmore);
    pmore->addMenu(pmore_extendedmenu);
    pmore_extendedmenu->addAction("&Exit", &app, &QApplication::quit);
    pmore_extendedmenu->addAction("&One more exit", &app, &QApplication::quit);
   // QMenu pmoreextendedmenu.resize(300, 100);

    QPushButton* pcmd_Upper_Pos = new QPushButton("Upper"); // тоже пока не используется
    QPushButton* pcmd_Lower_Pos = new QPushButton("Lower");

   
    pvbxLayout->addWidget(pcmd_Upper_Pos);
    pvbxLayout->addWidget(pcmd_Lower_Pos);
    pvbxLayout->addWidget(pmore);

   // mnuBar.Orientation::horizontal;
    mnuBar.setWindowTitle("Main Menu");
    mnuBar.addMenu(pcopy);
    mnuBar.addMenu(pcut);
    mnuBar.addMenu(ppaste);
    mnuBar.addMenu(pdelete);
    //mnuBar.addMenu(pmore);
  //  mnuBar.addWidget(pvbxLayout);
    mnuBar.resize(300, 150);
   // mnuBar.show();
    //wgt.resize(260, 70);

    wgt.setLayout(pvbxLayout);
    wgt.show();

    return app.exec();
}