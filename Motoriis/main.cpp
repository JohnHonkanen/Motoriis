#include <SFML/Graphics.hpp>
#include "CsvParser.h"
#include "Player.h"
#include "InputEvents.h"
#include <iostream>

int main()
{
	CsvParser parser;
	InputEvents inputEvent;
	InputEvents windowStatus;
	string filename = "ItemDatabase.csv";
	vector<string> contents;
	parser.open(filename);
	contents = parser.parseFile();
	cout << contents.at(0);
	parser.close();

	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed) {
				inputEvent.eventControler(event.key.code);
			}


			if (event.type == sf::Event::Closed)
				window.close();

		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}