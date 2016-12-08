#pragma once
#include "ButtonObjects.h"
#include "Construct.h"
class ConstructButton : public ButtonObjects
{
public:
	ConstructButton();
	ConstructButton(float xOffsetMultiplier);
	ConstructButton(float xOffsetMultiplier, string texture);
	~ConstructButton();
	void draw(sf::RenderWindow *window, sf::View view);

	void update();
	void setConstruct(int id);
	int getConstruct();
private:
	void createRect(sf::View view);
	int constructId;
};

