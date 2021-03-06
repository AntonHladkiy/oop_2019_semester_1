#include <SFML/Graphics.hpp>
#include "Player.h"

///size of cell in pxls
#define CELL_SIZE 160

bool Player::is_bot()
{
	return false;
}

Player::Player()
{
}

bool Player::make_turn(Game & game, sf::Vector2f pos)
{
	bool temp;
	//check that we are on the field
	if (pos.x < CELL_SIZE * game.x_scale * game.board_size+CELL_SIZE || pos.y < CELL_SIZE || pos.x >  CELL_SIZE * game.x_scale * game.board_size + CELL_SIZE+CELL_SIZE * game.x_scale * game.board_size || pos.y > CELL_SIZE+CELL_SIZE * game.y_scale * game.board_size ) return false;
	//transform to index
	size_t x = (pos.x - CELL_SIZE * game.x_scale * (game.board_size) - CELL_SIZE) / (CELL_SIZE * game.x_scale), y = (pos.y- CELL_SIZE) / (CELL_SIZE * game.y_scale);
	//check for empty cell
	if (am_i_first_pl) {
		if (!check_cell(game, x, y, game.pl_2_field,temp)) {
			//am i won
			if (am_i_won(game, am_i_first_pl)) {
				game._playing = false;
				game._first_pl_won = true;
			}
			return false;
		}
	}
	else {
		if (!check_cell(game, x, y, game.pl_1_field,temp)) {
			//am i won
			if (am_i_won(game, am_i_first_pl)) {
				game._playing = false;
				game._first_pl_won = false;
			}
			return false;
		}
	}
	//next player turn
	game._first_pl_turn = !game._first_pl_turn;
	return true;
}



void Player::make_field(Game & game, sf::RenderWindow & window,bool & restart)
{
	std::vector<int> ships_count = { 4, 3, 2, 1 };
	std::pair<int, int> pair;
	std::pair<std::pair<int, int>, sf::Vector2f> helper;
	int temp;
	cell** _field;
	if (am_i_first_pl) {
		_field = game.pl_1_field;
	}
	else {
		_field = game.pl_2_field;
	}
	sf::Vector2f delta_pos; //delta of coord
	bool moveable = false;
	bool rotated = false;
	//check if we get already existed ship or not
	bool is_ship_from_field = false;
	//detect if player finish field
	bool is_player_finished = false;
	//check if all ships are placed
	bool are_all_ships_placed = false;
	//interface
	Interface interface;
	while (window.isOpen()&&(!is_player_finished)) {
		
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window); //coord of mouse (in px)
		sf::Vector2f pos = window.mapPixelToCoords(pixelPos); //coord of mous (transform)
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				restart = false;
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.key.code == sf::Mouse::Left) {
					helper = game.param_of_new_ship(window, pos, _field, rotated, is_ship_from_field,ships_count);
					pair = helper.first;
					delta_pos = helper.second;
				
					if (pair.first != 0) {
						if (!is_ship_from_field) {
							temp = ships_count[pair.first - 1];
							ships_count[pair.first - 1] = 0;
						}
						else {
							temp = 0;
						}
						moveable = true;
					}
				}
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.key.code == sf::Mouse::Left) {
					if (moveable) {
						if (game.place_ship(pair, pos, _field, rotated)) {
							
							if (!is_ship_from_field) {
								ships_count[pair.first - 1] = temp - 1;
							}
						}
						else {
							if (!is_ship_from_field) {
								ships_count[pair.first - 1] = temp;
							}
							else {
								ships_count[pair.first - 1] ++;
							}
						}
						moveable = false;
						temp = 0;
					}
				}
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::R) {
					rotated = !rotated;
				}
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::F) {
					if (are_all_ships_placed) {
						is_player_finished = true;
					}
				}
			}
		}
		
		are_all_ships_placed = true;
		for (auto i = 0; i < ships_count.size(); i++) {
			if (ships_count[i] != 0) {
				are_all_ships_placed = false;
			}
		}
		window.clear();
		if (am_i_first_pl) {
			interface.print_message("Player's 1 field", sf::Vector2f(150, 50), window);
		}
		else {
			interface.print_message("Player's 2 field", sf::Vector2f(150, 50), window);
		}
		interface.print_message("Available ships", sf::Vector2f(CELL_SIZE*game.x_scale*game.board_size + 2 * CELL_SIZE, 50), window);
		game.draw_starting_screen(window, ships_count, _field);
		if (are_all_ships_placed&&!moveable) {
			interface.print_message("Press F to finish your board", sf::Vector2f(CELL_SIZE*game.x_scale*game.board_size + 2 * CELL_SIZE, 700), window);
		}
		if (moveable) {
			interface.print_message("Press R to rotate ship", sf::Vector2f(CELL_SIZE*game.x_scale*game.board_size+2*CELL_SIZE, 700), window);
			game.move_ship(window, pos, delta_pos, pair, rotated);
		}
		window.display();
	}
}

Player::Player(bool _am_i_first_palyer):Participant(_am_i_first_palyer)
{

}





Player::~Player()
{
}
