#pragma once
#include "ItemManager.h"

using namespace std;

class LogisticSystem : public ItemManager
{
public:
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

private:
	int maxItems;
	int maxStorage;
	int maxConnection;
	int logisticID;
	vector<LogisticSystem> connectedLogistic;
};

