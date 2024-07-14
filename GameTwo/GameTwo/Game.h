#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
	sf::RenderWindow& window;
	Player* p1;
	Player* p2;
public:
	Game(sf::RenderWindow& window);
	void AddPlayers(Player* player1, Player* player2);
	void update(float deltaTime);
	void renderGame();
	~Game();
};