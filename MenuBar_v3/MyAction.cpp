#include <iostream>
#include <QtWidgets/QApplication>
#include "MyAction.h"

using namespace std;
MyAction::MyAction(int menuactid, QString menuactname, QString menuacttext)
{
	menuActId = menuactid;
	menuActName = menuactname;
	//menuAct->setText(menuacttext);
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
