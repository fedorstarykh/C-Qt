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

static const QChar sepstrL{ 0x2015 };
static QString separatorText()//separator
{
	return { 10, sepstrL };
}

MyWindow::MyWindow(QList<QAction*> actions, QWidget* parent, QString name) :
	QDialog(parent),
	_actions{ actions },
	splitter{ new QSplitter{this} }
{
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
	}

	menu = new QMenu;
	menu->installEventFilter(this);
	for (auto actm : _actions)
	{
		auto* itemm = new QAction;
		itemm->setText(actm->text());
		menu->addAction(itemm);
		if (itemm->text().contains(QString(QStringLiteral("Дополнительно"))))
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
		itemmm->setVisible(false);
	}

	//layouts
	QVBoxLayout* leftWgtLayout = new QVBoxLayout(this);
	QHBoxLayout* menuWgtLayout = new QHBoxLayout(this);

	//Widgets
	QWidget* leftWgt = new QWidget(this);
	QWidget* menuWgt = new QWidget(this);

	//settings
	settings = new QSettings("ORG", "MyProgram", this);

	//positioning on left layer
	leftWgtLayout->addWidget(listingLeft);
	leftWgtLayout->addWidget(up);
	leftWgtLayout->addWidget(down);
	leftWgtLayout->addWidget(addSep);
	leftWgt->setLayout(leftWgtLayout);

	//positioning on menu layer
	menuWgtLayout->addWidget(menu);
	menuWgtLayout->addWidget(moremenu);
	menuWgtLayout->setSpacing(0);
	menuWgt->setLayout(menuWgtLayout);
	
	pactMore->setText(QStringLiteral("Дополнительно ") + sRight);
	menu->addAction(pactMore);
	menu->setMinimumWidth(menu->sizeHint().width());
	moremenu->setMinimumWidth(menu->sizeHint().width());

	//connections
	connect(listingLeft, SIGNAL(itemChanged(QListWidgetItem*)),
		SLOT(moreMenuVision(QListWidgetItem*)));//changing moremenu 
	connect(up, SIGNAL(clicked()), SLOT(buttonPosUp()));//moving up
	connect(down, SIGNAL(clicked()), SLOT(buttonPosDown()));//moving down
	connect(addSep, SIGNAL(clicked()), SLOT(sepAddingButton()));//add separator
	connect(listingLeft, SIGNAL(itemSelectionChanged()), SLOT(sepChange()));//add separator
	connect(listingLeft, SIGNAL(itemSelectionChanged()), SLOT(sepDisable()));//add separator
	connect(listingLeft, SIGNAL(currentItemChanged()), SLOT(sepDisable()));//add separator extra connect

	//cursor for buttons
	QCursor curPointing(Qt::PointingHandCursor);
	up->setCursor(curPointing);
	down->setCursor(curPointing);
	addSep->setCursor(curPointing);
	up->setToolTip(QStringLiteral("Переместить выше"));
	down->setToolTip(QStringLiteral("Переместить ниже"));

	//leftWgt->setFixedSize(QSize(150, 300));
	splitter->addWidget(leftWgt);
	splitter->addWidget(menuWgt);
	auto layout = new QVBoxLayout{ this };
	layout->addWidget(splitter);

	//turning off collapsability
	splitter->setCollapsible(0, false);
	splitter->setCollapsible(1, false);

	//winstyle
	//menu->setStyleSheet("QMenu{ width: 100px; border-left: 1px solid black;}");
	//moremenu->setStyleSheet("QMenu{border-left: 0px solid black; border-bottom: 1px solid black; border-right: 1px solid black;}}");
	//leftWgt->setStyleSheet("color: #005eff;");//blue text

	QCoreApplication::setOrganizationName("ORG");
	QCoreApplication::setApplicationName(QStringLiteral("Меню"));

}

struct MySaveData
{
	QString name;
	int checkState;
	bool isSeparator{ false };
};

