#include <QVBoxLayout>
#include <QFont>
#include <QtWidgets>
#include "label.h"

Label::Label(QWidget* parent)
    : QWidget(parent) {

    QList<QString> list;
    list << "Copy " << "Cut " << "Paste " << "Delete";
	
}