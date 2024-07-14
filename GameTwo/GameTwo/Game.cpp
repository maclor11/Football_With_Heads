#include "Game.h"

Game::Game(sf::RenderWindow& window) : window(window)
{
	p1 = nullptr;
	p2 = nullptr;
}

void Game::AddPlayers(Player* player1, Player* player2)
{
	p1 = player1;
	p2 = player2;
}

void Game::update(float deltaTime)
{
	p1->ARROWSmovement(deltaTime);
	p2->WSADmovement(deltaTime);
}

void Game::renderGame()
{
	/*p1->setPosition(200, 100);
	p2->setPosition(500, 100);*/
	p1->render(window);
	p2->render(window);
}

Game::~Game()
{
	delete p1;
	delete p2;
}
