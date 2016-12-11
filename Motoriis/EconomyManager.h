#pragma once
#include <string>
#include "SFML\Graphics.hpp"
#include "Menu.h"

class EconomyManager
{
public:
	EconomyManager();
	~EconomyManager();
	int getMoney();
	void addMoney(int money);
	void reduceMoney(int money);
	void render(sf::RenderWindow *window, sf::View view);
private:
	sf::Clock clock;
	sf::Time elasped;
	sf::Font font;
	sf::Texture goldTexture;

	int money;
};

