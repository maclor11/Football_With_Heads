#include "Player.h"

Player::Player(const std::string fileName, const std::string playerName, sf::Vector2f pos = sf::Vector2f(50,500)) : speed(300), verticalVelocity(0), name(playerName), gravity(20), jumpVelocity(-450)
{

	if (!playerAppearance.loadFromFile(fileName))
	{
		std::cout << "Loading player's texture failed" << '\n';
		system("pause");
	}
	this->player.setTexture(playerAppearance);
	rect = sf::FloatRect(pos.x, pos.y, 100, 100);
}

void Player::setPosition(float x, float y)
{
	rect.left = x;
	rect.top = y;
	verticalVelocity = 0.0f;
}

void Player::WSADmovement(float deltaTime) // dorobic ze kiedy dotyka ziemi moze dopiero znowu skoczyc
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		rect.left -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		rect.left += speed * deltaTime;

	verticalVelocity += gravity;
	rect.top += verticalVelocity * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isOnTheFloor)
	{
		verticalVelocity = jumpVelocity;
		rect.top -= 2 * verticalVelocity * deltaTime;
	}
	

	verticalVelocity += gravity * deltaTime;
	rect.top += verticalVelocity * deltaTime;

	if ((rect.top + rect.height) > 600)
	{
		rect.top = 600 - rect.height;
		isOnTheFloor = 1;
	}
	else
	{
		isOnTheFloor = 0;
	}

	if ((rect.left + rect.width) > 800)
		rect.left = 800 - rect.width;
	else if ((rect.left + rect.width) < rect.width)
		rect.left = 0;
}

void Player::ARROWSmovement(float deltaTime) // dorobic ze kiedy dotyka ziemi moze dopiero znowu skoczyc
{
	// poruszanie sie w lewo i prawo
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		rect.left -= speed * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		rect.left += speed * deltaTime;

	//grawitacja
	verticalVelocity += gravity;
	rect.top += verticalVelocity * deltaTime;

	//skakanie
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isOnTheFloor)
	{
		verticalVelocity = jumpVelocity;
		rect.top -= 2 * verticalVelocity * deltaTime;
	}
	
	verticalVelocity += gravity * deltaTime;
	rect.top += verticalVelocity * deltaTime;
	
	//ograniczenie poruszania siê w pionie
	if ((rect.top + rect.height) > 600)
	{
		rect.top = 600 - rect.height;
		isOnTheFloor = 1;
	}
	else
	{
		isOnTheFloor = 0;
	}

	//ograniczenie poruszania sie w poziomie
	if ((rect.left + rect.width) > 800)
		rect.left = 800 - rect.width;
	else if ((rect.left + rect.width) < rect.width)
		rect.left = 0 ;
}

void Player::render(sf::RenderWindow& window)
{
	player.setPosition(rect.left,rect.top);
	player.setScale(rect.width / playerAppearance.getSize().x, rect.height / playerAppearance.getSize().y);
	window.draw(player);
}


