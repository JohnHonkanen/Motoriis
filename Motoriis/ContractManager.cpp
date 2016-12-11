#include "ContractManager.h"



ContractManager::ContractManager()
{
}

ContractManager::ContractManager(ItemManager *itemManager, EconomyManager *economyManager, Construct *inputs[])
{
	this->activeBuyContracts[0] = NULL;
	this->activeBuyContracts[1] = NULL;
	this->inputs[0] = inputs[0];
	this->inputs[1] = inputs[1];
	this->itemManager = itemManager;
	this->economyManager = economyManager;
	this->generateContracts();
}


ContractManager::~ContractManager()
{
}

void ContractManager::generateContracts()
{
	Item item1 = this->itemManager->findItem(2);
	item1.setAmount(30);
	this->buyContracts[0] = new BuyContracts(item1, 0, 1000, 300);
	this->buyContracts[1] = new BuyContracts(item1, 1, 1100, 100);
	this->buyContracts[2] = new BuyContracts(item1, 2, 1000, 0);

	Item item2 = this->itemManager->findItem(0);
	item2.setAmount(30);

	Item item3 = this->itemManager->findItem(1);
	item3.setAmount(15);

	this->sellContracts[0] = new SellContracts(item3, 0, 400);
	this->sellContracts[1] = new SellContracts(item2, 0, 500);
	this->sellContracts[2] = new SellContracts(item3, 0, 500);
}

Contracts *ContractManager::getBuy(int position)
{
	return this->buyContracts[position];
}

Contracts * ContractManager::getSell(int position)
{
	return this->sellContracts[position];
}

bool ContractManager::getShowMenu()
{
	return this->showMenu;
}

void ContractManager::setShowMenu(bool showMenu)
{
	this->showMenu = showMenu;
}
