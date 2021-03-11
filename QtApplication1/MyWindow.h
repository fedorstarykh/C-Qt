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
#include <QSettings>
class MyAction;
class MyWindow : public QDialog
{
	Q_OBJECT
		friend MyAction;

public:
	MyWindow(QWidget* parent = 0, QString name = QStringLiteral("Μενώ"));
	virtual ~MyWindow();
	//funcs for process latest process saving/loading
	void loadSettings();
	void saveSettings();
	
private:
	QSettings* settings;
	//splitter as main frame
	QSplitter* splitter;
	//left layer
	QListWidgetItem* copyItemLeft;
	QListWidgetItem* cutItemLeft;
	QListWidgetItem* pasteItemLeft;
	QListWidgetItem* deleteItemLeft;
	//wdgts
	QListWidget* listingLeft;
	QWidget*	 leftWgt;
	QWidget*	 menuWgt;
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
	//string
	QString*	 sRight;
	QString*	 sUp;
	QString*	 sDown;
	bool repeatable = false;
	
private slots:
	void cutVision(QListWidgetItem *item);
	void buttonPosUp();
	void buttonPosDown();
	void moreShowList();

};

#endif