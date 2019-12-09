#include "Bot.h"



std::pair<int, int> Bot::find_next_coord_for_attack(Game & game, cell ** enemy_field, const std::vector<int>& enemy_ships)
{
	int** weight_of_cells;
	weight_of_cells = new int*[game.board_size];
	for (size_t i = 0; i < game.board_size; i++) {
		weight_of_cells[i] = new int[game.board_size];
	}
	for (size_t i = 0; i < game.board_size; i++) {
		for (size_t j = 0;j < game.board_size;j++) {
			weight_of_cells[i][j] = 0;
		}
	}
	for (size_t i = 0; i < enemy_ships.size(); i++) {
		for (size_t j = 0; j < game.board_size; j++) {
			for (size_t k = 0; k < game.board_size; k++) {
				//horizontal check
				bool check = true;
				for (size_t z = j; z <= j + i; z++) {
					if (game.board_size - 1 - j < i) {
					check = false;
					break;
					}
					if (enemy_field[z][k] == cell::miss ) {
						check = false;
					}
					if (!is_killing && enemy_field[z][k] == cell::destroyed_ship) {
						check = false;
					}
				}
				if (check) {
					for (size_t z = j; z <= j + i; z++) {
						weight_of_cells[z][k] += enemy_ships[i];
					}
				}
				//vertical check
				check = true;
				for (size_t z = k; z <= k + i; z++) {
					if (game.board_size -1 - k < i) {
						check = false;
						break;
					}
					if (enemy_field[j][z] == cell::miss) {
						check = false;
					}
					if (!is_killing && enemy_field[j][z] == cell::destroyed_ship) {
						check = false;
					}
				}
				if (check) {
					for (size_t z = k; z <= k + i; z++) {
						weight_of_cells[j][z] += enemy_ships[i];
					}
				}
			}
		}
	}
	int first = 0;
	int second = 0;
	if (is_killing) {
		modify(game, enemy_field, weight_of_cells, prev_x, prev_y);
	}
	//find maximum
	for (size_t j = 0; j < game.board_size; j++) {
		for (size_t k = 0; k < game.board_size; k++) {
			if (weight_of_cells[j][k] >= weight_of_cells[first][second]) {
				first = j;
				second = k;
			}
		}
	}
	return std::pair<int, int>(first,second);
}

void Bot::modify(Game & game, cell ** enemy_field, int** weight, int x, int y)
{
	int vertical_parts_destroyed = 0;
	int vertical_empty_places = 0;
	int horizontal_part_destroyed = 0;
	int horizontal_empty_places = 0;
	//counting in which line there are more destroyed parts
	for (int i = game.true_borders(x); i <= game.true_borders(x + 3); i++) {
		if (enemy_field[i][y] == cell::miss) {
			break;
		}
		if (enemy_field[i][y] == cell::destroyed_ship) {
			horizontal_part_destroyed++;
		}
		else {
			horizontal_empty_places++;
		}
	}
	for (int i = game.true_borders(x); i >= game.true_borders(x - 3); i--) {
		if (enemy_field[i][y] == cell::miss) {
			break;
		}
		if (enemy_field[i][y] == cell::destroyed_ship) {
			horizontal_part_destroyed++;
		}
		else {
			horizontal_empty_places++;
		}
	}
	for (int i = game.true_borders(y); i <= game.true_borders(y + 3); i++) {
		if (enemy_field[x][i] == cell::miss) {
			break;
		}
		if (enemy_field[x][i] == cell::destroyed_ship) {
			vertical_parts_destroyed++;
		}
		else {
			vertical_empty_places++;
		}
	}
	for (int i = game.true_borders(y); i >= game.true_borders(y - 3); i--) {
		if (enemy_field[x][i] == cell::miss) {
			break;
		}
		if (enemy_field[x][i] == cell::destroyed_ship) {
			vertical_parts_destroyed++;
		}
		else {
			vertical_empty_places++;
		}
	}
	//adding value to weight
	if (horizontal_part_destroyed > vertical_parts_destroyed || (horizontal_part_destroyed == vertical_parts_destroyed && horizontal_empty_places >= vertical_empty_places)) {
		for (int i = game.true_borders(x + 1); i <= game.true_borders(x + 3); i++) {
			if (enemy_field[i][y] == cell::miss) {
				break;
			}
			if (enemy_field[i][y] != cell::destroyed_ship) {
				weight[i][y] += 500 * (4 - i + x);
			}
		}
		for (int i = game.true_borders(x - 1); i >= game.true_borders(x - 3); i--) {
			if (enemy_field[i][y] == cell::miss) {
				break;
			}
			if (enemy_field[i][y] != cell::destroyed_ship) {
				weight[i][y] += 500 * (4 + i - x);
			}
		}
	}
	else {
		for (int i = game.true_borders(y + 1); i <= game.true_borders(y + 3); i++) {

			if (enemy_field[x][i] == cell::miss) {
				break;
			}
			if (enemy_field[x][i] != cell::destroyed_ship) {
				weight[x][i] += 500 * (4 - i + y);
			}
		}
		for (int i = game.true_borders(y - 1); i >= game.true_borders(y - 3); i--) {
			if (enemy_field[x][i] == cell::miss) {
				break;
			}
			if (enemy_field[x][i] != cell::destroyed_ship) {
				weight[x][i] += 500 * (4 + i - y);
			}
		}
	}

}

