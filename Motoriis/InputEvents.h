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

