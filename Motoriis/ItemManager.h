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
private:
	int numItems;
	Item item[3];
};