bool Bot::is_bot()
{
	return true;
}

bool Bot::make_turn(Game & game, sf::Vector2f pos)
{
	cell** enemy_field;
	std::vector<int> enemy_ships;
	if (am_i_first_pl) {
		enemy_field = game.pl_2_field;
		enemy_ships = game.pl_2_ships;
	}
	else {
		enemy_field = game.pl_1_field;
		enemy_ships = game.pl_1_ships;
	}
	std::pair<int, int> pair = find_next_coord_for_attack(game, enemy_field, enemy_ships);

	int x = pair.first;
	int y = pair.second;
	bool is_destroyed=!is_killing;
		if (!check_cell(game, x, y, enemy_field, is_destroyed)) {
			if (am_i_won(game, am_i_first_pl)) {
				game._playing = false;
				if (am_i_first_pl) {
					game._first_pl_won = true;
				}
				else {
					game._first_pl_won = false;
				}
			}
			if (!is_destroyed) {
				if (prev_x == -1) {
					prev_x = x;
					prev_y = y;
				}	
			}
			else {
				prev_x = -1;
				prev_y = -1;
			}
			is_killing = !is_destroyed;
			return false;
		}
		//next player turn
		game._first_pl_turn = !game._first_pl_turn;
		return true;
}

void Bot::make_field(Game & game, sf::RenderWindow & window, bool & restart)
{
	cell** my_field;
	if (am_i_first_pl) {
		my_field = game.pl_1_field;
	}
	else {
		my_field = game.pl_2_field;
	}
	my_field[0][1] = cell::ship;
	my_field[0][2] = cell::ship;
	my_field[0][3] = cell::ship;
	my_field[0][4] = cell::ship;


	my_field[0][6] = cell::ship;
	my_field[0][7] = cell::ship;
	my_field[0][8] = cell::ship;

	my_field[9][1] = cell::ship;
	my_field[9][2] = cell::ship;
	my_field[9][3] = cell::ship;

	my_field[9][5] = cell::ship;
	my_field[9][6] = cell::ship;

	my_field[9][8] = cell::ship;
	my_field[9][9] = cell::ship;

	my_field[2][0] = cell::ship;
	my_field[3][0] = cell::ship;

	my_field[5][6] = cell::ship;

	my_field[7][8] = cell::ship;

	my_field[4][3] = cell::ship;

	my_field[7][1] = cell::ship;
}

Bot::Bot(bool am_i_first_player) :Participant(am_i_first_player)
{
	is_killing = false;
	prev_x = -1; prev_y = -1;
}

Bot::Bot()
{
}



Bot::~Bot()
{
}
