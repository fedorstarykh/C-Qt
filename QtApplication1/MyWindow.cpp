#include "MyWindow.h"
#include "sigsnslots.h"
#include <QtWidgets>
#include <QSplitter>
#include <QListWidget>
#include <QAction>
#include <QObject>
#include <QMetaObject>
#include <iostream>

MyWindow::MyWindow(QWidget* parent) : QDialog(parent)
{
	//buttons for left part
	up = new QPushButton("Move up");
	down = new QPushButton("Move down");
	//menu
	menu = new QMenu;

	//for left layer
	copyitem_left = new QListWidgetItem;
	cutitem_left = new QListWidgetItem;
	pasteitem_left = new QListWidgetItem;
	deleteitem_left = new QListWidgetItem;
	more_item_left = new QListWidgetItem;
	
	//layouts
	leftWgt_layout = new QVBoxLayout;
	menuWgt_layout = new QVBoxLayout;

	QListWidget* listing_left = new QListWidget(this);
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

	//cutitem->setHidden(true);//������ �������

	//positioning on left layer
	QWidget* leftWgt = new QWidget(this);
	
	leftWgt_layout->addWidget(listing_left);
	leftWgt_layout->addWidget(up);
	leftWgt_layout->addWidget(down);
	leftWgt->setLayout(leftWgt_layout);

	QWidget* menuWgt = new QWidget(this);	
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

	//pactCopy->setVisible(true);
	//all actions including into menu
	menu->addAction(pactCopy);
	menu->addAction(pactCut);
	menu->addAction(pactPaste);
	menu->addAction(pactDelete);
	menu->addAction(pactMore);

	connect(pactMore, &QAction::triggered, qApp, QApplication::quit);//�������� ��������� ��� ����� ������ copy

	connect(pactCut, SIGNAL(triggered()), SLOT(cutVision()));
	connect(cutitem_left, SIGNAL(changed(), SLOT(cutVision())));

	menuWgt_layout->addWidget(menu);
	menuWgt->setLayout(menuWgt_layout);

	leftWgt->setStyleSheet("color: #005eff;");//blue text

	splitter = new QSplitter(Qt::Horizontal);
	splitter->addWidget(leftWgt);
	splitter->addWidget(menuWgt);

	//splitter->resize(500, 500);
	splitter->setWindowTitle("MENU");
	menuWgt->setStyleSheet("QMenu::item:NoUpdate { background-color: white; color: #005eff; }");//white font blue text
	splitter->show();
	
}
//�������� ����������
bool cut_tf_value = true;
//�������� ���� ��� ������ ���
void MyWindow::cutVision()
{	
	//pactCut->setVisible(false);//hide cut on right menu
	cutitem_left->setHidden(cut_tf_value);//hide cut on left menu
	//����������� ������ � �������� ������ �� ����� Cut
	if (cut_tf_value == true)
		cut_tf_value = false;
	else
		cut_tf_value = true;
}

//destructor
MyWindow::~MyWindow() 
{

}