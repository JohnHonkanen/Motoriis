#include <vector>
#include "ConstructNetwork.h"
#include "Pipe.h"
#include "OutputConstruct.h"

#include <iostream>
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
	void changeFlow(Construct *c1, Construct *c2);
private:
	sf::Clock clock;
	sf::Time elasped;
	CLinked* head;
	CLinked* tail;
	CLinked* lastChecked;

	Network *nHead;
	Network *nTail;

	int count;
};

