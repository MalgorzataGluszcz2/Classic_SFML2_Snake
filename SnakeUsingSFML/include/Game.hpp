#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Food.hpp"

class Game
{
public:
	Game();
	void run();

private:
	void handleEvents();
	void update();
	void render();

private:
	sf::RenderWindow _window;

	// =========== CZAS ===========
	sf::Clock _gameClock;
	float _timer;

	// ======= KONFIGURACJA SIATKI =======
	static const int GRID_WIDTH = 40;
	static const int GRID_HEIGHT = 40;
	static const int CELL_SIZE = 20;

	const float MOVE_DELAY = 0.12f;

	// ========= EVENT =========
	sf::Event _ev;

	// ========= PUNKTY =========
	sf::Font _font;
	sf::Text _scoreText;
	int _score;
	sf::Vector2f _scorePosition;

	// Ksztalt glowy weza
	sf::RectangleShape _snakeHeadShape;

	Snake _snake;
	Food _food;
};