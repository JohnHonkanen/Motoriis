#include "Block.h"

Block::Block(int x, int y, int tile)
{
	this->x = x;
	this->y = y;
	this->tile = tile;
	this->size = 10;
}


Block::~Block()
{
}

sf::RectangleShape Block::draw() {
	sf::RectangleShape shape(sf::Vector2f(this->size, this->size));
	shape.setPosition(x, y);
	shape.setOutlineThickness(0.3);
	shape.setOutlineColor(sf::Color::Color(0, 0, 0,100));
	
	shape.setFillColor(sf::Color(100, 100, 100, 255));
	
	return shape;
}

