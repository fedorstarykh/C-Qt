#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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

class MainWindow : public QDialog
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();

	void setLeftItem(int leftitemid, QString leftitemname);
	QString getLeftItemName();

	int getLeftItemId();
private:
	//splitter as main frame
	QSplitter* splitter;

	//left layer
	QListWidgetItem* leftItem;
	QString leftItemName;
	int leftItemId;

	//wdgts
	QListWidget* listingLeft;
	QWidget* leftWgt;
	QWidget* menuWgt;
	//menu for right part
	QMenu* menu;
	QMenu* moreMenu;
	//buttons
	QPushButton* upBtn;
	QPushButton* downBtn;
	//Layouts
	QVBoxLayout* leftWgtLayout;
	QHBoxLayout* menuWgtLayout;
	//string
	QString* sRight;
	QString* sUp;
	QString* sDown;
private slots:
};

#endif