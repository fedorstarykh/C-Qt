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
    ListingLeft CopyLeft;
    CopyLeft.setLeftItem(1,"Copy");
    ListingLeft CutLeft;
    CopyLeft.setLeftItem(2, "Cut");
    ListingLeft PasteLeft;
    CopyLeft.setLeftItem(3, "Paste");
    ListingLeft DeleteLeft;
    CopyLeft.setLeftItem(4, "Delete");

    return app.exec();
}
