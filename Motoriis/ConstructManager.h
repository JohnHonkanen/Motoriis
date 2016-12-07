#include <vector>
#include "ConstructNetwork.h"
#include "Pipe.h"
#include "StorageConstruct.h"
#include "OutputConstruct.h"
#include "Machine.h"
#include "EndConstruct.h"
#pragma once

class Network
{
public:
	ConstructNetwork* network;
	Network* next;
	Network* prev;
};

class ConstructManager
{
public:
	ConstructManager();
	~ConstructManager();
	void addToList(Construct *construct);
	void addNetwork(Construct *base);
	void render(sf::RenderWindow *window, sf::View view);
	void update();
	void runNetwork(Network *current);
	Construct *checkPosition(sf::Vector2f position);
	CLinked* getLastChecked();
	void removeLink();
	void removeFromNetwork(Construct* construct);
	void changeFlow(Construct *c1, Construct *c2);
	void addStorageConstruct(sf::Vector2f position);

	void setConstruct(int construct);
	void buildConstruct(sf::Vector2f position, ItemManager manager);

	void setConstructing(bool value);
	bool getConstructing();

	sf::RectangleShape drawHelper(sf::Vector2f position);
private:
	void remove();
	sf::Clock clock;
	sf::Time elasped;
	CLinked* head;
	CLinked* tail;
	CLinked* lastChecked;

	Network *nHead;
	Network *nTail;

	int count;
	int construct = 1;
	bool isConstructing = false;
};

