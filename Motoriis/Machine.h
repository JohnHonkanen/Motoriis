#pragma once
#include "Construct.h"
#include "BaseInput.h"
#include <iostream>
class Machine :
	public Construct
{
public:
	Machine();
	~Machine();
	Machine(sf::Vector2f position);
	Machine(sf::Vector2f position, ItemManager manager);
	static Machine* makeMachine(sf::Vector2f position, ItemManager manager);
	sf::ConvexShape draw();
	void calculatePointPosition();
	void transferItem();
	void render(sf::RenderWindow *window, sf::View view);
	void handleBaseInputs();
	int remove();
	Construct* input1;
	Construct* input2;
	Construct* output;
private:
	ItemManager manager;
};

