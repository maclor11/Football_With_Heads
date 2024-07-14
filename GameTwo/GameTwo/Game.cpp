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
	p1->render(window, p1->getRect().left, 500);
	p2->render(window, p2->getRect().left + 200, 500);
}

Game::~Game()
{
	delete p1;
	delete p2;
}
