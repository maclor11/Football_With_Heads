#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Player 
{
	sf::Texture playerAppearance;
	sf::Sprite player;
	std::string name;
	float speed;
	float verticalVelocity;
	float jumpVelocity;
	float gravity;
	sf::FloatRect rect;
	bool isOnTheFloor = 1;
public:
	Player(const std::string fileName, const std::string playerName, sf::Vector2f pos);
	void WSADmovement(float deltaTime);
	void ARROWSmovement(float deltaTime);
	void setPosition(float x, float y);
	void render(sf::RenderWindow& window);
};