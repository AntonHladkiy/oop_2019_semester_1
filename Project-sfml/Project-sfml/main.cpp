#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Bot.h"
#include "Participant.h"
#include "Interface.h"

int main()
{
	Interface interface;
	bool restart = true;
	bool is_first_bot;
	bool is_second_bot;
	interface.open_menu(is_first_bot,is_second_bot,restart);
	Participant* pl_1 = new Player(true);
	Participant* pl_2;
	if (is_second_bot) {
		pl_2 = new Bot(false);
	}
	else {
		pl_2 = new Player(false);
	}
	while (restart) {
		Game game;
		sf::RenderWindow window(sf::VideoMode(1440, 800), "Sea Battle");
		pl_1->make_field(game, window,restart);
		pl_2->make_field(game, window,restart);
		sf::View view = window.getDefaultView();
		window.setView(view);
		while (window.isOpen())
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(window); //coord of mouse (in px)
			sf::Vector2f pos = window.mapPixelToCoords(pixelPos); //coord of mous (transform)
			sf::Event event;
			if (game.is_pl_1_turn()&&pl_1->is_bot()) {
				pl_1->make_turn(game, pos);
			}
			if (!game.is_pl_1_turn() && pl_2->is_bot()) {
				pl_2->make_turn(game, pos);
			}
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					restart = false;
					window.close();
				}
				if (event.type == sf::Event::MouseButtonPressed)
					if (event.key.code == sf::Mouse::Left)
					{
						if (game.is_pl_1_turn()&& !pl_1->is_bot())
						{
							pl_1->make_turn(game, pos);
						}
						else {
							if(!pl_2->is_bot())
							pl_2->make_turn(game, pos);
						}
					}
			}
			window.clear();
			if (game.are_we_still_playing()) {
				game.draw(window,pl_1,pl_2);
			}
			else {
				//window.setSize(sf::Vector2u(100, 100));
				std::string str;
				if (game.did_first_win()) {
					str = "First player won";
				}
				else {
					str = "Second player won";
				}
				interface.print_message(str, sf::Vector2f(600, 120), window);
				interface.print_message("Press R to restart game", sf::Vector2f(640 + 2 * 160, 700), window);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					window.close();
					restart = true;
				}
			}
			window.display();
		}
	}
	return 0;
}

