#include <QtWidgets/QApplication>
#include "MyAction.h"
#include "MainWindow.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    std::unique_ptr<MainWindow> window(new MainWindow());
     // window->show();
    
    //adding actions with Act_Constructor
    MyAction Copy(1, "Copy", "Copy");
    MyAction Cut(2, "Cut", "Cut");
    MyAction Paste(3, "Paste", "Paste");
    MyAction Delete(4, "Delete", "Delete");
   
    return app.exec();
}