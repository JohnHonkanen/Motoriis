#include <SFML/Graphics.hpp>
#include "InputEvents.h"
#include "Player.h"
#include "Chunk.h"
#include "BuildingManager.h"
#include <vector>
#include <iostream>
#include "Camera2D.h"

using namespace std;
#pragma once
class GameManager
{
public:
	GameManager(int windowHeight, int windowWidth);
	~GameManager();
	void run();
private:
	bool init();
	void render();
	void update();
	void mainLoop();
	void processInputs();

	sf::RenderWindow *window;
	sf::View view;
	sf::Vector2f mousePos;

	Player *player;
	Camera2D camera2D;
	vector<Chunk> chunks;
	InputEvents playerEvents;
	BuildingManager buildingManager;

	int windowHeight;
	int windowWidth;

	int snapGrid = 10;
	int gridOffset = 0;

	int vert = 0;
	int hori = 0;

	bool isPanning = false;
	bool resetMovement = false;
};

