#pragma once
#include "ItemManager.h"

using namespace std;

class LogisticSystem : public ItemManager
{
public:
	LogisticSystem();
	LogisticSystem(int ID, int maxItems, int maxStorage);
	~LogisticSystem();
	bool addToList(Item *item);
	bool exceedMaxItem();
	bool storeItem(string sku, int amount);
	bool exceedMaxStorage();
	bool exceedMaxStorage(int incomingAmount);
	bool transferItem(LogisticSystem &system, string sku, int amount);
	bool establishConnection(LogisticSystem &system);
	bool breakConnection(LogisticSystem &system);
	bool isConnected(LogisticSystem &system);
	int getID();
	vector<Item*> getItems();
	void setMaxItems(int max) { this->maxItems = max; }; // Sets Max Item to value
	void setMaxStorage(int max) { this->maxStorage = max; }; // Sets Max storage to value

private:
	int maxItems;
	int maxStorage;
	int maxConnection;
	int logisticID;
	vector<LogisticSystem> connectedLogistic;
};

