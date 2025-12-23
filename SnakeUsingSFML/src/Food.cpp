#include <cstdlib>
#include "../include/Food.hpp"

Food::Food(int gridW, int gridH) : _gridWidth(gridW), _gridHeight(gridH)
{
	respawn();
}

void Food::respawn()
{
	_position.x = rand() % _gridWidth;
	_position.y = rand() % _gridHeight;
}

const sf::Vector2i &Food::getPosition() const
{
	return _position;
}