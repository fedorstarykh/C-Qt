#include <iostream>
#include <QtWidgets/QApplication>
#include "MainWindow.h"

using namespace std;

MainWindow::MainWindow(QWidget* parent) : QDialog(parent)
{
	//up and down buttons settings
	std::wstring strUp = L"\u25b2";//arrow up
	std::wstring strDown = L"\u25bc";//arrow down
	std::wstring strRight = L"\u276f";//arrow right for menu
	sUp = new QString;
	sDown = new QString;
	sRight = new QString;
	QString sRight = QString::fromStdWString(strRight);
	QString sUp = QString::fromStdWString(strUp);
	QString sDown = QString::fromStdWString(strDown);
	upBtn = new QPushButton(sUp);
	downBtn = new QPushButton(sDown);
	QCursor curPointing(Qt::PointingHandCursor);
	upBtn->setCursor(curPointing);
	downBtn->setCursor(curPointing);
	upBtn->setToolTip(QStringLiteral("����������� ����"));
	downBtn->setToolTip(QStringLiteral("����������� ����"));

	//menu
	splitter = new QSplitter(Qt::Horizontal);
	
	//moreMenu = new QMenu;

	//for left layer
	leftItem = new QListWidgetItem;

	//layouts
	leftWgtLayout = new QVBoxLayout(this);
	menuWgtLayout = new QHBoxLayout(this);

	//Widgets
	listingLeft = new QListWidget(this);
	leftWgt = new QWidget(this);
	menuWgt = new QWidget(this);

	//positioning on left layer
	leftWgtLayout->addWidget(listingLeft);
	leftWgtLayout->addWidget(upBtn);
	leftWgtLayout->addWidget(downBtn);
	leftWgt->setLayout(leftWgtLayout);

	//positioning on menu layer
	//menuWgtLayout->addWidget(menu);
//	menuWgtLayout->addWidget(moreMenu);
	//menuWgtLayout->setMargin(0);
	menuWgtLayout->setContentsMargins(QMargins(0, 8, 10, 10));
	menuWgtLayout->setSpacing(0);
	menuWgt->setLayout(menuWgtLayout);

	//min sizes
	leftWgt->setFixedSize(QSize(150, 300));
	menuWgt->setFixedSize(QSize(250, 300));
	//moreMenu->setFixedSize(QSize(130, 150));
	//menuWgt->QFrame::NoFrame;
	leftWgt->setStyleSheet("color: #005eff;");//blue text
	splitter->addWidget(leftWgt);
	splitter->addWidget(menuWgt);
	splitter->show();
}

////setting leftitem
//void MainWindow::setLeftItem(int leftitemid, QString leftitemname)
//{	int counterForPos = 0;
//	for (int i = 0; i > 0; i++)
//	{
//		counterForPos++;
//		leftItemId = leftitemid;
//		leftItem->setText(leftitemname);
//		leftItem->setCheckState(Qt::Checked);
//		listingLeft->insertItem(counterForPos, leftItem);
//	}
//}
////left item name getter
//QString MainWindow::getLeftItemName()
//{
//	return leftItemName;
//}
////left item id getter
//int MainWindow::getLeftItemId()
//{
//	return leftItemId;
//}
MainWindow::~MainWindow()
{

}

