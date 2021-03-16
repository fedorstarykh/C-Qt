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

class MyWindow : public QDialog
{
	Q_OBJECT	

public:
	MyWindow(QList<QAction*> actions, QWidget* parent = 0, QString name = QStringLiteral("Меню"));

	bool	load(const QByteArray& data);
	QByteArray	save()const;

protected:
	bool eventFilter(QObject* watched, QEvent* event) final;

private:
	void checkBoxSave(QString name, QListWidgetItem*item);
	void checkBoxLoad(QListWidgetItem* item, QString name, int defaultValue);

	QList<QAction*> _actions;

	QListWidget* listingLeft;

	QSettings* settings;
	//splitter + menu
	QSplitter* splitter;
	QMenu* menu;
	QMenu* moremenu;
	
	QString strMore = (QStringLiteral("Дополнительно "));

	bool repeatable {false};
	
private slots:
	void moreMenuVision(QListWidgetItem *item);
	void moreShowList();
	void buttonPosUp();
	void buttonPosDown();

};

#endif