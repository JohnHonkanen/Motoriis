#include "GameManager.h"
int main()
{
	const int windowHeight = 1600;
	const int windowWidth = 900;
	GameManager *game = new GameManager(windowHeight, windowWidth);
	game->run();

	return 0;
}