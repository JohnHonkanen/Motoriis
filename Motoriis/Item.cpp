#include "Item.h"

Item::Item() {

}
Item::Item(int uid, string name, int type, string sku, sf::Color color, int basePrice)
{
	this->uid = uid;
	this->name = name;
	this->type = type;
	this->sku = sku;
	this->color = color;
	this->amount = 1;
	this->basePrice = basePrice;
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

int Item::getBasePrice()
{
	return this->basePrice;
}

bool Item::isCompound()
{
	return this->compoundItem;
}

void Item::makeCompound(int item1, int item2)
{
	this->compoundItem = true;
	this->item1Id = item1;
	this->item2Id = item2;
}

int Item::getItem1Id()
{
	return this->item1Id;
}

int Item::getItem2Id()
{
	return this->item2Id;
}

void Item::changeModifier(float modifier)
{
	this->modifier = modifier;
}
