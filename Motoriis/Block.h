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
private:
	int x, y;
	int size;
	int tile;
};

