
#include "Participant.h"

#define CELL_SIZE 160
bool Participant::check_cell(Game &game, size_t x, size_t y, cell ** enemy_field,bool& is_destroyed)
{
	
	if (enemy_field[x][y] == cell::miss) return false;
	if (enemy_field[x][y] == cell::destroyed_ship) return false;
	if (enemy_field[x][y] == cell::ship) {
		enemy_field[x][y] = cell::empty;
		size_t size_of_ship = 0;
		if (game.check_for_destruction(x, y, enemy_field, -1, -1, size_of_ship)) {
			is_destroyed = true;
			//is_destroyed = true;
			game.fill_cells(x, y, enemy_field, -1, -1);
			if (am_i_first_pl) {
				//std::cout << game.pl_2_ships[size_of_ship - 1] << std::endl;
				game.pl_2_ships[size_of_ship - 1]--;
			}
			else {
				game.pl_1_ships[size_of_ship - 1]--;
			}
			enemy_field[x][y] = cell::destroyed_ship;
			return false;
		}
		is_destroyed = false;
		enemy_field[x][y] = cell::destroyed_ship;
		return false;
	}
	if (enemy_field[x][y] == cell::empty) {
		if (is_destroyed) {
			is_destroyed = true;
		}
		else {
			is_destroyed = false;
		}
		enemy_field[x][y] = cell::miss;
		return true;
	}

}

bool Participant::am_i_won(Game & game, bool am_i_first_pl)
{
	bool res = true;
	if (am_i_first_pl) {
		for (auto i = 0; i < game.pl_2_ships.size(); i++) {
			if (game.pl_2_ships[i] != 0) {
				res = false;
			}
		}
	}
	else {
		for (auto i = 0; i < game.pl_1_ships.size(); i++) {
			if (game.pl_1_ships[i] != 0) {
				res = false;
			}
		}
	}
	return res;
}



Participant::Participant(bool _am_i_first_pl)
{
	am_i_first_pl = _am_i_first_pl;
}

Participant::Participant()
{
}

Participant::~Participant()
{
}

void Game::draw(sf::RenderWindow & window, Participant* p_1, Participant* p_2)
{
	Interface interface;
	interface.print_message("Your field", sf::Vector2f(150, 100), window);
	interface.print_message("Enemy field", sf::Vector2f(150 + CELL_SIZE * x_scale*board_size + CELL_SIZE, 100), window);
	if (_first_pl_turn) {
		if (!p_1->is_bot()) {
			interface.print_message("Player's 1 turn", sf::Vector2f(600, 50), window);
			draw_pl_field(window, pl_1_field, pl_2_field);
		}
		else {
			interface.print_message("Player's 2 turn", sf::Vector2f(600, 50), window);
			draw_pl_field(window, pl_2_field, pl_1_field);
		}
	}
	else {
		if (!p_2->is_bot()) {
			interface.print_message("Player's 2 turn", sf::Vector2f(600, 50), window);
			draw_pl_field(window, pl_2_field, pl_1_field);
		}
		else {
			interface.print_message("Player's 1 turn", sf::Vector2f(600, 50), window);
			draw_pl_field(window, pl_1_field, pl_2_field);
		}
	}
}