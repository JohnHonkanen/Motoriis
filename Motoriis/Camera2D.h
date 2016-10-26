#pragma once
#include <SFML/Graphics.hpp>

class Camera2D
{
public:
	Camera2D(int x, int y);
	~Camera2D();
	Camera2D();
	sf::View getView();

	void getZoom(int zoomPercentage);
	sf::View getMiniMap();
	void moveCamera(float x, float y);
	sf::View view;
	sf::View mapCenter;

private:
	int x;
	int y;

	float speed = 3;
	sf::View minimap;



};

