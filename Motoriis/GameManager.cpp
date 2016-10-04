#include "GameManager.h"

GameManager::GameManager(int windowHeight, int windowWidth)
{
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
}


GameManager::~GameManager()
{
}

bool GameManager::init() {
	int chunkSize = 50;
	this->player = new Player(this->windowHeight / 2, this->windowWidth / 2);
	this->chunks.push_back(Chunk(chunkSize, chunkSize, this->windowHeight / 2 - (chunkSize*10)/2, this->windowWidth / 2 - (chunkSize*10)/2));
	this->window = new sf::RenderWindow(sf::VideoMode(this->windowHeight, this->windowWidth), "Motoriss");
	this->window->setView(player->getView());

	if (!window)
		return false;
	return true;
}

void GameManager::run() {
	if (!init())
		throw "Could not initialize game";

	this->mainLoop();
}

void GameManager::processInputs() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		//Mouse Logic
		if (event.type == sf::Event::MouseMoved) {
			sf::Vector2i pixelPosition = InputEvents::mousePosition(window);
			this->mousePos = window->mapPixelToCoords(pixelPosition);
		}
		if (playerEvents.getMouseDrag()) {
			playerEvents.updateOverlay(mousePos);
		}
		if(event.type == sf::Event::MouseButtonPressed && InputEvents::mouseEvent() == 1)
		{
			playerEvents.setMouseDrag(true);
			playerEvents.setStartDrag(mousePos);
		}
		else if(event.type == sf::Event::MouseButtonReleased) {
			if (playerEvents.getOverlay().getSize().x > 0) {
				if (playerEvents.getOverlay().getSize().y > 0) {
					//X and Y positive
					for (int startX = playerEvents.getStartDrag().x; startX < mousePos.x + gridOffset; startX += snapGrid) {
						for (int startY = playerEvents.getStartDrag().y; startY < mousePos.y + gridOffset; startY += snapGrid) {
							//Update Chunks
							vector<Chunk>::iterator it;
							int chunk = 0;
							for (it = chunks.begin(); it < chunks.end(); it++, chunk++) {
								chunks.at(chunk).checkBlockAt(sf::Vector2f(startX, startY), 1);
							}
						}
					}
				}
				else {
					//X Positive and Y Negative
					for (int startX = playerEvents.getStartDrag().x; startX < mousePos.x; startX += snapGrid) {
						for (int startY = playerEvents.getStartDrag().y; startY > mousePos.y; startY -= snapGrid) {
							//Update Chunks
							vector<Chunk>::iterator it;
							int chunk = 0;
							for (it = chunks.begin(); it < chunks.end(); it++, chunk++) {
								chunks.at(chunk).checkBlockAt(sf::Vector2f(startX, startY), 1);
							}
						}
					}
				}
			}
			else {
				if (playerEvents.getOverlay().getSize().y > 0) {
					//X Negative and Y Positive
					for (int startX = playerEvents.getStartDrag().x; startX > mousePos.x; startX -= snapGrid) {
						for (int startY = playerEvents.getStartDrag().y; startY < mousePos.y; startY += snapGrid) {
							//Update Chunks
							vector<Chunk>::iterator it;
							int chunk = 0;
							for (it = chunks.begin(); it < chunks.end(); it++, chunk++) {
								chunks.at(chunk).checkBlockAt(sf::Vector2f(startX, startY), 1);
							}
						}
					}
				}
				else {
					//X and Y Negative
					for (int startX = playerEvents.getStartDrag().x; startX > mousePos.x; startX -= snapGrid) {
						for (int startY = playerEvents.getStartDrag().y; startY > mousePos.y; startY -= snapGrid) {
							//Update Chunks
							vector<Chunk>::iterator it;
							int chunk = 0;
							for (it = chunks.begin(); it < chunks.end(); it++, chunk++) {
								chunks.at(chunk).checkBlockAt(sf::Vector2f(startX, startY), 1);
							}
						}
					}
				}
			}
			playerEvents.setMouseDrag(false);
			playerEvents.resetOverlay();
		}
		//EndOfMouse
	}
}

void GameManager::update() {
}

void GameManager::mainLoop() {
	while (window->isOpen()) {
		this->processInputs();
		this->update();
		this->render();
	}
}

void GameManager::render() {

	sf::RectangleShape shape(sf::Vector2f(3, 3));
	shape.setPosition(mousePos.x-1, mousePos.y-1);
	window->clear();
	//Render our chunks
	vector<Chunk>::iterator it;
	int chunk = 0;
	for (it = chunks.begin(); it < chunks.end(); it++, chunk++) {
		chunks.at(chunk).render(window);
	}
	if (playerEvents.getMouseDrag()) {
		window->draw(playerEvents.getOverlay());
	}
	//End of Render Chunks
	window->draw(shape);
	window->display();
}
