#include <QtWidgets/QApplication>
#include <QListWidget>
#include <QCheckBox>
#include <QAction>
#include <QMenuBar>
#include <QObject>
#include <QSettings>
#include "MyWindow.h"
#include "menuNoClose.h"
#include "MyAction.h"

int main(int argc, char** argv)
{
	
    QApplication app(argc, argv);
    std::unique_ptr<MyWindow> window( new MyWindow());

	//MyAction Copy(1, "Copy", "Copy");
	//MyAction Cut(2, "Cut", "Cut");
	//MyAction Paste(3, "Paste", "Paste");
	//MyAction Delete(4, "Delete", "Delete");
	

	//settings.setValue("/Settings/StringKey", "String Value");
	//settings.setValue("/Settings/IntegerKey", 213);
	//settings.setValue("/Settings/BooleanKey", true);
    //window->show();
    return app.exec();
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
	if (currentRowDown < 3 && currentRowDown >= 0)
	{
		QListWidgetItem tmp_2 = *(listingLeft->currentItem());
		int downRow = currentRowDown + 1;

		*(listingLeft->item(currentRowDown)) = *(listingLeft->item(downRow));
		*(listingLeft->item(downRow)) = tmp_2;

		listingLeft->insertItem(currentRowDown, listingLeft->item(downRow));
		listingLeft->setCurrentItem(listingLeft->item(downRow));
	}

}
