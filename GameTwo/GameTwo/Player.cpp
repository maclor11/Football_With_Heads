#include "Player.h"

Player::Player(const std::string fileName, const std::string playerName) : speed(300), verticalVelocity(0), name(playerName), gravity(.8)
{
	if (!playerAppearance.loadFromFile(fileName))
	{
		std::cout << "Loading player's texture failed" << '\n';
		system("pause");
	}
	this->player.setTexture(playerAppearance);
	rect = sf::FloatRect(50, 50, 100, 100);
}

void Player::setPosition(float x, float y)
{
	player.setPosition(x, y);
}

void Player::WSADmovement(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		rect.left -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		rect.left += speed * deltaTime;

	verticalVelocity += gravity;
	rect.top += verticalVelocity * deltaTime;

	if ((rect.top + rect.height) > 600)
		rect.top = 600 - rect.height;
}

void Player::ARROWSmovement(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		rect.left -= speed * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		rect.left += speed * deltaTime;

	verticalVelocity += gravity;
	rect.top += verticalVelocity * deltaTime;

	if ((rect.top + rect.height) > 600)
		rect.top = 600 - rect.height;
}

void Player::render(sf::RenderWindow& window, float x, float y)
{
	player.setPosition(x, y);
	player.setScale(rect.width / playerAppearance.getSize().x, rect.height / playerAppearance.getSize().y);
	window.draw(player);
}

sf::FloatRect Player::getRect()
{
	return rect;
}
