#include "Storage.h"



Storage::Storage()
{
	this->containsItem = false;
}

Storage::Storage(int id)
{
	this->ID = id;
	this->containsItem = false;
}

Storage::~Storage()
{
}

void Storage::storeItem(Item *item) {
	Item *newItem = new Item(item->getUID(), item->getName(), item->getType(), item->getSKU(), item->getColor());
	this->item = newItem;
	this->containsItem = true;
}

void Storage::removeItem() {
	this->containsItem = false;
	this->item = NULL;
}

Item *Storage::getItem() {
	return this->item;
}

bool Storage::hasItem()
{
	return this->containsItem;
}
