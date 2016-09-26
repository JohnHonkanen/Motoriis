#pragma once
#include "Item.h"
#include <vector>

using namespace std;

class ItemManager
{
public:
	ItemManager();
	~ItemManager();
	void populateItems(vector<string> itemList);
	bool findItem(string sku);
	bool storeItem(string sku, int amount);
	bool removeItem(string sku, int amount);
	bool addToList(Item *item);
	Item *getItem(string sku);
	bool canAccept(int systemId);

protected:
	vector<Item*> items;
	vector<int> accept;
};

