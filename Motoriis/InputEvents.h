#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "Player.h"

#pragma once
class InputEvents
{
public:
	InputEvents();
	~InputEvents();
	static int mouseEvent();
	static sf::Vector2i mousePosition(sf::RenderWindow *window);
	static sf::Vector2f roundMousePos(int x, int y);

	bool getMouseDrag();
	
	sf::Vector2f getStartDrag();
	sf::RectangleShape getOverlay();

	void setMouseHeld(bool status) { this->mouseHeld = status; };
	bool getMouseHeld() { return this->mouseHeld; };
	void setMouseDrag(bool status);
	void setStartDrag(sf::Vector2f position);
	void updateOverlay(sf::Vector2f currentPosition);
	void resetOverlay();
	void keyboardEvent(unsigned int keyInput);


private:
	bool mouseHeld = false;
	bool mouseDrag = false;

	sf::Vector2f startDrag;
	sf::RectangleShape overlay;
};


