#pragma once
#include "ButtonObjects.h"
#include "Construct.h"
class ConstructButton : public ButtonObjects
{
public:
	ConstructButton();
	ConstructButton(float xOffsetMultiplier);
	~ConstructButton();
	void draw(sf::RenderWindow *window, sf::View view);

	void update();
	void setConstruct(int id);
private:
	void createRect(sf::View view);
	int constructId;
};

