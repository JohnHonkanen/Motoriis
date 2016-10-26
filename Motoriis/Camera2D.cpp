#include "Camera2D.h"

Camera2D::Camera2D() {

}

Camera2D::Camera2D(int x, int y)
{
	this->x = x;
	this->y = y;
	this->view = sf::View(sf::Vector2f(x, y), sf::Vector2f(400, 225));
	this->minimap = sf::View(sf::Vector2f(x, y), sf::Vector2f(800, 450));
	this->minimap.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
}


Camera2D::~Camera2D()
{
}

sf::View Camera2D::getView() {
	return this->view;
}

void Camera2D::getZoom(int zoomPercentage) {
	this->view.zoom(zoomPercentage);
}

sf::View Camera2D::getMiniMap() {
	return this->minimap;
}

void Camera2D::moveCamera(float x, float y) {
	/*if (this->getView().getCenter().y - this->getView().getSize().y < 90 && y == -1) {
		y = 0;
	}

	if (this->getView().getCenter().y - this->getView().getSize().y > 360 && y == 1) {
		y = 0;
	}

	if (this->getView().getCenter().x < 755 && x == -1) {
		x = 0;
	}

	if (this->getView().getCenter().x > 851 && x == 1) {
		x = 0;
	}*/
	this->view.move(x * speed, y * speed);
}
