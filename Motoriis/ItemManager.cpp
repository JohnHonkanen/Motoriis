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
	//First Set
	Item item0 = Item(0, "Blueberry", 1, "BLU0", sf::Color(6, 79, 186), 13);
	Item item1 = Item(1, "Milk", 1, "MLK0", sf::Color(224, 222, 225), 10);
	Item item2 = Item(2, "Strawberries", 1, "STRAWBRRY", sf::Color(232, 3, 27), 8);
	this->addItem(item0);
	this->addItem(item1);
	this->addItem(item2);
	//Second Set
	Item item3 = Item(3, "Cream", 1, "CREAM", sf::Color(255,255,255), 23);
	item3.makeCompound(1, 1);
	Item item4 = Item(4, "Blueberry Icecream", 0, "BLUICE", sf::Color(197, 119, 167), 40);
	item4.makeCompound(3, 0);
	Item item5 = Item(5, "Strawberry Cream", 1, "SBRRYCREAM", sf::Color(245, 177, 175), 38);
	item5.makeCompound(3, 2);
	this->addItem(item3);
	this->addItem(item4);
	this->addItem(item5);
	//Third Set
	Item item6 = Item(6, "Blueberry Extract", 1, "BLU0EX", sf::Color(6, 79, 255), 29);
	item6.makeCompound(0,0);
	Item item7 = Item(7, "Strawberry Extract", 1, "STRAWBRRYEX", sf::Color(255, 3, 27), 23);
	item7.makeCompound(2, 2);
	Item item8 = Item(8, "Mixed Berry Extract", 0, "MIXEX", sf::Color(255, 100, 255), 70);
	item8.makeCompound(6, 7);
	this->addItem(item6);
	this->addItem(item7);
	this->addItem(item8);
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

Item ItemManager::findCompound(int id1, int id2)
{
	for (int i = 0; i < this->numItems; i++) {
		if (this->item[i].isCompound()) {
			if (this->item[i].getItem1Id() == id1) {
				if (this->item[i].getItem2Id() == id2) {
					return this->item[i];
				}
			} else if(this->item[i].getItem2Id() == id1){
				if (this->item[i].getItem1Id() == id2) {
					return this->item[i];
				}
			}
		}
	}
	return Item();
}
