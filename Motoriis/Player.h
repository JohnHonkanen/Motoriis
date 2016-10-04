#include <SFML/Graphics.hpp>
#pragma once
class Player
{
public:
	Player(int x, int y);
	~Player();
	sf::View getView();
private:
	int x, y;
	sf::View playerView;
};

