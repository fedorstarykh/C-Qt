#include "MyWindow.h"
#include "sigsnslots.h"
//#include "sigsnslots.h"
#include <QList>
#include <QtWidgets>
#include <QSplitter>
#include <QListWidget>
#include <QAction>
#include <QObject>
#include <QMetaObject>
#include <iostream>

MyWindow::MyWindow(QWidget* parent) : QDialog(parent)
{
	up = new QPushButton("Move up");
	down = new QPushButton("Move down");
	//menu
	menu = new QMenu;
	moremenu = new QMenu;
	//for left layer
	copyitem_left = new QListWidgetItem;
	cutitem_left = new QListWidgetItem;
	pasteitem_left = new QListWidgetItem;
	deleteitem_left = new QListWidgetItem;
	more_item_left = new QListWidgetItem;
	//layouts
	leftWgt_layout = new QVBoxLayout;
	menuWgt_layout = new QVBoxLayout;
	more_layout = new QVBoxLayout;
	//Widgets
	listing_left = new QListWidget(this);
	leftWgt = new QWidget(this);
	menuWgt = new QWidget(this);
	moreWgt = new QWidget(this);

	//setting texts for left menu
	copyitem_left->setText("Copy");
	cutitem_left->setText("Cut");
	pasteitem_left->setText("Paste");
	deleteitem_left->setText("Delete");
	more_item_left->setText("More");
	//all pos checked
	copyitem_left->setCheckState(Qt::Checked);
	cutitem_left->setCheckState(Qt::Checked);
	pasteitem_left->setCheckState(Qt::Checked);
	deleteitem_left->setCheckState(Qt::Checked);
	more_item_left->setCheckState(Qt::Checked);
	//inserting all items into left list
	listing_left->insertItem(1, copyitem_left);
	listing_left->insertItem(2, cutitem_left);
	listing_left->insertItem(3, pasteitem_left);
	listing_left->insertItem(4, deleteitem_left);
	listing_left->insertItem(5, more_item_left);
	
	//cutitem->setHidden(true);//скрыть элемент
	//positioning on left layer
	
	leftWgt_layout->addWidget(listing_left);
	leftWgt_layout->addWidget(up);
	leftWgt_layout->addWidget(down);
	leftWgt->setLayout(leftWgt_layout);

	//more_layout->addWidget(moreWgt);

	//objecting actions
	pactCopy = new QAction(this);
	pactCut = new QAction(this);
	pactPaste = new QAction(this);
	pactDelete = new QAction(this);
	pactMore = new QAction(this);
	//naming menu points on right part
	pactCopy->setText("&Copy");
	pactCut->setText("&Cut");
	pactPaste->setText("&Paste");
	pactDelete->setText("&Delete");
	pactMore->setText("&More");

	//all actions including into menu
	menu->addAction(pactCopy);
	menu->addAction(pactCut);
	menu->addAction(pactPaste);
	menu->addAction(pactDelete);
	menu->addAction(pactMore);

	//===================submenu filling
	QMenu* submenuMore = menu->addMenu("More");
	submenuMore->addAction(pactCopy);
	submenuMore->addAction(pactCut);
	submenuMore->addAction(pactPaste);
	submenuMore->addAction(pactDelete);
	//===================
	//all actions for moremenu
	moremenu->addAction(pactCopy);
	moremenu->addAction(pactCut);
	moremenu->addAction(pactPaste);
	moremenu->addAction(pactDelete);
	//connection signals and slots
	//QObject::connect(up, SIGNAL(clicked(), &app, SLOT(quit() ))); //не работает почему то
	//connect(pactMore, &QAction::triggered, qApp, QApplication::quit);//закрытие программы при клике кнопки copy
	//connect(pactCut, SIGNAL(triggered()), SLOT(cutVision()));
	//connect(pactMore, SIGNAL(hovered()), SLOT(more_Window()));//for submenu ver1
	//connect(listing_left, &QListWidget::itemChanged(&QListWidgetItem::copyitem_left), SLOT(cutVision()));
	//connect(this, &MyWindow::cutSignal, &MyWindow::cutVision);
	QObject::connect(listing_left, SIGNAL(itemChanged(cutitem_left)), SLOT(cutVision()));
	//connect(listing_left, &QListWidget::itemChanged, /*this,*/ MyWindow::cutVision());

	menuWgt_layout->addWidget(menu);
	more_layout->addWidget(moremenu);
	menuWgt->setLayout(menuWgt_layout);
	//moreWgt->setLayout(more_layout);
	//moreWgt->setVisible(false);
	
	//min sizes
	moreWgt->setMinimumSize(150, 100);
	//leftWgt->setMinimumSize(100, 100);
	menuWgt->setMinimumSize(150, 100);
	leftWgt->setFixedSize(QSize(150, 300));
	//menuWgt->setFixedSize(QSize(150, 300));
	//moreWgt->setFixedSize(QSize(150, 300));

	leftWgt->setStyleSheet("color: #005eff;");//blue text
	splitter = new QSplitter(Qt::Horizontal);
	splitter->addWidget(leftWgt);
	splitter->addWidget(menuWgt);
	splitter->addWidget(moreWgt);
	//splitter->indexOf(leftWgt);

	//turning off collapsability for left and right part
	splitter->setCollapsible(0, false);
	splitter->setCollapsible(1, false);
	splitter->setCollapsible(2, false);
	splitter->setCollapsible(3, false);


	splitter->resize(700, 700);
	splitter->setWindowTitle("MENU");
	menuWgt->setStyleSheet("QMenu::item:NoUpdate { background-color: white; color: #005eff; }");//white font blue text
	splitter->show();
	
}
//тестовый слот для кнопки кат ver_1
//void MyWindow::cutVision()
//{	
//	//pactCut->setVisible(false);//hide cut on right menu
//	cutitem_left->setHidden(cut_tf_value);//hide cut on left menu
//	//возможность скрыть и показать объект по клику Cut
//	if (cut_tf_value == true)
//		cut_tf_value = false;
//	else
//		cut_tf_value = true;
//}

//тестовый слот для кнопки кат ver_2
void MyWindow::cutVision()
{
	pactCut->setVisible(cut_tf_value);//hide cut on right menu
	//cutitem_left->setHidden(cut_tf_value);//hide cut on left menu
	//возможность скрыть и показать объект по клику Cut
	if (cut_tf_value == true)
		cut_tf_value = false;
	else
		cut_tf_value = true;
}
//void MyWindow::cutSignal()
//{
//	listing_left->QListWidget::itemChanged(cutitem_left);
//}
void MyWindow::more_Window()
{
	moreWgt->setVisible(more_tf_value);
	if (more_tf_value == true)
		more_tf_value = false;
	else
		more_tf_value = true;
}
void MyWindow::more_add_del()
{
	//для добавления удаления пунктов в меню в зависимости от левой части
}
//destructor
MyWindow::~MyWindow() 
{

}