#pragma once
#include "Construct.h"
#include "ContractManager.h"
class EndConstruct :
	public Construct
{
public:
	EndConstruct();
	EndConstruct(sf::Vector2f position, ContractManager *contractManager, EconomyManager* economyManager);
	~EndConstruct();
	sf::ConvexShape draw();
	void calculatePointPosition();
	void transferItem();
	void render(sf::RenderWindow *window, sf::View view);
	bool addItem(Item *item);
private:
	ContractManager *contractManager;
	EconomyManager* economyManager;
};

