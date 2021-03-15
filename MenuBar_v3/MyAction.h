#ifndef MYACTION_H
#define MYACTION_H
#include <QAction>
#include <iostream>
using namespace std;
//class MainWindow;
class MyAction : public QAction, public MainWindow
{
	Q_OBJECT
public:
	//friend MainWindow;

	MyAction(int menuactid, QString menuactname, QString menuacttext = "unsigned");
	~MyAction();
	int getMenuActId();
	QString getMenuActName();
protected:
	QAction* menuAct;
	QAction* moreAct;
	int menuActId;
	int moreActId;
	QString menuActName;
	//menu for right part
	QMenu* menu;
	QMenu* moreMenu;
private:

};

#endif