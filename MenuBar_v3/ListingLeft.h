#ifndef LISTINGLEFT_H
#define LISTINGLEFT_H
#include <QPushButton>
#include <QWidget>
#include <QListWidgetItem>
#include <QSplitter>
#include <QBoxLayout>
#include <QList>
#include <QMenu>
#include <QDialog>
#include <QMenuBar>
#include <QTableWidget>
#include <QListWidget>

class MyAction;
class ListingLeft 
{
	Q_OBJECT
public:
	
	//ListingLeft();
	~ListingLeft();

	ListingLeft(int leftitemid, QString leftitemname);
	QString getLeftItemName();

	int getLeftItemId();
private:
	//left layer
	QListWidgetItem* leftItem;
	QString leftItemName;
	int leftItemId;

	////wdgts
	//QListWidget* listingLeft;
	//QWidget* leftWgt;

};

#endif
