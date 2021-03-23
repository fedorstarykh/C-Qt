#include <QList>
#include <QtWidgets>
#include <QSplitter>
#include <QListWidget>
#include <QAction>
#include <QObject>
#include <QMetaObject>
#include <iostream>
#include <QCloseEvent>
#include <QSettings>
#include "MyWindow.h"

MyWindow::MyWindow(QList<QAction*> actions, QWidget* parent, QString name) :
	QDialog(parent),
	_actions{ actions },
	splitter{ new QSplitter{this} }
{
	std::wstring strRight = L"\u276f";	//arrow right
	QString sRight = QString::fromStdWString(strRight);
	std::wstring strUp    = L"\u25b2";			//arrow up
	std::wstring strDown  = L"\u25bc";		//arrow down
	
	QString sUp    = QString::fromStdWString(strUp);
	QString sDown  = QString::fromStdWString(strDown);
	QPushButton* up		= new QPushButton(sUp);
	QPushButton* down	= new QPushButton(sDown);

	QPushButton* addSep = new QPushButton;
	addSep->setText(QStringLiteral("Добавить разделитель"));
	//menu
	splitter = new QSplitter(Qt::Horizontal);
	
	listingLeft = new QListWidget(this);
	for (auto act : _actions)
	{
		
		auto item = new QListWidgetItem;
		item->setText(act->text());
		listingLeft->addItem(item);
		item->setCheckState(Qt::Checked);
		if (item->text().contains(strMore))
		{
			item->setHidden(true);
		}
	}
	menu = new QMenu;
	menu->installEventFilter(this);
	for (auto actm : _actions)
	{
		auto itemm = new QAction;
		itemm->setText(actm->text());
		menu->addAction(itemm);
		menu->addSeparator();
		if (itemm->text().contains(strMore))
		{
			connect(itemm, &QAction::triggered, this, &MyWindow::moreShowList);//showing elements in moremenu
		}
	}
	moremenu = new QMenu;
	moremenu->installEventFilter(this);
	for (auto actmm : _actions)
	{
		auto itemmm = new QAction;
		itemmm->setText(actmm->text());
		moremenu->addAction(itemmm);
		moremenu->addSeparator();
		itemmm->setVisible(false);
		if (itemmm->text().contains(strMore))
		{
			itemmm->setVisible(false);
		}
	}
		
	//layouts
	QVBoxLayout*  leftWgtLayout = new QVBoxLayout(this);
	QHBoxLayout*  menuWgtLayout = new QHBoxLayout(this);

	//Widgets
	QWidget* leftWgt     = new QWidget(this);
	QWidget* menuWgt     = new QWidget(this);

	//settings
	settings = new QSettings("ORG", "MyProgram", this);
	
	//positioning on left layer
	leftWgtLayout	->addWidget(listingLeft);
	leftWgtLayout	->addWidget(up);
	leftWgtLayout	->addWidget(down);
	leftWgtLayout	->addWidget(addSep);
	leftWgt			->setLayout(leftWgtLayout);

	//positioning on menu layer
	menuWgtLayout->addWidget(menu);
	menuWgtLayout->addWidget(moremenu);
	menuWgtLayout->setSpacing(0);
	menuWgt		 ->setLayout(menuWgtLayout);
	QAction* pactMore = new QAction;
	pactMore->setText(QStringLiteral("Дополнительно ") + sRight);
	menu->addAction(pactMore);

	connect(listingLeft, SIGNAL(itemChanged(QListWidgetItem*)), 
		SLOT(moreMenuVision(QListWidgetItem*)));//changing moremenu 
	connect(up, SIGNAL(clicked()), SLOT(buttonPosUp()));//moving up
	connect(down, SIGNAL(clicked()), SLOT(buttonPosDown()));//moving down
	connect(addSep, SIGNAL(clicked()), SLOT(sepAddingButton()));//add separator
	connect(addSep, SIGNAL(clicked(QListWidgetItem*)), SLOT(sepCheck(QListWidgetItem*)));//add separator
	//cursor for buttons
	//cursor for buttons
	QCursor curPointing(Qt::PointingHandCursor);
	up->setCursor(curPointing);
	down->setCursor(curPointing);
	addSep->setCursor(curPointing);
	up->setToolTip(QStringLiteral("Переместить выше"));
	down->setToolTip(QStringLiteral("Переместить ниже"));

	leftWgt		->setFixedSize(QSize(150, 300));
	splitter	->addWidget(leftWgt);
	splitter	->addWidget(menuWgt);
	auto layout = new QVBoxLayout{ this };
	layout->addWidget(splitter);

	//turning off collapsability
	splitter->setCollapsible(0, false);
	splitter->setCollapsible(1, false);

	//styling
	//menu->setStyleSheet("QMenu{ width: 100px; border-left: 1px solid black;}");
	//moremenu->setStyleSheet("QMenu{border-left: 0px solid black; border-bottom: 1px solid black; border-right: 1px solid black;}}");
	//leftWgt->setStyleSheet("color: #005eff;");//blue text

	QCoreApplication::setOrganizationName("ORG");
	QCoreApplication::setApplicationName(QStringLiteral("Меню"));
	
}
QByteArray MyWindow::save() const
{
	//settings->beginGroup("listsave");
	//geom saving
	//settings->setValue("geometry", splitter->geometry());
	//settings->endGroup();
	QMap<QString, int> savings;
	savings["copy"] = 0;
	savings["cut"] = 2;
	savings["paste"] = 2;
	savings["delete"] = 2;

	QFile file("saveFile.txt");
	if (file.open(QIODevice::WriteOnly)) 
	{
		QDataStream stream(&file);
		stream.setVersion(QDataStream::Qt_5_15);
		stream << QListWidgetItem("1") << QListWidgetItem("2")<<QListWidgetItem("3") <<QListWidgetItem("4");
		//stream << savings;

	}
	file.close();
	return QByteArray();
}
bool MyWindow::load(const QByteArray& data)
{
	//QMap<QString, int> savings;
	//settings->beginGroup("listsave");
	QFile file("saveFile.txt");
	if (file.open(QIODevice::ReadOnly))
	{
		QDataStream stream(&file);
		stream.setVersion(QDataStream::Qt_5_15);
		//stream >> savings;
	}
	////geom load
	//splitter->setGeometry(settings->value("geometry", QRect(200, 200, 300, 300)).toRect());//loading last pos of window
	//settings->endGroup();
	return true;
}

