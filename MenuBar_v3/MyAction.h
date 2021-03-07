#ifndef MYACTION_H
#define MYACTION_H
#include <QAction>
#include <iostream>
using namespace std;

class MyAction : public QAction
{
	Q_OBJECT

public:
	MyAction(int menuactid, QString menuactname, QString menuacttext = "unsigned");
	~MyAction();
	int getMenuActId();
	QString getMenuActName();
private:
	QAction* menuAct;
	QAction* moreAct;
	int menuActId;
	int moreActId;
	QString menuActName;
};

#endif