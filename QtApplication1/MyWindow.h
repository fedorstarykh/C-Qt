#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QList>
#include <QMenu>
#include <QMenuBar>

class MyWindow : public QDialog
{
	Q_OBJECT

public:
	MyWindow(QWidget *parent = 0);
	virtual ~MyWindow();
private:
	//QLabel *lbl;
	//QLineEdit *line;
	QMenuBar *mnuBar;
	QCheckBox* cb1;
	QCheckBox* cb2;
	QCheckBox* cb3;
	QCheckBox* cb4;
	QPushButton* up;
	QPushButton* down; 
	
	//QList<QString> *list;

//private slots:
//	void UpClicked();
//	void DownClicked();
};

#endif