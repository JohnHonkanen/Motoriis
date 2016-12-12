#include "EndConstruct.h"



EndConstruct::EndConstruct()
{
}

EndConstruct::EndConstruct(sf::Vector2f position, ContractManager *contractManager, EconomyManager* economyManager)
{
	this->position = position;
	this->texture.loadFromFile("Texture/shipping.jpg");
	this->contractManager = contractManager;
	this->economyManager = economyManager;
	this->main = this;
	this->price = 30;
}


EndConstruct::~EndConstruct()
{
}

sf::ConvexShape EndConstruct::draw()
{
	return sf::ConvexShape();
}

void EndConstruct::calculatePointPosition()
{
	//DO Nothing
}

void EndConstruct::transferItem()
{
	//Do Nothing
}

void EndConstruct::render(sf::RenderWindow * window, sf::View view)
{
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(10,10));
	shape.setPosition(this->position);
	shape.setTexture(&this->texture, false);
	window->draw(shape);
}

bool EndConstruct::addItem(Item * item)
{
	if (this->contractManager->activeBuyContracts[0] != NULL && !this->contractManager->activeBuyContracts[0]->isComplete()) {
		if (item->getUID() == this->contractManager->activeBuyContracts[0]->getItem().getUID()) {
			dynamic_cast<BuyContracts*> (this->contractManager->activeBuyContracts[0])->addToCurrent(1);
			if (this->contractManager->activeBuyContracts[0]->getItem().getAmount()
				== dynamic_cast<BuyContracts*> (this->contractManager->activeBuyContracts[0])->getCurrent()) {
				dynamic_cast<BuyContracts*> (this->contractManager->activeBuyContracts[0])->fufill(this->economyManager);
			}
			return true;
		}

	} else if(this->contractManager->activeBuyContracts[1] != NULL && !this->contractManager->activeBuyContracts[1]->isComplete()){
		if (item->getUID() == this->contractManager->activeBuyContracts[1]->getItem().getUID()) {
			dynamic_cast<BuyContracts*> (this->contractManager->activeBuyContracts[1])->addToCurrent(1);
			if (this->contractManager->activeBuyContracts[1]->getItem().getAmount()
				== dynamic_cast<BuyContracts*> (this->contractManager->activeBuyContracts[1])->getCurrent()) {
				dynamic_cast<BuyContracts*> (this->contractManager->activeBuyContracts[1])->fufill(this->economyManager);
			}
			return true;
		}
	}
	if (item == NULL)
		return true;

	return false;
}
