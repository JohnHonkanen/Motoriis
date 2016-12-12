#pragma once
#include "Item.h"
class ItemManager
{
public:
	ItemManager();
	~ItemManager();
	bool init();
	bool addItem(Item item);
	Item findItem(int id);
	Item findCompound(int id1, int id2);
private:
	int numItems;
	Item item[9];
};

