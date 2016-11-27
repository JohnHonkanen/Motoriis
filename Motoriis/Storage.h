#include "Item.h"
#include <vector>
#pragma once
class Storage
{
public:
	Storage();
	Storage(int ID);
	~Storage();
	void storeItem(Item item);
	void removeItem();
	Item getItem();
	bool hasItem();

private:
	int ID;
	Item item;
	bool containsItem = false;
};

