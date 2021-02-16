#include "MyWindow.h"
#include "sigsnslots.h"
#include <QtWidgets>
#include <QSplitter>
#include <QListWidget>
#include <QAction>
#include <QObject>
#include <QMetaObject>

MyWindow::MyWindow(QWidget* parent) : QDialog(parent)
{
	up = new QPushButton("Move up");
	down = new QPushButton("Move down");

	//
	//QHBoxLayout* layout = new QHBoxLayout;
	//layout->addWidget(up);//кнопки 	
	//layout->addWidget(down);
	menu = new QMenu;

	//for left layer
	copyitem_left = new QListWidgetItem;
	cutitem_left = new QListWidgetItem;
	pasteitem_left = new QListWidgetItem;
	deleteitem_left = new QListWidgetItem;
	more_item_left = new QListWidgetItem;

	copyitem = new QListWidgetItem;
	cutitem = new QListWidgetItem;
	pasteitem = new QListWidgetItem;
	deleteitem = new QListWidgetItem;
	more_item = new QListWidgetItem;

	//left layer
	QVBoxLayout* left = new QVBoxLayout;
	QListWidget* listing_left = new QListWidget(this);

	copyitem_left->setText("Copy");
	cutitem_left->setText("Cut");
	pasteitem_left->setText("Paste");
	deleteitem_left->setText("Delete");
	more_item_left->setText("More");

	bool i = true;
	copyitem_left->setCheckState(Qt::Checked);
	cutitem_left->setCheckState(Qt::Checked);
	pasteitem_left->setCheckState(Qt::Checked);
	deleteitem_left->setCheckState(Qt::Checked);
	more_item_left->setCheckState(Qt::Checked);


	listing_left->insertItem(1, copyitem_left);
	listing_left->insertItem(2, cutitem_left);
	listing_left->insertItem(3, pasteitem_left);
	listing_left->insertItem(4, deleteitem_left);
	listing_left->insertItem(5, more_item_left);

	listing_left->resize(100, 100);

	//left->addLayout(layout);

	//middle layer
	QVBoxLayout* mid = new QVBoxLayout;
	QListWidget* listing_mid = new QListWidget(this);
	QListWidgetItem* copyitem = new QListWidgetItem;
	QListWidgetItem* cutitem = new QListWidgetItem;
	QListWidgetItem* pasteitem = new QListWidgetItem;
	QListWidgetItem* deleteitem = new QListWidgetItem;
	QListWidgetItem* more_item = new QListWidgetItem;

	copyitem->setText("Copy");
	cutitem->setText("Cut");
	pasteitem->setText("Paste");
	deleteitem->setText("Delete");
	more_item->setText("More");

	listing_mid->insertItem(1, copyitem);
	listing_mid->insertItem(2, cutitem);
	listing_mid->insertItem(3, pasteitem);
	listing_mid->insertItem(4, deleteitem);
	listing_mid->insertItem(5, more_item);
	listing_mid->resize(100, 100);
	//spisok->itemChanged (QListWidgetItem *copy);
	//cutitem->setHidden(true); //скрыть элемент

	mid->addWidget(listing_mid);

	//right layer
	QVBoxLayout* right = new QVBoxLayout;
	QListWidget* listing_right = new QListWidget;
	listing_right->addItem("Copy");
	listing_right->addItem("Cut");
	listing_right->addItem("Paste");
	listing_right->addItem("Delete");

	right->addWidget(listing_right);
	listing_right->resize(10, 4);

	//main layer
	//QHBoxLayout* main = new QHBoxLayout;
	//main->addLayout(left);
	//main->addLayout(mid);	
	//main->addLayout(right);

	QWidget* leftWgt = new QWidget(this);
	QVBoxLayout* leftWgt_layout = new QVBoxLayout;
	leftWgt_layout->addWidget(listing_left);
	leftWgt_layout->addWidget(up);
	leftWgt_layout->addWidget(down);
	leftWgt->setLayout(leftWgt_layout);

	QWidget* menuWgt = new QWidget(this);	
	QVBoxLayout* menuWgt_layout = new QVBoxLayout;

	QAction* pactCopy = new QAction("file copy action");
	pactCopy->setText("&Copy");
	menu->addAction(pactCopy);

	QAction* pactCut = new QAction("s");
	pactCut->setText("&Cut");
	pactCut->setDisabled(false);
	menu->addAction(pactCut);
	connect(pactCopy, SIGNAL(clicked(true)), pactCut, SLOT(delete()));
	menu->addAction("Paste");
	menu->addAction("Delete");
	
	menuWgt_layout->addWidget(menu);
	menuWgt->setLayout(menuWgt_layout);
	menuWgt->setStyleSheet("QLineEdit { background-color: yellow }");

	QPalette pal(palette());
	pal.setColor(QPalette::Base, Qt::green);
	setAutoFillBackground(true);
	setPalette(pal);
	//menuWgt->setStyleSheet("color: #FF0000;");//red text
	splitter = new QSplitter(Qt::Horizontal);
	//leftWgt->setPalette(pal);
	splitter->addWidget(leftWgt);
	menuWgt->setPalette(pal);
	splitter->addWidget(menuWgt);
	//splitter->addWidget(listing_mid);
	//splitter->addWidget(listing_right);
	splitter->resize(500, 500);
	splitter->setWindowTitle("MENU");
	//splitter->setStyleSheet("QMenu::item:NoUpdate { background-color: white; }");//permanently white
	splitter->show();
	//setLayout(main);
	
}
//destructor
MyWindow::~MyWindow() 
{

}