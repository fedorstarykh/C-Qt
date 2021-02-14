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
#include <QTableWidget>

class MyWindow : public QDialog
{
	Q_OBJECT

public:
	MyWindow(QWidget *parent = 0);
	virtual ~MyWindow();
	
private:
	QCheckBox* cb1;
	QCheckBox* cb2;
	QCheckBox* cb3;
	QCheckBox* cb4;
	QPushButton* up;
	QPushButton* down; 

//private slots:
//	void UpClicked();
//	void DownClicked();
};

#endif