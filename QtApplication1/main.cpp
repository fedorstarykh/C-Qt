#include <QtWidgets/QApplication>
#include <QListWidget>
#include <QCheckBox>
#include <QAction>
#include <QMenuBar>
#include <QObject>
#include <QSettings>
#include "MyWindow.h"

int main(int argc, char** argv)
{
	
	QApplication app{ argc, argv };
	
	QList<QAction*> actions;
	//adding actions to list
	actions.push_back(new QAction{ QStringLiteral("Пункт1")});
	actions.push_back(new QAction{ QStringLiteral("Пункт2")});
	actions.push_back(new QAction{ QStringLiteral("Пункт3")});
	actions.push_back(new QAction{ QStringLiteral("Пункт4")});
	actions.push_back(new QAction{ QStringLiteral("Пункт5")});
	actions.push_back(new QAction{ QStringLiteral("Пункт6")});
	actions.push_back(new QAction{ QStringLiteral("Пункт7")});

	QSettings sett{ "settings.ini", QSettings::Format::IniFormat};
	QByteArray data = sett.value("Settings").toByteArray();
	MyWindow window{actions};
	bool ok = window.load(data);
	Q_ASSERT(ok);

    window.show();
	int res = app.exec();
	auto state = window.save();
	sett.setValue("Settings", state);
	
    return res;
}
