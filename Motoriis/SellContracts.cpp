#include "SellContracts.h"



SellContracts::SellContracts()
{
}

SellContracts::SellContracts(Item item, int rating, int cost)
{
	this->item = item;
	this->rating = rating;
	this->cost = cost;
	this->type = 1;
}

bool SellContracts::fufill(Construct * construct, EconomyManager* manager)
{
	construct->storage.storeItem(&this->item);
	construct->storage.getItem()->setAmount(this->item.getAmount());
	manager->reduceMoney(this->cost);
	return true;
}


SellContracts::~SellContracts()
{
}

bool SellContracts::purchase()
{
	return false;
}
