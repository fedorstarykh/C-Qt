#include "MyWindow.h"
#include "sigsnslots.h"
#include"closeEvent.h"
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
	std::wstring strUp = L"\u25b2";//arrow up
	QString sUp = QString::fromStdWString(strUp);
	std::wstring strdown = L"\u25bc";//arrow down
	QString sDown = QString::fromStdWString(strdown);
	up = new QPushButton(sUp);
	down = new QPushButton(sDown);
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
	leftWgt_layout = new QVBoxLayout(this);
	menuWgt_layout = new QHBoxLayout(this);
	more_layout = new QVBoxLayout(this);
	//Widgets
	listing_left = new QListWidget(this);
	leftWgt = new QWidget(this);
	menuWgt = new QWidget(this);
	moreWgt = new QWidget(this);

	//setting texts for left menu
	copyitem_left->setText(QStringLiteral("Копировать"));
	cutitem_left->setText(QStringLiteral("Вырезать"));
	pasteitem_left->setText(QStringLiteral("Вставить"));
	deleteitem_left->setText(QStringLiteral("Удалить"));
	more_item_left->setText(QStringLiteral("Ещё"));
	//all pos checked
	copyitem_left->setCheckState(Qt::Checked);
	cutitem_left->setCheckState(Qt::Checked);
	pasteitem_left->setCheckState(Qt::Checked);
	deleteitem_left->setCheckState(Qt::Checked);
	//inserting all items into left list
	listing_left->insertItem(1, copyitem_left);
	listing_left->insertItem(2, cutitem_left);
	listing_left->insertItem(3, pasteitem_left);
	listing_left->insertItem(4, deleteitem_left);
	listing_left->insertItem(5, more_item_left);
	
	//positioning on left layer
	leftWgt_layout->addWidget(listing_left);
	leftWgt_layout->addWidget(up);
	leftWgt_layout->addWidget(down);
	leftWgt->setLayout(leftWgt_layout);
	//positioning on menu layer
	menuWgt_layout->addWidget(menu);
	menuWgt_layout->addWidget(moremenu);
	menuWgt->setLayout(menuWgt_layout);
	//menuWgt->setWindowFlags(Qt::Tool);
	//menuWgt->setStyleSheet(QFrame::Panel);

	//objecting actions
	pactCopy = new QAction(this);
	pactCut = new QAction(this);
	pactPaste = new QAction(this);
	pactDelete = new QAction(this);
	pactMore = new QAction(this);
	
	//naming menu points on right part
	pactCopy->setText(QStringLiteral("Копировать"));
	pactCut->setText(QStringLiteral("Вырезать"));
	pactPaste->setText(QStringLiteral("Вставить"));
	pactDelete->setText(QStringLiteral("Удалить"));
	std::wstring str = L"\u276F";//arrow right
	QString sRight = QString::fromStdWString(str);
	pactMore->setText(QStringLiteral("Ещё  ") + sRight);

	//all actions including into menu
	menu->addAction(pactCopy);
	menu->addSeparator();
	menu->addAction(pactCut);
	menu->addSeparator();
	menu->addAction(pactPaste);
	menu->addSeparator();
	menu->addAction(pactDelete);
	menu->addSeparator();
	menu->addAction(pactMore);

	moreCopy = new QAction(this);
	moreCopy->setText(QStringLiteral("Копировать"));
	moremenu->addAction(moreCopy);
	moreCopy->setVisible(false);

	moreCut = new QAction(this);
	moreCut->setText(QStringLiteral("Вырезать"));
	moremenu->addAction(moreCut);
	moreCut->setVisible(false);

	morePaste = new QAction(this);
	morePaste->setText(QStringLiteral("Вставить"));
	moremenu->addAction(morePaste);
	morePaste->setVisible(false);

	moreDelete = new QAction(this);
	moreDelete->setText(QStringLiteral("Удалить"));
	moremenu->addAction(moreDelete);
	moreDelete->setVisible(false);
	
	connect(listing_left, SIGNAL(itemChanged(QListWidgetItem*)), SLOT(cutVision(QListWidgetItem*)));//changing moremenu 
	connect(up, SIGNAL(clicked()), SLOT(buttonPosUp()));//moving up
	connect(down, SIGNAL(clicked()), SLOT(buttonPosDown()));//moving down
	//min sizes
	leftWgt->setFixedSize(QSize(150, 300));
	menuWgt->setFixedSize(QSize(250, 300));
	leftWgt->setStyleSheet("color: #005eff;");//blue text
	splitter = new QSplitter(Qt::Horizontal);
	splitter->addWidget(leftWgt);
	splitter->addWidget(menuWgt);

	//turning off collapsability for left and right part
	splitter->setCollapsible(0, false);
	splitter->setCollapsible(1, false);
	splitter->setCollapsible(2, false);
	splitter->setCollapsible(3, false);
	//styling
	splitter->resize(700, 700);
	splitter->setWindowTitle(QStringLiteral("                                   Меню"));
	menuWgt->setStyleSheet("QMenu::item:NoUpdate { background-color: white; color: #005eff; }");//white font blue text
	splitter->show();
}

//closeEvent::closeEvent(QCloseEvent* event)
//{
//		event->ignore();
//}
void MyWindow::cutVision(QListWidgetItem* item)
{
	
	for (auto actMenu : menu->actions())
	{
		if (actMenu->text().contains(item->text()))
		{
			actMenu->setVisible(item->checkState() == Qt::Checked);
		}
	}
	for (auto actMore : moremenu->actions())
	{
		if (actMore->text().contains(item->text()))
		{
			actMore->setVisible(item->checkState() != Qt::Checked);
		}
	}
}
void MyWindow::buttonPosUp(/*int* row*/)
{
	int currentRowUp = listing_left->QListWidget::currentRow();
	if (currentRowUp > 0) 
	{
		QListWidgetItem tmp = *(listing_left->currentItem());
		int upRow = currentRowUp - 1;

		*(listing_left->item(currentRowUp)) = *(listing_left->item(upRow));
		*(listing_left->item(upRow)) = tmp;
	
		listing_left->insertItem(currentRowUp, listing_left->item(upRow));
		listing_left->setCurrentItem(listing_left->item(upRow));
	}
}

void MyWindow::buttonPosDown()
{
	int currentRowDown = listing_left->QListWidget::currentRow();
	if (currentRowDown < 4)
	{
		QListWidgetItem tmp_2 = *(listing_left->currentItem());
		int downRow = currentRowDown + 1;

		*(listing_left->item(currentRowDown)) = *(listing_left->item(downRow));
		*(listing_left->item(downRow)) = tmp_2;

		listing_left->insertItem(currentRowDown, listing_left->item(downRow));
		listing_left->setCurrentItem(listing_left->item(downRow));
	}
}
//destructor
MyWindow::~MyWindow() {}
//closeEvent::~closeEvent() {}