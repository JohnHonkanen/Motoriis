#include "Block.h"
#include "SFML\Graphics.hpp"
#pragma once
class Chunk
{
public:
	Chunk();
	Chunk(int chunkHeight, int chunkWidth, int positionX, int positionY); // max 255
	~Chunk();
	void render(sf::RenderWindow *window);
	void checkBlockAt(sf::Vector2f position, int mouseEvent, int tile);
	static Chunk getChunkAt(vector<Chunk> chunkList, sf::Vector2f position);
	int getX();
	int getY();
private:
	void init();

	std::vector<std::vector<Block*>> Blocks;
	int chunkHeight;
	int chunkWidth;
	int chunkPositionX;
	int chunkPositionY;
};

