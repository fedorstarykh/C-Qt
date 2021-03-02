#include "MyWindow.h"
#include "closeEvent.h"
#include "menuNoClose.h"
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

//void QWidget::closeEvent(QCloseEvent* event)
//{
//	event->ignore();
//}
MyWindow::MyWindow(QWidget* parent) : QDialog(parent)
{
	std::wstring strUp    = L"\u25b2";//arrow up
	std::wstring strDown  = L"\u25bc";//arrow down
	std::wstring strRight = L"\u276f";//arrow right
	sUp            = new QString;
	sDown          = new QString;
	sRight		   = new QString;
	QString sRight = QString::fromStdWString(strRight);
	QString sUp    = QString::fromStdWString(strUp);
	QString sDown  = QString::fromStdWString(strDown);
	up             = new QPushButton(sUp);
	down           = new QPushButton(sDown);


	//menu
	splitter = new QSplitter(Qt::Horizontal);
	menu     = new QMenu;
	moremenu = new QMenu;

	//for left layer
	copyItemLeft   = new QListWidgetItem;
	cutItemLeft    = new QListWidgetItem;
	pasteItemLeft  = new QListWidgetItem;
	deleteItemLeft = new QListWidgetItem;

	//layouts
	leftWgtLayout = new QVBoxLayout(this);
	menuWgtLayout = new QHBoxLayout(this);

	//Widgets
	listingLeft = new QListWidget(this);
	leftWgt     = new QWidget(this);
	menuWgt     = new QWidget(this);
	//objecting actions
	pactCopy = new QAction(this);
	pactCut = new QAction(this);
	pactPaste = new QAction(this);
	pactDelete = new QAction(this);
	pactMore = new QAction(this);

	//setting texts for left menu
	copyItemLeft  ->setText(QStringLiteral("Копировать"));
	cutItemLeft   ->setText(QStringLiteral("Вырезать"));
	pasteItemLeft ->setText(QStringLiteral("Вставить"));
	deleteItemLeft->setText(QStringLiteral("Удалить"));

	//all pos checked
	copyItemLeft	->setCheckState(Qt::Checked);
	cutItemLeft		->setCheckState(Qt::Checked);
	pasteItemLeft	->setCheckState(Qt::Checked);
	deleteItemLeft	->setCheckState(Qt::Checked);

	//inserting all items into left list
	listingLeft	->insertItem(1, copyItemLeft);
	listingLeft	->insertItem(2, cutItemLeft);
	listingLeft	->insertItem(3, pasteItemLeft);
	listingLeft	->insertItem(4, deleteItemLeft);
	
	//positioning on left layer
	leftWgtLayout	->addWidget(listingLeft);
	leftWgtLayout	->addWidget(up);
	leftWgtLayout	->addWidget(down);
	leftWgt			->setLayout(leftWgtLayout);

	//positioning on menu layer
	menuWgtLayout->addWidget(menu);
	menuWgtLayout->addWidget(moremenu);
	//menuWgtLayout->setMargin(0);
	menuWgtLayout->setContentsMargins(QMargins(0, 8, 10, 10));
	menuWgtLayout->setSpacing(0);
	menuWgt		 ->setLayout(menuWgtLayout);
	/*moremenu  ->frameGeometry();
	moremenu->x();
	moremenu->y();*/
	//naming menu points on right part
	pactCopy	->setText(QStringLiteral("Копировать"));
	pactCut		->setText(QStringLiteral("Вырезать"));
	pactPaste	->setText(QStringLiteral("Вставить"));
	pactDelete	->setText(QStringLiteral("Удалить"));
	pactMore	->setText(QStringLiteral("Ещё  ") + sRight);

	//all actions including into menu
	menu	->addAction(pactCopy);
	menu	->addSeparator();
	menu	->addAction(pactCut);
	menu	->addSeparator();
	menu	->addAction(pactPaste);
	menu	->addSeparator();
	menu	->addAction(pactDelete);
	menu	->addSeparator();
	menu	->addAction(pactMore);

	//QMenu menu{ border: 1px solid black; };
	moreCopy = new QAction(this);
	moreCopy->setText(QStringLiteral("Копировать"));
	moremenu->addAction(moreCopy);
	moreCopy->setVisible(false);

	moreCut = new QAction(this);
	moreCut		->setText(QStringLiteral("Вырезать"));
	moremenu	->addAction(moreCut);
	moreCut		->setVisible(false);

	morePaste = new QAction(this);
	morePaste	->setText(QStringLiteral("Вставить"));
	moremenu	->addAction(morePaste);
	morePaste	->setVisible(false);

	moreDelete = new QAction(this);
	moreDelete	->setText(QStringLiteral("Удалить"));
	moremenu	->addAction(moreDelete);
	moreDelete	->setVisible(false);

	connect(listingLeft, SIGNAL(itemChanged(QListWidgetItem*)), 
		SLOT(cutVision(QListWidgetItem*)));//changing moremenu 
	connect(up, SIGNAL(clicked()), SLOT(buttonPosUp()));//moving up
	connect(down, SIGNAL(clicked()), SLOT(buttonPosDown()));//moving down
	connect(MyWindow::pactMore, SIGNAL(triggered()), SLOT(moreShowList()));

	//cursor for buttons
	QCursor curPointing(Qt::PointingHandCursor);
	up->setCursor(curPointing);
	down->setCursor(curPointing);
	up->setToolTip(QStringLiteral("Переместить выше"));
	down->setToolTip(QStringLiteral("Переместить ниже"));

	QFrame *frm = new QFrame;
	frm->setFrameStyle(QFrame:: Raised);
	frm->setLineWidth(10);
	moremenu->setGeometry(10, 35, 50, 20);
	
	//min sizes
	leftWgt		->setFixedSize(QSize(150, 300));
	menuWgt		->setFixedSize(QSize(250, 300));
	moremenu	->setFixedSize(QSize(130, 150));
	//menuWgt->QFrame::NoFrame;
	leftWgt		->setStyleSheet("color: #005eff;");//blue text
	splitter	->addWidget(leftWgt);
	splitter	->addWidget(menuWgt);

	//turning off collapsability for left and right part
	splitter	->setCollapsible(0, false);
	splitter	->setCollapsible(1, false);
	splitter	->setCollapsible(2, false);
	splitter	->setCollapsible(3, false);
	//styling
	
	menu->setStyleSheet("QMenu{ width: 100px; border-left: 1px solid black;}");
	moremenu->setStyleSheet("QMenu{border-left: 0px solid black; border-bottom: 1px solid black; border-right: 1px solid black;}}");


	moremenu->  setVisible(repeatable);
	splitter	->resize(700, 700);
	splitter	->setWindowTitle(QStringLiteral(" Меню"));
	//menuWgt		->setStyleSheet("QMenu::item:hovered { color: #005eff; }");//white font blue text
	splitter	->show();
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

void MyWindow::moreShowList()
{	
	if (repeatable == false)
		repeatable = true;
	else
		repeatable = false;
	moremenu->setVisible(repeatable);
}
//destructor
MyWindow::~MyWindow() {}
//MenuNoClose::~MenuNoClose() {}

//closeEvent::~closeEvent() {}