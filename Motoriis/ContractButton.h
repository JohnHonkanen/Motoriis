#pragma once
#include "ButtonObjects.h"
#include "Contracts.h"
class ContractButton :
	public ButtonObjects
{
public:
	ContractButton(Contracts *contract, int x, int y);
	~ContractButton();
	void draw(sf::RenderWindow *window, sf::View view);
	void update();
	Contracts *getContract();
private:
	void createRect(sf::View view);
	Contracts *contract;
	int xPos, yPos;
	sf::Font font;
};

