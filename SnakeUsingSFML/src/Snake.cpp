#include "../include/Snake.hpp"

Snake::Snake()
{
	_head = { 15, 15 };
	_direction = { 1, 0 };
}

void Snake::setDirection(sf::Vector2i dir)
{
	// Waz sie nie cofa do tylu
	if (dir + _direction != sf::Vector2i(0, 0))
	{
		_direction = dir;
	}
}

void Snake::movement()
{
	_previousHead = _head;
	_head += _direction;

	for (int i = static_cast<int>(_segments.size()) - 1; i > 0; --i)
	{
		_segments[i] = _segments[i - 1];
	}

	if (!_segments.empty())
	{
		_segments[0] = _previousHead;
	}
}

void Snake::grow()
{
	if (_segments.empty())
		_segments.push_back(_previousHead); // Pierwszy segment
	else
		_segments.push_back(_segments.back()); // Kopiujemy ogon
}

const sf::Vector2i& Snake::getHead() const
{
	return _head;
}

const std::vector<sf::Vector2i>& Snake::getSegments() const
{
	return _segments;
}

bool Snake::isSelfCollision() const
{
	for (const auto &body : _segments)
	{
		if (body == _head)
			return true;
	}

	return false;
}

bool Snake::isOutOfWindow(int gridW, int gridH) const
{
	return _head.x < 0 || _head.x >= gridW ||
			  _head.y < 0 || _head.y >= gridH;
}