#include "SFML\Graphics.hpp"
#include <vector>
#pragma once

using namespace std;

class Block
{
public:
	Block(int x, int y, int tile);
	~Block();
	sf::RectangleShape draw();
	void changeTile(int tile);
	bool isOccupied() { return this->occupied; };
	void setOccupied(bool o) { this->occupied = o; };
private:
	int x, y;
	int size;
	int tile;
	bool occupied = false;
};

