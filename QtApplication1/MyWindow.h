#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QDialog>
#include <QPushButton>
#include <QWidget>
#include <QListWidgetItem>
#include <QSplitter>
#include <QBoxLayout>
#include <QList>
#include <QMenu>
#include <QMenuBar>
#include <QTableWidget>
#include <QListWidget>
#include <QSettings>
#include <QFile>
class MyWindow : public QDialog
{
	Q_OBJECT	

public:
	MyWindow(QList<QAction*> actions, QWidget* parent = 0, QString name = QStringLiteral("Μενώ"));

	QByteArray	save()const;
	bool	load(const QByteArray& data);

protected:
	bool eventFilter(QObject* watched, QEvent* event) final;

private:

	QList<QAction*> _actions;

	QListWidget* listingLeft;
	
	QSettings* settings;
	
	//splitter + menu
	QSplitter* splitter;
	QMenu* menu;
	QMenu* moremenu;
	QPushButton* addSep = new QPushButton;

	std::wstring strRight = L"\u276f";	//arrow right
	QString sRight = QString::fromStdWString(strRight);
	std::wstring strUp = L"\u25b2";			//arrow up
	std::wstring strDown = L"\u25bc";		//arrow down
	QString sUp = QString::fromStdWString(strUp);
	QString sDown = QString::fromStdWString(strDown);
	QPushButton* up = new QPushButton(sUp);
	QPushButton* down = new QPushButton(sDown);
	QAction* pactMore = new QAction;
	bool repeatable {false};
	int sepCounterExp {1};
private slots:
	void moreMenuVision(QListWidgetItem *item);
	void moreShowList();//unused + no need
	void buttonPosUp();
	void buttonPosDown();
	void sepAddingButton();
	void sepChange();
	void sepDisable();
};

#endif