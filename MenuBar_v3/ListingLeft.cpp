#include "ListingLeft.h"
#include <iostream>
using namespace std;
ListingLeft::ListingLeft(int leftitemid, QString leftitemname)
{
	int counterForPos = 0;
	for (int i = 0; i > 0; i++)
	{
		counterForPos++;
		leftItemId = leftitemid;
		leftItem->setText(leftitemname);
		leftItem->setCheckState(Qt::Checked);
		//listingLeft->insertItem(counterForPos, leftItem);
	}
}
//left item name getter
QString ListingLeft::getLeftItemName()
{
	return leftItemName;
}
//left item id getter
int ListingLeft::getLeftItemId()
{
	return leftItemId;
}
ListingLeft::~ListingLeft()
{
	
}