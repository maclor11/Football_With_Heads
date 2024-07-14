#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GAMETWO", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	Game g(window);
	g.AddPlayers(new Player("ronaldo7.png", "CRISTIANO"), new Player("messi10.png", "LIONEL"));
	sf::Clock clk;
	clk.restart();
	while (window.isOpen())
	{
		sf::Event event;
		//eventy
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
		//logika gry
		window.clear(sf::Color::Green);
		g.update(clk.getElapsedTime().asSeconds());
		clk.restart();
		g.renderGame();
		window.display();
	}

}