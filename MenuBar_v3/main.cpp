#include <QtWidgets/QApplication>
#include "MyAction.h"
#include "MainWindow.h"
#include "ListingLeft.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    std::unique_ptr<MainWindow> window(new MainWindow());
     // window->show();
    //adding actions with Act_Constructor
    //id, name, text
    MyAction Copy(1, "Copy", "Copy");
    MyAction Cut(2, "Cut", "Cut");
    MyAction Paste(3, "Paste", "Paste");
    MyAction Delete(4, "Delete", "Delete");
    //id, text
    MainWindow CopyLeft;
    CopyLeft.ListingLeft(1, "Copy");
    MainWindow CutLeft;
    CutLeft.ListingLeft(2, "Cut");
    MainWindow PasteLeft;
    PasteLeft.ListingLeft(3, "Paste");
    MainWindow DeleteLeft;
    DeleteLeft.ListingLeft(4, "Delete");
    //for left layer
    QListWidgetItem* leftItem = new QListWidgetItem;

    //layouts
    QVBoxLayout*  leftWgtLayout = new QVBoxLayout();
    QHBoxLayout*  menuWgtLayout = new QHBoxLayout();

    //Widgets
    QListWidget*  listingLeft = new QListWidget();
    QWidget* leftWgt = new QWidget();
    QWidget*  menuWgt = new QWidget();
    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    QPushButton* upBtn = new QPushButton;
    QPushButton* downBtn = new QPushButton;
    int counterForPos = 0;
   /*  for (int i = 0; i >= 10; i++)
     {
         counterForPos++;
     }*/
    listingLeft->insertItem(counterForPos, leftItem);

    //positioning on left layer
    leftWgtLayout->addWidget(listingLeft);
    leftWgtLayout->addWidget(upBtn);
    leftWgtLayout->addWidget(downBtn);
    leftWgt->setLayout(leftWgtLayout);
    menuWgt->setLayout(menuWgtLayout);

   
    //moreMenu->setFixedSize(QSize(130, 150));
    //menuWgt->QFrame::NoFrame;
    leftWgt->setStyleSheet("color: #005eff;");//blue text
    splitter->addWidget(leftWgt);
    splitter->addWidget(menuWgt);
    splitter->show();

    return app.exec();
}
