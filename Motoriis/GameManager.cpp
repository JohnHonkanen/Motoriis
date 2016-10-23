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
	this->camera2D = Camera2D(this->windowHeight / 2, this->windowWidth / 2);
	this->window->setView(view);


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
		//Update Drag Overlay
		if (playerEvents.getMouseDrag()) {
			playerEvents.updateOverlay(mousePos);
		}
		//Mouse Click and Release Event
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

		//Keyboard
		if (event.type == sf::Event::KeyPressed) {
			playerEvents.keyboardEvent(event.key.code);

			std::cout << event.key.code << endl;

			//Vert
			if (event.key.code == sf::Keyboard::W) {
				vert = -1;
			}
			else if (event.key.code == sf::Keyboard::S) {
				vert = 1;
			}

			//Hori
			if (event.key.code == sf::Keyboard::A) {
				hori = -1;
			}
			else if (event.key.code == sf::Keyboard::D) {
				hori = 1;
			}
		}

		//do try diagonal
		else if (event.type == sf::Event::KeyReleased){
			
			if (event.key.code == sf::Keyboard::W) {
				vert = 0;
			}
			else if (event.key.code == sf::Keyboard::S) {
				vert = 0;
			}

			if (event.key.code == sf::Keyboard::A) {
				hori = 0;
			}
			else if (event.key.code == sf::Keyboard::D) {
				hori = 0;
			}
		}
		camera2D.moveCamera(hori, vert);
		//EndOfKeyboard

		//Mouse Wheel Start
		float zoomX = 40;
		float zoomY = zoomX/16*9;

		if (event.type == sf::Event::MouseWheelMoved) {
			// Zoom Out
			if (event.mouseWheel.delta < 0 && camera2D.view.getSize().x < 450) {
					camera2D.view.setSize(camera2D.view.getSize().x + zoomX, camera2D.view.getSize().y + zoomY);
			}
			//Zoom In
			else if (event.mouseWheel.delta > 0 && camera2D.view.getSize().x > 100){

					camera2D.view.setSize(camera2D.view.getSize().x - zoomX, camera2D.view.getSize().y - zoomY);
			}
			
			//Zoom to mouse position

			if (camera2D.view.getSize().x < 450 && camera2D.view.getSize().x > 100) {
				sf::Vector2f currentCenter = camera2D.view.getCenter();
				sf::Vector2f moveToPos = currentCenter - mousePos;

				int interpolate = 5; //Linear cause bad at maths. 

				camera2D.view.setCenter(currentCenter.x - moveToPos.x / interpolate, currentCenter.y - moveToPos.y / interpolate);
			}	
		}
		//Mouse Wheel End
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

	sf::RectangleShape shape(sf::Vector2f(10, 10));
	shape.setPosition(InputEvents::roundMousePos(mousePos.x, mousePos.y));
	window->setView(this->camera2D.view);
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
