#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QDialog>
#include <QPushButton>
#include <QWidget>
#include <QListWidgetItem>
#include <QSplitter>
class MyWindow : public QDialog
{
	Q_OBJECT

public:
	MyWindow(QWidget *parent = 0);
	virtual ~MyWindow();
	QSplitter* splitter;
private:
	//left layer
	
	QMenu* menu;
	QListWidgetItem* copyitem_left;
	QListWidgetItem* cutitem_left;
	QListWidgetItem* pasteitem_left;
	QListWidgetItem* deleteitem_left;
	QListWidgetItem* more_item_left;
	//mid layer
	QListWidgetItem* copyitem;
	QListWidgetItem* cutitem;
	QListWidgetItem* pasteitem;
	QListWidgetItem* deleteitem;
	QListWidgetItem* more_item;
	//buttons
	QPushButton* up;
	QPushButton* down; 
//private slots:
//	void UpClicked();
//	void DownClicked();
};

#endif