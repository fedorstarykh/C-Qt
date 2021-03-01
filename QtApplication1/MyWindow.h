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

private:
	//splitter as main frame
	QSplitter* splitter;
	//left layer
	QListWidgetItem* copyItemLeft;
	QListWidgetItem* cutItemLeft;
	QListWidgetItem* pasteItemLeft;
	QListWidgetItem* deleteItemLeft;
	//wdgts
	QListWidget* listingLeft;
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
	QVBoxLayout* leftWgtLayout;
	QHBoxLayout* menuWgtLayout;
	QVBoxLayout* moreLayout;
public:
	MyWindow(QWidget* parent = 0);
	virtual ~MyWindow();

private slots:
	void cutVision(QListWidgetItem *item);
	void buttonPosUp();
	void buttonPosDown();
//signals:
};

#endif