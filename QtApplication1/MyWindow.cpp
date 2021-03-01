#include "MyWindow.h"
#include "closeEvent.h"
#include "MyAction.h"
#include <QList>
#include <QtWidgets>
#include <QSplitter>
#include <QListWidget>
#include <QAction>
#include <QObject>
#include <QMetaObject>
#include <iostream>
#include <QCloseEvent>

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
	copyItemLeft = new QListWidgetItem;
	cutItemLeft = new QListWidgetItem;
	pasteItemLeft = new QListWidgetItem;
	deleteItemLeft = new QListWidgetItem;

	//layouts
	leftWgtLayout = new QVBoxLayout(this);
	menuWgtLayout = new QHBoxLayout(this);
	moreLayout = new QVBoxLayout(this);

	//Widgets
	listingLeft = new QListWidget(this);
	leftWgt = new QWidget(this);
	menuWgt = new QWidget(this);
	moreWgt = new QWidget(this);

	//setting texts for left menu
	copyItemLeft->setText(QStringLiteral("Копировать"));
	cutItemLeft->setText(QStringLiteral("Вырезать"));
	pasteItemLeft->setText(QStringLiteral("Вставить"));
	deleteItemLeft->setText(QStringLiteral("Удалить"));

	//all pos checked
	copyItemLeft->setCheckState(Qt::Checked);
	cutItemLeft->setCheckState(Qt::Checked);
	pasteItemLeft->setCheckState(Qt::Checked);
	deleteItemLeft->setCheckState(Qt::Checked);

	//inserting all items into left list
	listingLeft->insertItem(1, copyItemLeft);
	listingLeft->insertItem(2, cutItemLeft);
	listingLeft->insertItem(3, pasteItemLeft);
	listingLeft->insertItem(4, deleteItemLeft);
	
	//positioning on left layer
	leftWgtLayout->addWidget(listingLeft);
	leftWgtLayout->addWidget(up);
	leftWgtLayout->addWidget(down);
	leftWgt->setLayout(leftWgtLayout);

	//positioning on menu layer
	menuWgtLayout->addWidget(menu);
	menuWgtLayout->addWidget(moremenu);
	menuWgt->setLayout(menuWgtLayout);

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
	
	connect(listingLeft, SIGNAL(itemChanged(QListWidgetItem*)), SLOT(cutVision(QListWidgetItem*)));//changing moremenu 
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
	splitter->setWindowTitle(QStringLiteral("\t \t \t \t Меню"));
	menuWgt->setStyleSheet("QMenu::item:NoUpdate { background-color: white; color: #005eff; }");//white font blue text
	splitter->show();
}
void QWidget::closeEvent(QCloseEvent* event)
{
		event->ignore();
}

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

void MyWindow::buttonPosUp()
{
	int currentRowUp = listingLeft->QListWidget::currentRow();
	if (currentRowUp > 0) 
	{
		QListWidgetItem tmp = *(listingLeft->currentItem());
		int upRow = currentRowUp - 1;

		*(listingLeft->item(currentRowUp)) = *(listingLeft->item(upRow));
		*(listingLeft->item(upRow)) = tmp;
	
		listingLeft->insertItem(currentRowUp, listingLeft->item(upRow));
		listingLeft->setCurrentItem(listingLeft->item(upRow));
	}
}

void MyWindow::buttonPosDown()
{
	int currentRowDown = listingLeft->QListWidget::currentRow();
	if (currentRowDown < 4)
	{
		QListWidgetItem tmp_2 = *(listingLeft->currentItem());
		int downRow = currentRowDown + 1;

		*(listingLeft->item(currentRowDown)) = *(listingLeft->item(downRow));
		*(listingLeft->item(downRow)) = tmp_2;

		listingLeft->insertItem(currentRowDown, listingLeft->item(downRow));
		listingLeft->setCurrentItem(listingLeft->item(downRow));
	}
	
}


//destructor
MyWindow::~MyWindow() {}
//closeEvent::~closeEvent() {}