bool MyWindow::eventFilter(QObject* watched, QEvent* event)
{
	if ((watched == menu || watched == moremenu) && (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease))
	{
		return true;
	}
	return false;
}

//void MyWindow::checkBoxSave(QString name, QListWidgetItem *item)
//{
//	settings->setValue(name, (int)item->checkState());
//}
//
//void MyWindow::checkBoxLoad(QListWidgetItem* item, QString name, int defaultValue)
//{
//	item->setCheckState((Qt::CheckState)settings->value(name, defaultValue).toInt());
//}

void MyWindow::moreMenuVision(QListWidgetItem* item)
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
	int borderDown = listingLeft->count();
	borderDown--;
	if (currentRowDown < borderDown  && currentRowDown >= 0)
	{
		QListWidgetItem tmp_2 = *(listingLeft->currentItem());
		int downRow = currentRowDown + 1;

		*(listingLeft->item(currentRowDown)) = *(listingLeft->item(downRow));
		*(listingLeft->item(downRow)) = tmp_2;

		listingLeft->insertItem(currentRowDown, listingLeft->item(downRow));
		listingLeft->setCurrentItem(listingLeft->item(downRow));
	}
}

void MyWindow::sepAddingButton()
{
	//listingLeft->setStyleSheet("QListWidget::item { border-bottom: 1px solid black; }");
	QListWidgetItem* sep = new QListWidgetItem;
	sep->setText(sepsymbol);
	listingLeft->addItem(sep);
}

void MyWindow::sepCheck(QListWidgetItem* separator)
{
	for (auto leflis : listingLeft->actions())
	{
		if (leflis->text().contains(separator->text()))
		{
			menu->addSeparator();
		}
	}
	
}