#include "BuildingManager.h"



BuildingManager::BuildingManager()
{
}


BuildingManager::~BuildingManager()
{
}

/*
Populate our building list with a CSV buildingList
@param buildingList List of CSV string
*/

void BuildingManager::populateBuildings(vector<string> buildingList) {
	vector<string>::iterator it;
	int i = 0;
	for (it = buildingList.begin(); it < buildingList.end(); it++, i++) {
		this->buildings.push_back(Building::convertToBuilding(buildingList.at(i)));
	}
}
