#include "Item.h"

Item::Item() {

}
Item::Item(int uid, string name, int type, string sku, string color)
{
	this->uid = uid;
	this->name = name;
	this->type = type;
	this->sku = sku;
	this->color = color;
	this->amount = 0;
}
Item::Item(int uid, string name, int type, string sku, string color, int amount)
{
	this->uid = uid;
	this->name = name;
	this->type = type;
	this->sku = sku;
	this->color = color;
	this->amount = amount;
}


Item::~Item()
{
}

string Item::getName() {
	return this->name;
}
int Item::getType() {
	return this->type;
}

string Item::getSKU() {
	return this->sku;
}

string Item::getColor(){
	return this->color;
}

int Item::getAmount() {
	return this->amount;
}
/*
	Increase Amount
	@param amount Amount to be Increased by
*/
void Item::addAmount(int amount) {
	this->amount += amount;
}
/*
	Reduce Amount
	@param amount Amount to be reduced by
*/
void Item::reduceAmount(int amount) {
	this->amount -= amount;
}
/*
	Change CSV string into an Item datatype
*/
Item* Item::convertToItem(string itemString) {
	string itemProp[5];
	stringstream ss(itemString);
	string token;
	int i = 0;
	while (getline(ss, token, ',')) {
		itemProp[i] = token;
		i++;
	}
	return new Item(stoi(itemProp[0]), itemProp[1], stoi(itemProp[2]), itemProp[3], itemProp[4]);
}
/*
	Create a new instance of this item
*/
Item* Item::copy() {
	return new Item(this->uid, this->name, this->type, this->sku, this->color, this->amount);
}

void Item::setAmount(int amount) {
	this->amount = amount;
}