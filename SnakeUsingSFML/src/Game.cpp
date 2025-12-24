#include "../include/Game.hpp"

Game::Game() : _window(sf::VideoMode(GRID_WIDTH * CELL_SIZE, GRID_HEIGHT * CELL_SIZE), "My Snake Game!"), _timer(0.0f), _scorePosition(sf::Vector2f(1, 1)), _food(GRID_WIDTH, GRID_HEIGHT), _score(0)
{
	_font.loadFromFile("font/OpenSans-Regular.ttf");
	_scoreText.setFont(_font);
	_scoreText.setCharacterSize(30);
	_scoreText.setFillColor(sf::Color(255, 255, 255));
	_scoreText.setOutlineThickness(2);
	_scoreText.setOutlineColor(sf::Color(0, 0, 0));
	_scoreText.setPosition(_scorePosition);
	_scoreText.setString("Score: ");
}

void Game::run()
{
	while (_window.isOpen())
	{
		handleEvents(); 
		update();
		render();
	}
}

void Game::handleEvents()
{
	// =========== INPUT ===========
	while (_window.pollEvent(_ev))
	{
		if (_ev.type == sf::Event::Closed)
			_window.close();

		if (_ev.type == sf::Event::KeyPressed)
		{
			if (_ev.key.code == sf::Keyboard::W)
				_snake.setDirection({ 0, -1 });
			
			if (_ev.key.code == sf::Keyboard::S)
				_snake.setDirection({ 0, 1 });
			
			if (_ev.key.code == sf::Keyboard::A)
				_snake.setDirection({ -1, 0 });
			
			if (_ev.key.code == sf::Keyboard::D)
				_snake.setDirection({ 1, 0 });
		}
	}
}

void Game::update()
{
	float dt = _gameClock.restart().asSeconds();
	_timer += dt;

	if (_timer >= MOVE_DELAY)
	{
		_timer = 0.0f;
		_snake.movement();

		// Gdy waz zje owoc
		if (_snake.getHead() == _food.getPosition())
		{
			_score++;
			_scoreText.setString("Score: " + std::to_string(_score));
			_snake.grow();
			_food.respawn();
		}

		// Kolizja weza z samym soba
		if (_snake.isSelfCollision())
		{
			_window.close();
		}

		// Kolizja weza z oknem
		if (_snake.isOutOfWindow(GRID_WIDTH, GRID_HEIGHT))
		{
			_window.close();
		}
	}
}

void Game::render()
{
	_window.clear();
	
	// Rysuj owoc
	sf::RectangleShape fruitShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	fruitShape.setFillColor(sf::Color(255, 0, 0));
	fruitShape.setPosition(_food.getPosition().x * CELL_SIZE, _food.getPosition().y * CELL_SIZE);
	_window.draw(fruitShape);

	// Rysuj glowe
	_snakeHeadShape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	_snakeHeadShape.setFillColor(sf::Color(0, 255, 0));
	_snakeHeadShape.setPosition(_snake.getHead().x * CELL_SIZE, _snake.getHead().y * CELL_SIZE);
	_window.draw(_snakeHeadShape);

	// Rysuj cialo
	sf::RectangleShape snakeBodyShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	snakeBodyShape.setFillColor(sf::Color(0, 255, 0));

	for (const auto& segment : _snake.getSegments())
	{
		snakeBodyShape.setPosition(segment.x * CELL_SIZE, segment.y * CELL_SIZE);
		_window.draw(snakeBodyShape);
	}

	_scoreText.setPosition(sf::Vector2f(_scorePosition.x * CELL_SIZE, _scorePosition.y * CELL_SIZE));
	_window.draw(_scoreText);

	_window.display();
}