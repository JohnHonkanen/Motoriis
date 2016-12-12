#include "ContractManager.h"



ContractManager::ContractManager()
{
}

ContractManager::ContractManager(ItemManager *itemManager, EconomyManager *economyManager, Construct *inputs[])
{
	this->font.loadFromFile("Fonts/Bungee-Regular.ttf");
	this->activeBuyContracts[0] = NULL;
	this->activeBuyContracts[1] = NULL;
	this->inputs[0] = inputs[0];
	this->inputs[1] = inputs[1];
	this->itemManager = itemManager;
	this->economyManager = economyManager;
	this->buyContracts[0] = NULL;
	this->buyContracts[1] = NULL;
	this->buyContracts[2] = NULL;
	this->generateContracts();
}


ContractManager::~ContractManager()
{
}

void ContractManager::generateContracts()
{
	//Generate BUY CONTRACTS
	for (int i = 0; i < 3; i++) {
		if (this->buyContracts[i]) {
			if (this->buyContracts[i]->getActive() && !this->buyContracts[i]->isComplete())
				continue;
		}
		int itemId = rand() % 8 + 3;
		if (itemId > 8)
			itemId = 8;

		int rating = rand() % 3;
		float priceModifier = 1;
		float amountModifier = 1;
		switch (rating)
		{
		case 0:
			priceModifier = ((rand() % 5 + 5)/10.0f) + 1;
			amountModifier = ((rand() % 5 + 5) / 10.0f) + 1;
		case 1:
			priceModifier = ((rand() % 3 + 3) / 10.0f) + 1;
			amountModifier = ((rand() % 3 + 3) / 10.0f) + 1;
		case 2:
			priceModifier = ((rand() % 1 + 1) / 10.0f) + 1;
			amountModifier = ((rand() % 1 + 1) / 10.0f) + 1;
		default:
			break;
		}

		Item item = this->itemManager->findItem(itemId);
		item.setAmount((rand() % 100 + 10) * amountModifier);
		this->buyContracts[i] = new BuyContracts(item, rating, (item.getAmount() * item.getBasePrice()) * priceModifier, 0);
	}

	for (int i = 0; i < 3; i++) {
		int itemId = rand() % 3;
		int rating = rand() % 3;
		float priceModifier = 1;
		float amountModifier = 1;
		switch (rating)
		{
		case 0:
			priceModifier = 1 - ((rand() % 3 + 2) / 10.0f);
			amountModifier = ((rand() % 5 + 10) / 10.0f) + 1;
		case 1:
			priceModifier = 1 - ((rand() % 3 + 0) / 10.0f);
			amountModifier = ((rand() % 3 + 7) / 10.0f) + 1;
		case 2:
			priceModifier = 1 - ((rand() % 1 + 0) / 10.0f);
			amountModifier = ((rand() % 1 + 2) / 10.0f) + 1;
		default:
			break;
		}
		Item item = this->itemManager->findItem(itemId);
		item.setAmount((rand() % 100 + 10) * amountModifier);
		this->sellContracts[i] = new SellContracts(item, rating, (item.getAmount() * item.getBasePrice()) * priceModifier);
	}
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

void ContractManager::update()
{
	elasped = clock.getElapsedTime();
	if (elasped.asSeconds() > 20.0f) {
		if (this->activeBuyContracts[0] != NULL) {
			if (this->activeBuyContracts[0]->isComplete()) {
				this->activeBuyContracts[0] = NULL;
			}
		}
		
		if (this->activeBuyContracts[1] != NULL) {
			if (this->activeBuyContracts[1]->isComplete()) {
				this->activeBuyContracts[1] = NULL;
			}
		}
		this->generateContracts();
		clock.restart();
	}
}

void ContractManager::render(sf::RenderWindow * window, sf::View view)
{
	float buttonSize = view.getSize().x / 25.0f;
	float yOffset = view.getSize().y * 0.01f;
	float positionX = view.getCenter().x + (view.getSize().x* 0.5f) - buttonSize*3.1f;
	float positionY = view.getCenter().y - (view.getSize().y *0.5f) + buttonSize * 1.2f;
	int adjuster = 0;
	sf::Vector2f position = sf::Vector2f(positionX, positionY);
	sf::RectangleShape shape = sf::RectangleShape();
	shape.setSize(sf::Vector2f(buttonSize * 3, buttonSize * 1.5f));
	shape.setPosition(position);
	shape.setFillColor(sf::Color(255, 55, 0));

	if (this->activeBuyContracts[0] != NULL) {
		sf::Text text(this->activeBuyContracts[0]->getItem().getName(), this->font, view.getSize().x*0.05f);
		text.setScale(sf::Vector2f(0.2f, 0.2f));
		text.setPosition(shape.getPosition());
		window->draw(shape);
		window->draw(text);
		text.setString("Current: " + std::to_string(this->activeBuyContracts[0]->getCurrent()) 
			+ "/" + std::to_string(this->activeBuyContracts[0]->getItem().getAmount()));
		text.setPosition(shape.getPosition() + sf::Vector2f(0, view.getSize().y * 0.05f));
		window->draw(text);
		text.setString("$" + std::to_string(this->activeBuyContracts[0]->getCost()));
		text.setPosition(shape.getPosition() + sf::Vector2f(0, shape.getSize().y) - sf::Vector2f(0, shape.getSize().y*0.2f));
		window->draw(text);
		adjuster++;
	}

	if (this->activeBuyContracts[1] != NULL) {
		shape.setPosition(shape.getPosition() + sf::Vector2f(0,0 + (buttonSize*adjuster*1.7f)));
		sf::Text text(this->activeBuyContracts[1]->getItem().getName(), this->font, view.getSize().x*0.05f);
		text.setScale(sf::Vector2f(0.2f, 0.2f));
		text.setPosition(shape.getPosition());
		window->draw(shape);
		window->draw(text);
		text.setString("Current: " + std::to_string(this->activeBuyContracts[1]->getCurrent())
			+ "/" + std::to_string(this->activeBuyContracts[1]->getItem().getAmount()));
		text.setPosition(shape.getPosition() + sf::Vector2f(0, view.getSize().y * 0.05f));
		window->draw(text);
		text.setString("$" + std::to_string(this->activeBuyContracts[1]->getCost()));
		text.setPosition(shape.getPosition() + sf::Vector2f(0, shape.getSize().y) - sf::Vector2f(0, shape.getSize().y*0.2f));
		window->draw(text);
	}
	
}

int ContractManager::getSecondsLeft()
{
	return 20 - this->elasped.asSeconds();
}

void ContractManager::setActiveInput(int activeInput)
{
	this->activeInput = activeInput;
}

int ContractManager::getActiveInput()
{
	return this->activeInput;
}
