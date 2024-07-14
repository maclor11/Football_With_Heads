#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GAMETWO", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	Game g(window);
	g.AddPlayers(new Player("ronaldo7.png", "CRISTIANO", sf::Vector2f(550,500)), new Player("messi10.png", "LIONEL", sf::Vector2f(50, 500)));
	sf::Clock clk;
	clk.restart();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}
		window.clear(sf::Color::Green);
		g.update(clk.getElapsedTime().asSeconds());
		clk.restart();
		g.renderGame();
		window.display();
	}

}