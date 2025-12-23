#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Snake
{
public:
	Snake();
	void setDirection(sf::Vector2i dir);
	void movement();
	void grow();

	const sf::Vector2i &getHead() const;
	const std::vector<sf::Vector2i>& getSegments() const;

private:
	sf::Vector2i _head;
	std::vector<sf::Vector2i> _segments;
	sf::Vector2i _direction;
	sf::Vector2i _previousHead;
};