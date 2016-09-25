#include <SFML/Graphics.hpp>
#include "CsvParser.h"

int main()
{
	CsvParser parser;
	string filename = "ItemDatabase.csv";
	vector<string> contents;
	parser.open(filename);
	contents = parser.parseFile();
	cout << contents.at(0);
	parser.close();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}