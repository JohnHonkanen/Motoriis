#include "EconomyManager.h"



EconomyManager::EconomyManager()
{
	this->font.loadFromFile("Fonts/Bungee-Regular.ttf");
	this->goldTexture.loadFromFile("Texture/gold.png");
	this->money = 3000;
}


EconomyManager::~EconomyManager()
{
}

int EconomyManager::getMoney()
{
	return this->money;
}

void EconomyManager::addMoney(int money)
{
	this->money += money;
}

void EconomyManager::reduceMoney(int money)
{
	this->money -= money;
}

void EconomyManager::render(sf::RenderWindow *window, sf::View view)
{
	sf::String money;
	money = std::to_string(this->getMoney());
	sf::Text text(money, this->font,view.getSize().x/5);
	if (this->money < 0) {
		text.setColor(sf::Color::Red);
	}
	else
		text.setColor(sf::Color::White);
	text.setScale(sf::Vector2f(0.1f,0.1f));
	float positionX = view.getCenter().x - view.getSize().x / 2;
	float positionY = view.getCenter().y - view.getSize().y / 2;
	text.setPosition(sf::Vector2f(positionX, positionY) + sf::Vector2f(view.getSize().x / 30, 0));

	//Gold Bar
	sf::RectangleShape gold;
	gold.setTexture(&this->goldTexture, false);
	gold.setSize(sf::Vector2f(view.getSize().x/33, view.getSize().x/33));
	gold.setPosition(sf::Vector2f(positionX, positionY));
	window->draw(text);
	window->draw(gold);
}
