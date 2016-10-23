#pragma once

#include "Building.h"

class LogisticNetwork
{
public:
	LogisticNetwork();


	~LogisticNetwork();

	void renderItemsToGUI();
	void renderLogisticToMap();
	void updateNetwork();

	void addBuilding(Building building);
	
private:

	vector<Building> connectedBuildings;
	
};

//store the items in building storage.
//create an array of items in the building storage.

//transfer items to another building storage (move to end of pipe).
//transfer item based on speed which is based on tickrate. 

//identify buildings
//identify input and output and if no output, doesn't move items.
//identify if in transit.