#include "MyWindow.h"
#include "sigsnslots.h"
#include <QList>
#include <QtWidgets>
#include <QApplication>
#include <QTextStream>
#include <QMenu>
#include <QListWidget>
#include <QAction>
#include <QObject>
#include <QMetaObject>

MyWindow::MyWindow(QWidget* parent) : QDialog(parent)
{

	//lbl = new QLabel("Enter");
	//line = new QLineEdit;
	
	cb1 = new QCheckBox("Copy");
	cb1->setChecked(true);
//	cb1->addAction( );

	cb2 = new QCheckBox("Cut");
	cb2->setChecked(true);
	cb3 = new QCheckBox("Paste");
	cb3->setChecked(true);
	cb4 = new QCheckBox("Delete");
	cb4->setChecked(true);

	up = new QPushButton("Move up");
	down = new QPushButton("Move down");

	
	//QList<QString> list = { "hi" };
	


	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(up);//кнопки 	
	layout->addWidget(down);
	

	QObject::connect(up, SIGNAL(clicked(), &app, SLOT(quit())));

	//right layer
	QVBoxLayout* right = new QVBoxLayout;
	right->addWidget(cb1);//чекбоксы списком
	right->addWidget(cb2);
	right->addWidget(cb3);
	right->addWidget(cb4);
	right->addLayout(layout);

	//left layer
	QVBoxLayout* left = new QVBoxLayout;
	QListWidget* spisok = new QListWidget;
		spisok->addItem("Copy");
		spisok->addItem("Cut");
		spisok->addItem("Paste");
		spisok->addItem("Delete");
		spisok->addItem("More");
		left->addWidget(spisok);

	//left+1layer
		QVBoxLayout* lefter = new QVBoxLayout;
		QListWidget* spisok_2 = new QListWidget;
		spisok_2->addItem("Copy");
		spisok_2->addItem("Cut");
		spisok_2->addItem("Paste");
		spisok_2->addItem("Delete");
		lefter->addWidget(spisok_2);

	//main layer
	QHBoxLayout* main = new QHBoxLayout;
	main->addLayout(right);
	main->addLayout(left);	
	main->addLayout(lefter);

	resize(500, 500);
	setLayout(main);
	setWindowTitle("MENU");
}


//destructor
MyWindow::~MyWindow() 
{
	delete down;
	delete up;
	delete cb4;
	delete cb3;
	delete cb2;
	delete cb1;
	
}