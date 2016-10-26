#include "SFML\Graphics.hpp"
#include <vector>

#include "Building.h"
#pragma once

using namespace std;

class Block
{
public:
	Block(int x, int y, int tile);
	~Block();
	sf::RectangleShape draw();
	void changeTile(int tile, Building building);
	int getTile() { return this->tile; };
	bool isOccupied() { return this->occupied; };
	void setOccupied(bool o) { this->occupied = o; };
	sf::Vector2f getCoords() { return sf::Vector2f(this->x, this->y); };
private:
	int x, y;
	int size;
	int tile;
	bool occupied = false;
	Building building;
};

