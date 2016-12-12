#include "GameManager.h"

GameManager::GameManager(int windowHeight, int windowWidth)
{
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->mainMusic.openFromFile("Sounds/bg_main.wav");
	this->logo.loadFromFile("Texture/logo.png");
	this->font.loadFromFile("Fonts/Bungee-Regular.ttf");
}


GameManager::~GameManager()
{
}

bool GameManager::init() {
	this->mainMusic.setLoop(true);
	this->mainMusic.play();
	srand(time(NULL)); // SET RANDOM
	int chunkSize = 150;
	this->player = new Player(this->windowHeight / 2, this->windowWidth / 2);
	this->chunks.push_back(Chunk(chunkSize, chunkSize, this->windowHeight / 2 - (chunkSize*10)/2, this->windowWidth / 2 - (chunkSize*10)/2));
	this->window = new sf::RenderWindow(sf::VideoMode(this->windowHeight, this->windowWidth), "Motoriss");
	this->camera2D = Camera2D(this->windowHeight / 2, this->windowWidth / 2);
	this->window->setView(view);
	
	Construct* outputBlue = new OutputConstruct(InputEvents::roundMousePos(800, 400));
	Construct* outputMilk = new OutputConstruct(InputEvents::roundMousePos(800, 460));
	this->constructManager.addToList(outputBlue);
	this->constructManager.addToList(outputMilk);
	this->constructManager.addNetwork(outputBlue);
	this->constructManager.addNetwork(outputMilk);
	Construct *inputs[2] = { outputBlue, outputMilk };
	this->contractManager = ContractManager(&itemManager, &economyManager, inputs);
	this->menuManager = MenuManager(&constructManager, &contractManager, &economyManager, inputs);
	this->constructManager.addContractManager(&this->contractManager);
	this->constructManager.addEconomyManager(&this->economyManager);
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
		
		sf::Vector2i pixelPosition = InputEvents::mousePosition(window);
		this->mousePos = window->mapPixelToCoords(pixelPosition);
		sf::Vector2f roundedPos = InputEvents::roundMousePos(mousePos.x, mousePos.y);

		//Update Drag Overlay
		if (playerEvents.getMouseDrag()) {
			playerEvents.updateOverlay(mousePos);
		}
		//Normal Construction
		if (playerEvents.getMouseHeld()) {
			if (!this->start)
				this->start = true;

			if (this->menuManager.intersectsButton(sf::Vector2f(mousePos.x, mousePos.y))) {
				this->menuManager.getFound()->handleClicked();
			} else{
				if (this->constructManager.checkPosition(roundedPos) == NULL) {
					this->constructManager.buildConstruct(roundedPos, this->itemManager);
				}
			}

		}
		else if (playerEvents.getMouseRightHeld()) {
			if (this->constructManager.checkPosition(roundedPos) != NULL) {
				this->constructManager.removeLink();
			}
		}
		//Mouse Click and Release Event
		if(event.type == sf::Event::MouseButtonPressed && InputEvents::mouseEvent() == 1)
		{
			playerEvents.setMouseHeld(true);
		}
		else if(event.type == sf::Event::MouseButtonReleased) {
			playerEvents.setMouseHeld(false);
			playerEvents.setMouseDrag(false);
			playerEvents.resetOverlay();
		}

		//Mouse Click and Release Event
		if (event.type == sf::Event::MouseButtonPressed && InputEvents::mouseEvent() == 2)
		{
			playerEvents.setMouseRightHeld(true);
		}
		else if (event.type == sf::Event::MouseButtonReleased) {
			playerEvents.setMouseRightHeld(false);
		}
		//EndOfMouse

		//Keyboard
		if (event.type == sf::Event::KeyPressed) {
			playerEvents.keyboardEvent(event.key.code);
			
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
			//Constructing...
			if (event.key.code == sf::Keyboard::Num1) {
				if (this->contractManager.getShowMenu()) {
					this->contractManager.setActiveInput(0);//TOP
				}else{
					this->constructManager.setConstruct(1);
				}
				
			}
			else if (event.key.code == sf::Keyboard::Num2) {
				if (this->contractManager.getShowMenu()) {
					this->contractManager.setActiveInput(1);//BOTTOM
				}
				else {
					this->constructManager.setConstruct(2);
				}
			}
			else if (event.key.code == sf::Keyboard::Num3)
				this->constructManager.setConstruct(3);
			else if (event.key.code == sf::Keyboard::Num4)
				this->constructManager.setConstruct(4);

			if (event.key.code == sf::Keyboard::B) {
				if (this->constructManager.getConstructing())
					this->constructManager.setConstructing(false);
				else
					this->constructManager.setConstructing(true);
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
		//EndOfKeyboard

		if (!this->menuManager.intersectsButton(sf::Vector2f(mousePos.x, mousePos.y))) {
			//Pan Mouse Start
			if (this->mousePos.x < camera2D.getView().getCenter().x - (camera2D.getView().getSize().x / 2) + 10) {
				hori = -1;
				isPanning = true;
				resetMovement = false;
			}
			else if (this->mousePos.x > camera2D.getView().getCenter().x + (camera2D.getView().getSize().x / 2) - 10) {
				hori = 1;
				isPanning = true;
				resetMovement = false;
			}
			else {
				isPanning = false;
			}

			if (this->mousePos.y < camera2D.getView().getCenter().y - (camera2D.getView().getSize().y / 2) + 10) {
				vert = -1;
				isPanning = true;
				resetMovement = false;
			}
			else if (this->mousePos.y > camera2D.getView().getCenter().y + (camera2D.getView().getSize().y / 2) - 10) {
				vert = 1;
				isPanning = true;
				resetMovement = false;
			}
			else {
				isPanning = false;
			}
		}
		

		if (!resetMovement && !isPanning) {
			resetMovement = true;
			hori = 0;
			vert = 0;
		}
		//Pan Mouse End

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
	if (this->start) {
		camera2D.moveCamera(hori, vert);
		this->menuManager.update();
		this->constructManager.update();
		this->contractManager.update();
		if (this->economyManager.getMoney() < -2000) {
			this->window->close();
			this->closeState = 1;
			return;
		}
			
	}
	
}

void GameManager::mainLoop() {
	window->setFramerateLimit(30);
	while (window->isOpen()) {
		this->processInputs();
		this->update();
		this->render();
	}
}

void GameManager::render() {


	window->setView(this->camera2D.view);
	window->clear();
	if (this->start) {
		//Render our chunks
		vector<Chunk>::iterator it;
		int chunk = 0;
		for (it = chunks.begin(); it < chunks.end(); it++, chunk++) {
			chunks.at(chunk).render(window);
		}
		if (playerEvents.getMouseDrag()) {
			window->draw(playerEvents.getOverlay());
		}
		this->constructManager.render(window, camera2D.getView());
		if (this->constructManager.getConstructing())
			window->draw(this->constructManager.drawHelper(InputEvents::roundMousePos(mousePos.x, mousePos.y)));
		this->contractManager.render(window, camera2D.getView());
		this->menuManager.render(window, camera2D.getView());
		this->economyManager.render(window, camera2D.getView());
	}
	else {
		sf::RectangleShape shape;
		shape.setPosition(camera2D.getView().getCenter() - sf::Vector2f(camera2D.getView().getSize().x*0.2, camera2D.getView().getSize().y*0.2f));
		shape.setTexture(&this->logo, false);
		shape.setSize(sf::Vector2f(camera2D.getView().getSize().x*0.4, camera2D.getView().getSize().y*0.1));
		window->draw(shape);
		sf::Text text("Click anywhere to Start!", this->font, view.getSize().x*0.05f);
		text.setScale(sf::Vector2f(0.2f, 0.2f));
		text.setPosition(camera2D.getView().getCenter() - sf::Vector2f(camera2D.getView().getSize().x * 0.19f, 0));
		window->draw(text);
		text.setString("Developed by Globobyte Studios, All Rights Reserved © 2016");
		text.setPosition(camera2D.getView().getCenter() + sf::Vector2f(-camera2D.getView().getSize().x * 0.27f, camera2D.getView().getSize().y*0.4f));
		text.setCharacterSize(view.getSize().x*0.03f);
		window->draw(text);
		text.setString("Tech Demo");
		text.setPosition(camera2D.getView().getCenter() + sf::Vector2f(camera2D.getView().getSize().x * 0.16f, -camera2D.getView().getSize().y*0.09f));
		text.setCharacterSize(view.getSize().x*0.02f);
		window->draw(text);
	}
	
	
	//End of Render Chunks
	//Render GUI
	window->display();
}
