#include "LogisticNetwork.h"
#include "LogisticSystem.h"


LogisticNetwork::LogisticNetwork()
{

}


LogisticNetwork::~LogisticNetwork()
{
}

void LogisticNetwork::updateNetwork() {
	

}


void LogisticNetwork::addBuilding(Building building) {

	this->connectedBuildings.push_back(building);

}

//store the items in building storage.
//create an array of items in the building storage.

//transfer items to another building storage (move to end of pipe).
//transfer item based on speed which is based on tickrate. 

//identify buildings
//identify input and output and if no output, doesn't move items.
//identify if in transit.