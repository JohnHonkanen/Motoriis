#pragma once
#include "BuyContracts.h";
#include "SellContracts.h";
#include "ItemManager.h"
#include "EconomyManager.h"
class ContractManager
{
public:
	ContractManager();
	ContractManager(ItemManager *itemManager, EconomyManager *economyManager, Construct *inputs[]);
	~ContractManager();
	void generateContracts();
	Contracts *getBuy(int position);
	Contracts *getSell(int position);
	bool getShowMenu();
	void setShowMenu(bool showMenu);
	Contracts *activeBuyContracts[2];
private:
	Contracts *buyContracts[3];
	Contracts *sellContracts[3];
	int numberOfActive;
	ItemManager *itemManager;
	EconomyManager *economyManager;
	bool showMenu = false;
	Construct *inputs[2];
};

