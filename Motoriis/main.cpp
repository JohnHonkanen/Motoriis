/*
	Motoriss Tech Demo v0.02
	Globobyte Studios

	Module - Games Project (COMP08080)
	B00291253 - John Honkanen
	B00294272 - Lars A Palm
*/

#include "GameManager.h"
int main()
{
	const int windowHeight = 1600;
	const int windowWidth = 900;
	int closeState;
	do{
		closeState = 0;
		GameManager *game = new GameManager(windowHeight, windowWidth);
		game->run();
		closeState = game->closeState;
		delete game;
	} while (closeState == 1);
	

	return 0;
}