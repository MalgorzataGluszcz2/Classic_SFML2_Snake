#pragma once
#include <SFML/Graphics.hpp>

class Food
{
public:
	Food(int gridW, int gridH);
	void respawn();
	const sf::Vector2i &getPosition() const;

private:
	sf::Vector2i _position;
	int _gridWidth;
	int _gridHeight;
};