#pragma once
#include "Construct.h"
class EndConstruct :
	public Construct
{
public:
	EndConstruct();
	EndConstruct(sf::Vector2f position);
	~EndConstruct();
	sf::ConvexShape draw();
	void calculatePointPosition();
	void transferItem();
	void render(sf::RenderWindow *window, sf::View view);
	bool addItem(Item *item);
};

