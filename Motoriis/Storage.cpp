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

void Storage::storeItem(Item item) {
	this->item = item;
	this->containsItem = true;
}

void Storage::removeItem() {
	this->containsItem = false;
	this->item = Item();
}

Item Storage::getItem() {
	return this->item;
}

bool Storage::hasItem()
{
	return this->containsItem;
}