QDataStream& operator << (QDataStream& stream, const MySaveData& data)
{
	stream << data.name;
	stream << data.checkState;
	stream << data.isSeparator;
	return stream;
}

QDataStream& operator >>(QDataStream& stream, MySaveData& data)
{
	stream >> data.name;
	stream >> data.checkState;
	stream >> data.isSeparator;
	return stream;
}

QByteArray MyWindow::save() const
{
	QByteArray arr;
	{
		QDataStream stream{ &arr, QIODevice::WriteOnly };
		stream << listingLeft->count();
		for (int i = 0; i < listingLeft->count(); i++)
		{
			QListWidgetItem* item = listingLeft->item(i);
			MySaveData data{ item->text(), int(item->checkState()), item->text() == separatorText() };
			stream << data;
		}
	}
	return arr;
}

bool MyWindow::load(const QByteArray& data)
{
	QDataStream stream{ data };
	int count{};
	stream >> count;

	MySaveData buffer;
	for (int i = 0; i < count; i++)
	{
		stream >> buffer;
		if (buffer.isSeparator)
		{
			listingLeft->insertItem(i, separatorText());
		}
		auto items = listingLeft->findItems(buffer.name, Qt::MatchFlag::MatchExactly);
		/*for (int i = 0; i < listingLeft->count(); i++)
			QListWidgetItem* nonsep = listingLeft->item(i);*/
			if (items.size() == 1 /*&& !nonsep->text().contains(sepstrL)*/)
			{
				items.front()->setCheckState(static_cast<Qt::CheckState>(buffer.checkState));
			}
		
	}
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

		auto actions = menu->actions();
		auto actSepCheck = listingLeft->currentItem()->text();// taking element text
		auto moreacts = moremenu->actions();
		auto check = listingLeft->currentItem()->checkState();
		
		if (check == 2 /*&& actSepCheck != sepstrL*/)
		{
			auto foundAct = std::find_if(std::begin(actions), std::end(actions), [text = listingLeft->currentItem()->text()](QAction* act)
			{
				return act->text().contains(text);
			});
			if (foundAct == std::end(actions) )
				return;
			Q_ASSERT(foundAct != std::begin(actions));

			auto prev = foundAct - 1;
			std::swap(*foundAct, *prev);
			auto item = listingLeft->currentItem();
			auto check = item->checkState();
			menu->clear();
			menu->addActions(actions);
		}
		else /*if (actSepCheck != sepstrL)*/
		{
			auto foundAct = std::find_if(std::begin(moreacts), std::end(moreacts), [text = listingLeft->currentItem()->text()](QAction* act)
			{
				return act->text().contains(text);
			});
			if (foundAct == std::begin(moreacts) )
				return;
			Q_ASSERT(foundAct != std::begin(moreacts));

			auto prev = foundAct - 1;
			std::swap(*foundAct, *prev);
			moremenu->clear();
			moremenu->addActions(moreacts);
		}
	}
}

void MyWindow::buttonPosDown()
{
	int currentRowDown = listingLeft->QListWidget::currentRow();
	int borderDown = listingLeft->count();
	borderDown--;
	if (currentRowDown < borderDown && currentRowDown >= 0)
	{
		QListWidgetItem tmp_2 = *(listingLeft->currentItem());
		int downRow = currentRowDown + 1;

		*(listingLeft->item(currentRowDown)) = *(listingLeft->item(downRow));
		*(listingLeft->item(downRow)) = tmp_2;

		listingLeft->insertItem(currentRowDown, listingLeft->item(downRow));
		listingLeft->setCurrentItem(listingLeft->item(downRow));
		
		auto actions = menu->actions();
		auto moreacts = moremenu->actions();
		auto check = listingLeft->currentItem()->checkState();

		if (check == 2 )
		{	
		auto foundAct = std::find_if(std::begin(actions), std::end(actions), [text = listingLeft->currentItem()->text()](QAction* act)
		{
			return act->text().contains(text);
		});
			if (foundAct == std::end(actions))
			return;
		Q_ASSERT(foundAct != std::end(actions));

			auto prev = foundAct + 1;
			std::swap(*foundAct, *prev);
			menu->clear();
			menu->addActions(actions);
		}
		
		else /*if (check == false)*/
		{
			auto foundAct = std::find_if(std::begin(moreacts), std::end(moreacts), [text = listingLeft->currentItem()->text()](QAction* act)
			{
				return act->text().contains(text);
			});
			if (foundAct == std::end(moreacts))
				return;
			Q_ASSERT(foundAct != std::end(moreacts));

			auto prev = foundAct + 1;
			std::swap(*foundAct, *prev);
			moremenu->clear();
			moremenu->addActions(moreacts);
		}	
	}
}

