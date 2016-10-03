#include "ItemManager.h"

ItemManager::ItemManager()
{
}


ItemManager::~ItemManager()
{
}
/*
	Populate our item list with a CSV itemList
	@param itemList List of CSV string
*/

void ItemManager::populateItems(vector<string> itemList){
	vector<string>::iterator it;
	int i = 0;
	for (it = itemList.begin(); it < itemList.end(); it++, i++) {
		this->items.push_back(Item::convertToItem(itemList.at(i)));
	}
}
/*
	Decrease Item amount from list
	@param sku sku identifer of item
	@param amount Number to add.
*/
bool ItemManager::removeItem(string sku, int amount) {
	vector<Item*>::iterator it;
	int i = 0;
	for (it = this->items.begin(); it < this->items.end(); it++, i++) {
		if (this->items.at(i)->getSKU() == sku) {
			this->items.at(i)->reduceAmount(amount);
			if (this->items.at(i)->getAmount() == 0) {
				this->items.erase(it);
			}
			return true;
		}
	}
	return false;
}
/*
	Add more item amounts to list
	@param sku sku identifer of item
	@param amount Number to add.
*/
bool ItemManager::storeItem(string sku, int amount) {
	vector<Item*>::iterator it;
	int i = 0;
	for (it = this->items.begin(); it < this->items.end(); it++, i++) {
		if (this->items.at(i)->getSKU() == sku) {
			items.at(i)->addAmount(amount);
			return true;
		}
	}
	return false;
}
/*
	Retreive item from list
	@param sku sku identifer of item
*/
Item *ItemManager::getItem(string sku) {
	vector<Item*>::iterator it;
	int i = 0;
	for (it = this->items.begin(); it < this->items.end(); it++, i++) {
		if (this->items.at(i)->getSKU() == sku) {
			return items.at(i)->copy();
		}
	}
	return new Item();
}
/*
	Checks if item is in list
	@param sku sku identifer of item
*/
bool ItemManager::findItem(string sku) {
	vector<Item*>::iterator it;
	int i = 0;
	for (it = this->items.begin(); it < this->items.end(); it++, i++) {
		if (this->items.at(i)->getSKU() == sku)
			return true;
	}
	return false;
}
/*
	Add to the System's List, if already there returns false.
	@param item Item to add to list
*/
bool ItemManager::addToList(Item *item) {
	vector<Item*>::iterator it;
	int i = 0;
	for (it = this->items.begin(); it < this->items.end(); it++, i++) {
		if (this->items.at(i)->getSKU() == item->getSKU()) {
			return false;
		}
	}
	items.push_back(item);
	return true;
}
/*
	Checks if we can accept from the system
	@param system System Identifier
*/
bool ItemManager::canAccept(int system) {
	vector<int>::iterator it;
	int i = 0;
	for (it = this->accept.begin(); it < this->accept.end(); it++, i++) {
		if (accept.at(i) == system)
			return true;
	}
	return false;
}

