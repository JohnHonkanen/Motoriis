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
	Item(int uid, string name, int type, string sku, sf::Color color);
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
private:
	int uid, type, amount;
	string name, sku;
	sf::Color color;
};

