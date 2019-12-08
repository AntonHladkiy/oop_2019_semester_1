#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Player.h"

int main()
{
	Game game;
	Player pl_1(true);
	Player pl_2(false);
	Interface interface;
	sf::RenderWindow window(sf::VideoMode(1440, 800), "Sea Battle");
	pl_1.make_field(game, window);
	pl_2.make_field(game, window);
	sf::View view = window.getDefaultView();
	window.setView(view);
	while (window.isOpen())
	{
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window); //coord of mouse (in px)
		sf::Vector2f pos = window.mapPixelToCoords(pixelPos); //coord of mous (transform)
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.key.code == sf::Mouse::Left)
				{
					if (game.is_pl_1_turn())
					{
						//std::cout << "Player 1's turn" << std::endl;
						//interface.print_message("Player's 1 turn", sf::Vector2f(600, 50), window);
						pl_1.make_turn(game, pos);
					}
					else {
						//interface.print_message("Player's 2 turn", sf::Vector2f(600, 50), window);
						//std::cout << "Player 2's turn" << std::endl;
						pl_2.make_turn(game, pos);
					}
				}
		}
		if (!game.are_we_still_playing()) {
			window.close();
		}
		window.clear();
		game.draw(window);
		window.display();
	}

	return 0;
}

