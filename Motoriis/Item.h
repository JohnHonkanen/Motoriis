#include<string>
#include<vector>
#include <sstream>
#pragma once

using namespace std;

class Item
{
public:
	Item();
	Item(int uid, string name, int type, string sku, string color);
	Item(int uid, string name, int type, string sku, string color, int amount);
	~Item();
	string getName();
	int getType();
	string getSKU();
	string getColor();
	static Item* convertToItem(string itemString);
	int getAmount();
	void addAmount(int amount);
	void reduceAmount(int amount);
	Item *copy();
	void setAmount(int amount);
private:
	int uid, type, amount;
	string name, sku, color;
};

