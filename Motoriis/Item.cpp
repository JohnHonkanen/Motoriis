#include "Item.h"

Item::Item() {

}
Item::Item(int uid, string name, int type, string sku, sf::Color color)
{
	this->uid = uid;
	this->name = name;
	this->type = type;
	this->sku = sku;
	this->color = color;
	this->amount = 1;
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

sf::Color Item::getColor(){
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

void Item::setAmount(int amount) {
	this->amount = amount;
}