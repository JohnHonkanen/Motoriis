#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#pragma once
class InputEvents
{
public:
	InputEvents();
	~InputEvents();
	static int mouseEvent();
	static sf::Vector2i mousePosition(sf::RenderWindow *window);

	bool getMouseDrag();
	void setMouseDrag(bool status);

	sf::Vector2f getStartDrag();
	void setStartDrag(sf::Vector2f position);
	sf::RectangleShape getOverlay();
	void updateOverlay(sf::Vector2f currentPosition);
	void resetOverlay();
private:
	bool mouseDrag = false;
	sf::Vector2f startDrag;
	sf::RectangleShape overlay;
};

#pragma once
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class InputEvents
{
public:
	InputEvents();
	~InputEvents();

	void eventControler(unsigned int keyInput);

	sf::Event event;
	sf::Window window;
};

