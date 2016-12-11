#include "BuyContracts.h"



BuyContracts::BuyContracts()
{
}

BuyContracts::BuyContracts(Item item, int rating, int payment, int advance)
{
	this->item = item;
	this->rating = rating;
	this->cost = payment;
	this->advancePayment = advance;
	this->type = 2;
}

bool BuyContracts::fufill(Construct * construct, EconomyManager* manager)
{
	return false;
}

bool BuyContracts::fufill(EconomyManager* manager)
{
	manager->addMoney(this->cost);
	this->complete = true;
	return true;
}


BuyContracts::~BuyContracts()
{
}

bool BuyContracts::purchase()
{
	return false;
}

void BuyContracts::addToCurrent(int amount)
{
	this->current += amount;
}

int BuyContracts::getCurrent()
{
	return this->current;
}

int BuyContracts::getAdvancedPayment()
{
	return this->advancePayment;
}
