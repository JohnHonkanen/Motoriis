#include "SFML\Graphics\Color.hpp"
#include<string>
#include<vector>
#include <sstream>
#pragma once

using namespace std;

class Item
{
public:
	Item();
	Item(int uid, string name, int type, string sku, sf::Color color, int basePrice);
	~Item();
	string getName();
	int getType();
	string getSKU();
	sf::Color getColor();
	int getUID() { return this->uid; };
	int getAmount();
	void addAmount(int amount);
	void reduceAmount(int amount);
	void setAmount(int amount);
	int getBasePrice();
	bool isCompound();
	void makeCompound(int item1, int item2);
	int getItem1Id();
	int getItem2Id();
	void changeModifier(float modifier);
private:
	int uid, type, amount;
	string name, sku;
	sf::Color color;
	bool compoundItem;
	int item1Id = -1;
	int item2Id = -1;
	int basePrice = 0;
	float modifier = 0;
};

