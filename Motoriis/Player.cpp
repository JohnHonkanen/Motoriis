#include "Player.h"

Player::Player(int x, int y)
{
	this->x = x;
	this->y = y;
	this->playerView = sf::View(sf::Vector2f(x, y), sf::Vector2f(400, 225));
}


Player::~Player()
{
}

sf::View Player::getView() {
	return this->playerView;
}
