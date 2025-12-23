#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include "include/Game.hpp"

int main()
{
	std::srand(static_cast<unsigned>(time(nullptr)));

	Game game;
	game.run();

	return 0;
}