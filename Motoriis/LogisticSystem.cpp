#include "LogisticSystem.h"


LogisticSystem::LogisticSystem(int ID, int maxItems, int maxStorage)
{
	this->maxItems = maxItems;
	this->maxStorage = maxStorage;
	this->logisticID = ID;
}


LogisticSystem::~LogisticSystem()
{
}

bool LogisticSystem::addToList(Item *item) 
{
	if (this->exceedMaxItem()) {
		return false;
	}

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

bool LogisticSystem::exceedMaxItem() 
{
	return (items.size() >= this->maxItems);
}

bool LogisticSystem::storeItem(string sku, int amount) 
{
	if (exceedMaxStorage(amount)) 
	{
		return false;
	}

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

bool LogisticSystem::exceedMaxStorage()
{
	vector<Item*>::iterator it;
	int i = 0;
	int currentStorage = 0;
	for (it = this->items.begin(); it < this->items.end(); it++, i++) {
		currentStorage += items.at(i)->getAmount();
	}
	return (currentStorage >= this->maxStorage);
}

bool LogisticSystem::exceedMaxStorage(int incomingAmount)
{
	vector<Item*>::iterator it;
	int i = 0;
	int currentStorage = 0;
	for (it = this->items.begin(); it < this->items.end(); it++, i++) {
		currentStorage += items.at(i)->getAmount();
	}

	return (currentStorage + incomingAmount >= this->maxStorage);
}

bool LogisticSystem::transferItem(LogisticSystem &system, string sku, int amount) 
{
	if (!this->isConnected(system)){
		return false;
	}

	Item *item = this->getItem(sku)->copy();
	item->setAmount(amount);

	if (system.findItem(sku)) {
		if (system.storeItem(sku, amount)) {
			this->removeItem(sku, amount);
			return true;
		}
	}
	else {
		if (system.addToList(item)) {
			this->removeItem(sku, amount);
			return true;
		} 
		return false;
	}
}

bool LogisticSystem::establishConnection(LogisticSystem &system) 
{
	if (connectedLogistic.size() < maxConnection) {
		connectedLogistic.push_back(system);
		return true;
	} 
	return false;
}

bool LogisticSystem::breakConnection(LogisticSystem &system) 
{
	return true;
}

bool LogisticSystem::isConnected(LogisticSystem &system)
{
	vector<LogisticSystem>::iterator it;
	int i = 0;
	for (it = this->connectedLogistic.begin(); it < this->connectedLogistic.end(); it++, i++) {
		if (this->connectedLogistic.at(i).getID() == system.getID()) {
			return true;
		} 
	}
	return false;
}

int LogisticSystem::getID() {
	return this->logisticID;
}

vector<Item*> LogisticSystem::getItems() {
	return this->items;
}