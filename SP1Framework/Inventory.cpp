#include "Inventory.h"

char firstItem[] = "A Flat Stone";
char secondItem[] = "History Book";
char thirdItem[] = "Stack of Stones";
char storageForItems[] = "";
char noItem[] = "";
bool takeFlatStone, takeHistoryBook, takeStones;

void storeInventory(char firstItem, char secondItem, char thirdItem)
{
	if (takeFlatStone == 1)
	{
		firstItem;
	}
	if (takeHistoryBook == 1)
	{
		secondItem;
	}
	if (takeStones == 1)
	{
		thirdItem;
	}
	else
	{
		noItem;
	}
}

