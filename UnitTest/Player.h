#pragma once
class Player
{
public:
	Player();
	~Player();

	void controlEvent(unsigned char key, static bool isKeyPressed);
};

