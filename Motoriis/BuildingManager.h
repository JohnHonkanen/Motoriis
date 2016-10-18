#pragma once
#include "Building.h"
#include <vector>

class BuildingManager
{
public:
	BuildingManager();
	~BuildingManager();
	void populateBuildings(vector<string> BuildingList);
private:
	vector<Building> buildings;
};

