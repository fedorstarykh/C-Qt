#include <iostream>
#include <QtWidgets/QApplication>
#include <QMenu>
#include "MyAction.h"

using namespace std;
MyAction::MyAction(int menuactid, QString menuactname, QString menuacttext)
{	
	menu = new QMenu;
	menuAct = new QAction(this);
	menuActId = menuactid;
	menuActName = menuactname;
	menuAct->setText(menuacttext);
	menu->addAction(menuAct);
}


int MyAction::getMenuActId()
{
	return menuActId;
}

QString MyAction::getMenuActName()
{
	return menuActName;
}

MyAction::~MyAction()
{
}
