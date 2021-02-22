#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QDialog>
#include <QPushButton>
#include <QWidget>
#include <QListWidgetItem>
#include <QSplitter>
#include <QBoxLayout>

class MyWindow : public QDialog
{
	Q_OBJECT

public:
	MyWindow(QWidget *parent = 0);
	virtual ~MyWindow();
	//splitter as main frame
	QSplitter* splitter;
	//left layer
	QListWidgetItem* copyitem_left;
	QListWidgetItem* cutitem_left;
	QListWidgetItem* pasteitem_left;
	QListWidgetItem* deleteitem_left;
	QListWidgetItem* more_item_left;
private:
	//menu for right part
	QMenu* menu;

	//buttons
	QPushButton* up;
	QPushButton* down; 
	//Actions(in menu)
	QAction* pactCopy;
	QAction* pactCut;
	QAction* pactPaste;
	QAction* pactDelete;
	QAction* pactMore;
	//Layouts
	QVBoxLayout* leftWgt_layout;
	QVBoxLayout* menuWgt_layout;

private slots:
	void cutVision();
//	void slotCut();
};
//void MyWindow::copyClicked(){ exit(0); }
#endif