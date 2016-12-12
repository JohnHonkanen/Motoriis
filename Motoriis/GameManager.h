#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "InputEvents.h"
#include "Player.h"
#include "Chunk.h"
#include "ConstructManager.h"
#include "MenuManager.h"
#include "ItemManager.h"
#include "EconomyManager.h"
#include "ContractManager.h"
#include "Camera2D.h"

#pragma once
class GameManager
{
public:
	GameManager(int windowHeight, int windowWidth);
	~GameManager();
	void run();
	int closeState = 0;
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
	ConstructManager constructManager;
	ItemManager itemManager;
	EconomyManager economyManager;
	ContractManager contractManager;
	MenuManager menuManager;

	int windowHeight;
	int windowWidth;

	int snapGrid = 10;
	int gridOffset = 0;

	int vert = 0;
	int hori = 0;

	bool isPanning = false;
	bool resetMovement = false;
	bool onButton = false;

	sf::Music mainMusic;
	sf::RectangleShape logoRect;
	sf::Texture logo;
	sf::Font font;
	bool start = false;
};

