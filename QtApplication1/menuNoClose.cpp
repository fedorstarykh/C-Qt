#include "closeEvent.h"
#include "MyWindow.h"
#include "menuNoClose.h"

//MenuNoClose::MenuNoClose(QMenu* parent) : QMenu(parent) 
////{ 
////		sRight = new QString;
////		QString sRight = QString::fromStdWString(strRight);
////		menu = new QMenu;
////		moremenu = new QMenu;
////		menuWgtLayout = new QHBoxLayout(this);
////		moreLayout = new QVBoxLayout(this);
////		menuWgtLayout = new QHBoxLayout(this);
////		moreLayout = new QVBoxLayout(this);
////		//menuWgt = new QWidget(this);
////		moreWgt = new QWidget(this);
////
////		//positioning on menu layer
////		menuWgtLayout->addWidget(menu);
////		menuWgtLayout->addWidget(moremenu);
////		menuWgt->setLayout(menuWgtLayout);
////
////		//objecting actions
////		pactCopy = new QAction(this);
////		pactCut = new QAction(this);
////		pactPaste = new QAction(this);
////		pactDelete = new QAction(this);
////		pactMore = new QAction(this);
////
////		//naming menu points on right part
////		pactCopy->setText(QStringLiteral("����������"));
////		pactCut->setText(QStringLiteral("��������"));
////		pactPaste->setText(QStringLiteral("��������"));
////		pactDelete->setText(QStringLiteral("�������"));
////		pactMore->setText(QStringLiteral("���  ") + sRight);
////
////		//all actions including into menu
////		menu->addAction(pactCopy);
////		menu->addSeparator();
////		menu->addAction(pactCut);
////		menu->addSeparator();
////		menu->addAction(pactPaste);
////		menu->addSeparator();
////		menu->addAction(pactDelete);
////		menu->addSeparator();
////		menu->addAction(pactMore);
////
////		moreCopy = new QAction(this);
////		moreCopy->setText(QStringLiteral("����������"));
////		moremenu->addAction(moreCopy);
////		moreCopy->setVisible(false);
////
////		moreCut = new QAction(this);
////		moreCut->setText(QStringLiteral("��������"));
////		moremenu->addAction(moreCut);
////		moreCut->setVisible(false);
////
////		morePaste = new QAction(this);
////		morePaste->setText(QStringLiteral("��������"));
////		moremenu->addAction(morePaste);
////		morePaste->setVisible(false);
////
////		moreDelete = new QAction(this);
////		moreDelete->setText(QStringLiteral("�������"));
////		moremenu->addAction(moreDelete);
////		moreDelete->setVisible(false);
////
////		menuWgt->setStyleSheet("QMenu::item:NoUpdate { background-color: white; color: #005eff; }");//white font blue text
////
////}
//void QWidget::closeEvent(QCloseEvent * event)
//	{
//		event->ignore();
//	}
//
//MenuNoClose::~MenuNoClose() {}
