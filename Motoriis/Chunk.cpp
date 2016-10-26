#include "Chunk.h"

Chunk::Chunk() {

}
Chunk::Chunk(int chunkHeight, int chunkWidth, int positionX, int positionY)
{
	this->chunkHeight = chunkHeight;
	this->chunkWidth = chunkWidth;
	this->chunkPositionX = positionX;
	this->chunkPositionY = positionY;
	this->init();

}

Chunk::~Chunk()
{
}

int Chunk::getX() {
	return this->chunkPositionX;
}

int Chunk::getY() {
	return this->chunkPositionY;
}
//Add our blocks
void Chunk::init() {
	for (int x = 0; x < this->chunkWidth; x++) {
		std::vector<Block*> yBlocks;
		for (int y = 0; y < this->chunkHeight; y++) {
			yBlocks.push_back(new Block(chunkPositionX + (10 * x),chunkPositionY + (10 * y), 0));
		}
		this->Blocks.push_back(yBlocks);
	}
}

void Chunk::render(sf::RenderWindow *window) {
	sf::View v = window->getView();
	float xPoint = v.getCenter().x - v.getSize().x / 2 -10;
	float maxXPoint = xPoint + v.getSize().x +10;
	float yPoint = v.getCenter().y - v.getSize().y / 2 -10;
	float maxYPoint = yPoint + v.getSize().y + 10;
	for (int x = (xPoint - chunkPositionX) / 10; x < (maxXPoint - chunkPositionX) / 10; x++) {
		for (int y = (yPoint - chunkPositionY) / 10; y < (maxYPoint - chunkPositionY) / 10; y++) {
			window->draw(this->Blocks.at(x).at(y)->draw());
		}
	}
}

void Chunk::checkBlockAt(sf::Vector2f position, int mouseEvent, int tile) {
	int xBlock = (position.x - this->chunkPositionX)/10;
	int yBlock = (position.y - this->chunkPositionY)/10;
	if (mouseEvent == 1) {
			Blocks.at(xBlock).at(yBlock)->changeTile(tile);	
	}
}

Chunk Chunk::getChunkAt(vector<Chunk> chunkList, sf::Vector2f position){
	vector<Chunk>::iterator it;
	int i = 0;

	for (it = chunkList.begin(); it < chunkList.end(); it++, i++) {
		if (position.x > chunkList.at(i).getX())
			if (position.y > chunkList.at(i).getY())
				return chunkList.at(i);
	}
	return Chunk();
}

