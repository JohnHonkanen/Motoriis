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
	if (tile == 0)
		shape.setFillColor(sf::Color(200, 200, 200, 255));
	else
		shape.setFillColor(sf::Color::Blue);
	return shape;
}

void Block::changeTile(int tile) {
	this->tile = tile;
}