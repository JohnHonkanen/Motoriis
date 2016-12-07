#include "ItemManager.h"



ItemManager::ItemManager()
{
	this->init();
}


ItemManager::~ItemManager()
{
}

bool ItemManager::init()
{
	Item item0 = Item(0, "Blueberry", 1, "BLU0", sf::Color(122, 0, 168));
	Item item1 = Item(1, "Milk", 1, "MLK0", sf::Color(220, 217, 205));
	Item item2 = Item(2, "Blueberry Icecream", 0, "BLU0", sf::Color(55, 0, 255));
	this->addItem(item0);
	this->addItem(item1);
	this->addItem(item2);
	return false;
}

bool ItemManager::addItem(Item item)
{
	this->item[this->numItems] = item;
	this->numItems++;
	return true;
}

Item ItemManager::findItem(int id)
{
	return this->item[id];
}
