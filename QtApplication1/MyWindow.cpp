#include "MyWindow.h"
#include <QList>
#include <QTextStream>
#include <QMenu>

MyWindow::MyWindow(QWidget* parent) : QDialog(parent)
{

	//lbl = new QLabel("Enter");
	//line = new QLineEdit;
	
	cb1 = new QCheckBox("Copy");
	cb1->setChecked(true);
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
	//layout->addWidget(lbl);//подпись
	//layout->addWidget(line);// поле ввода

	//right layer
	QVBoxLayout* right = new QVBoxLayout;
	right->addWidget(cb1);//чекбоксы списком
	right->addWidget(cb2);
	right->addWidget(cb3);
	right->addWidget(cb4);
	right->addLayout(layout);

	//left layer
	QVBoxLayout* left = new QVBoxLayout;

	/*QVBoxLayout* layout_2 = new QVBoxLayout;
	layout_2->*/
	QMenu* pcopy = new QMenu("&Copy ");
	pcopy->setDisabled(true);
	QMenu* pcut = new QMenu("&Cut ");
	pcut->setDisabled(true);
	QMenu* ppaste = new QMenu("&Paste ");
	ppaste->setDisabled(true);
	QMenu* pdelete = new QMenu("&Delete ");
	pdelete->setDisabled(true);
	QMenu* pmore = new QMenu("&More ");
	pmore->setDisabled(true);

	
	left->addWidget(pcopy);
	left->addWidget(pcut);
	left->addWidget(ppaste);
	left->addWidget(pdelete);
	left->addWidget(pmore);
	//left->addLayout(mnuBar);
	//left->addWidget(list);
	
	//main layer
	QHBoxLayout* main = new QHBoxLayout;
	main->addLayout(right);
	main->addLayout(left);	

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
	//delete line;
	//delete lbl;
}