void MyWindow::sepAddingButton()
{	
		QListWidgetItem* curit = listingLeft->currentItem();
		QListWidgetItem* separ = new QListWidgetItem{};
		separ->setText(separatorText());

		if (curit && curit->text().contains(sepstrL))
		{
			delete curit;
		}	
		else
		{
			if (curit && !curit->text().contains(sepstrL))
			{
				listingLeft->insertItem(listingLeft->currentRow() , separ);	
			}
			else
			{	
				int limitSep = listingLeft->count() - sepCounterExp;
				listingLeft->insertItem(limitSep, separ);

				auto actions = menu->actions();
				auto moreacts = moremenu->actions();
				auto check = listingLeft->currentItem()->checkState();
				auto foundAct = std::find_if(std::begin(actions), std::end(actions), [text = listingLeft->currentItem()->text()](QAction* act)
				{
					return act->text().contains(text);
				});
				if (foundAct == std::end(actions))
					return;
				Q_ASSERT(foundAct != std::begin(actions));

				auto item = listingLeft->currentItem();
				auto check = item->checkState();
				menu->clear();
				menu->addActions(actions);

				if (limitSep <= listingLeft->count())
				{
					sepCounterExp = sepCounterExp + 2;
				}
				if (sepCounterExp >= listingLeft->count())//blocking separator overfilling
				{
						addSep->setDisabled(true);	
				}
			}
		}
sepDisable();
}

void MyWindow::sepChange()
{
	QListWidgetItem* sepChanger = listingLeft->currentItem();
	if (sepChanger && sepChanger->text().contains(sepstrL))
	{
		addSep->setText(QStringLiteral("Убрать разделитель"));
	}
	else
	{
		addSep->setText(QStringLiteral("Добавить разделитель"));
	}
}

void MyWindow::sepDisable()
{
	//QList<QListWidgetItem*> sepRow = listingLeft->selectedItems();
	int sepDi = listingLeft->currentRow();
	QListWidgetItem* sepdisable = listingLeft->item(sepDi - 1);
	/*QListWidgetItem* arrowlockup = listingLeft->item(sepDi - 2);
	QListWidgetItem* arrowlockdown = listingLeft->item(sepDi + 2);*/
//	QListWidgetItem* haha = sepRow.startsWith();
	//QListWidgetItem* sepDisabler = sepRow.isEmpty();
	/*if (sepDi- 1== 0 || arrowlockup && arrowlockup->text().contains(sepstrL))
	{
		up->setDisabled(true);
	}
	else
	{
		up->setDisabled(false);
	}

	if (sepDi  == listingLeft->count() || arrowlockdown && arrowlockdown->text().contains(sepstrL))
	{
		down->setDisabled(true);
	}
	else
	{
		down->setDisabled(false);
	}*/

	if (sepDi == 0 || sepdisable && sepdisable->text().contains(sepstrL))
	
	{
		addSep->setDisabled(true);
	}
	else
	{
		addSep->setDisabled(false);
	}
}