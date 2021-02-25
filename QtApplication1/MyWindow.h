#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QDialog>
#include <QPushButton>
#include <QWidget>
#include <QListWidgetItem>
#include <QSplitter>
#include <QBoxLayout>
#include <QList>
#include <QMenu>
#include <QMenuBar>
#include <QTableWidget>
#include <QListWidget>

class MyWindow : public QDialog
{
	Q_OBJECT

public:
	MyWindow(QWidget *parent = 0);
	virtual ~MyWindow();

private:
	//splitter as main frame
	QSplitter* splitter;
	//left layer
	QListWidgetItem* copyitem_left;
	QListWidgetItem* cutitem_left;
	QListWidgetItem* pasteitem_left;
	QListWidgetItem* deleteitem_left;
	QListWidgetItem* more_item_left;
	//wdgts
	QListWidget* listing_left;
	QWidget* leftWgt;
	QWidget* menuWgt;
	QWidget* moreWgt;
	//menu for right part
	QMenu* menu;
	QMenu* moremenu;
	//buttons
	QPushButton* up;
	QPushButton* down; 
	//Actions(in menu)
	QAction* pactCopy;
	QAction* pactCut;
	QAction* pactPaste;
	QAction* pactDelete;
	QAction* pactMore;
	//Actions(moremenu)
	QAction* moreCopy;
	QAction* moreCut;
	QAction* morePaste;
	QAction* moreDelete;

	//Layouts
	QVBoxLayout* leftWgt_layout;
	QHBoxLayout* menuWgt_layout;
	QVBoxLayout* more_layout;
	//changing true - false
	
private slots:
	void cutVision(QListWidgetItem *item);
	void buttonPosUp();
	void buttonPosDown();
//signals:
};

#endif