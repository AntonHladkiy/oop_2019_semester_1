#include <SFML/Graphics.hpp>
#include "Game.h"


//size of cell in pxls
#define CELL_SIZE 160

void Game::draw(sf::RenderWindow & window)
{
	Interface interface;
	interface.print_message("Your field", sf::Vector2f(150, 100), window);
	interface.print_message("Enemy field", sf::Vector2f(150+ CELL_SIZE * x_scale*board_size+CELL_SIZE, 100), window);
	if (_first_pl_turn) {
		interface.print_message("Player's 1 turn", sf::Vector2f(600, 50), window);
		draw_pl_field(window, pl_1_field, pl_2_field);
	}
	else {
		interface.print_message("Player's 2 turn", sf::Vector2f(600, 50), window);
		draw_pl_field(window, pl_2_field, pl_1_field);
	}
}

void Game::draw_starting_screen(sf::RenderWindow & window,std::vector<int> &ships_count,cell** _field)
{
	for (auto i = 0; i < board_size; i++) {
		for (auto j = 0; j < board_size; j++) {
			_sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
			_sprite.setPosition(i * CELL_SIZE * x_scale, CELL_SIZE + j * CELL_SIZE * y_scale);
			_sprite.setColor(sf::Color::White);
			if (_field[i][j] == cell::ship) {
				_sprite.setColor(sf::Color::Blue);
			}
			window.draw(_sprite);
		}
	}
	_sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
	_sprite.setColor(sf::Color::Blue);
	for (size_t i = 0; i < ships_count.size(); i++) {
		if (ships_count[i] != 0) {
			for (auto j = 0; j < i+1; j++) {
				_sprite.setPosition(board_size * CELL_SIZE * x_scale+j*CELL_SIZE* x_scale+CELL_SIZE*2, CELL_SIZE + i*2*CELL_SIZE*y_scale);
				window.draw(_sprite);
			}
		}
	}

}

bool Game::is_pl_1_turn()
{
	return _first_pl_turn;
}

Game::Game()
{
	board_size = 10;
	_playing = true;
	_first_pl_turn = true;
	//sfml staff
	_texture.loadFromFile("../images/cells.png");
	_sprite.setTexture(_texture);

	//scale's staff
	x_scale = y_scale = (float)640 / (10 * CELL_SIZE);
	_sprite.setScale(x_scale, y_scale);

	//release memory
	pl_1_field = new cell*[board_size];
	pl_2_field = new cell*[board_size];
	for (size_t i = 0; i < board_size; i++)
	{
		pl_1_field[i] = new cell[board_size];
		pl_2_field[i] = new cell[board_size];
	}
	//initialization
	for (size_t i = 0; i < board_size; i++)
	{
		for (size_t j = 0; j < board_size; j++)
		{
			pl_1_field[i][j] = cell::empty;
			pl_2_field[i][j] = cell::empty;
		}
	}
	pl_1_ships.resize(4);
	pl_2_ships.resize(4);
	for (size_t i = 0; i < 4; i++) {
		pl_1_ships[i] = 4-i;
		pl_2_ships[i] = 4-i;
	}
}

bool Game::are_we_still_playing()
{
	return _playing;
}

std::pair<int, int> Game::calc_ship_coord(size_t x, size_t y, size_t prev_x, size_t prev_y, cell ** field)
{
	field[x][y] = cell::empty;
	int first = 1;
	int second = 0;
	if (x < board_size - 1) {
		if (x + 1 != prev_x || y != prev_y) {
			if (field[x + 1][y] == cell::ship) { first += calc_ship_coord(x + 1, y, x, y, field).first; }
		}
	}
	if (x > 0) {
		if (x - 1 != prev_x || y != prev_y) {
			if (field[x - 1][y] == cell::ship) { 
				first += calc_ship_coord(x -1, y, x, y, field).first;
				second +=1+ calc_ship_coord(x - 1, y, x, y, field).second;
			}
		}
	}
	if (y < board_size - 1) {
		if (x != prev_x || y + 1 != prev_y) {
			if (field[x][y + 1] == cell::ship) { first += calc_ship_coord(x , y+1, x, y, field).first; }
		}
	}
	if (y > 0) {
		if (x != prev_x || y - 1 != prev_y) {
			if (field[x][y - 1] == cell::ship) {
				first += calc_ship_coord(x, y - 1, x, y, field).first;
				second +=1+ calc_ship_coord(x, y - 1, x, y, field).second;
			}
		}
	}
	return std::pair<int, int>(first, second);
}

void Game::fill_cells(size_t x, size_t y,cell** enemy_field,size_t start_x,size_t start_y)
{
	if (enemy_field[true_borders(x + 1)][true_borders(y)] == cell::empty)
	{
		enemy_field[true_borders(x + 1)][true_borders(y)] = cell::miss;
	}
	if (enemy_field[true_borders(x + 1)][true_borders(y + 1)] == cell::empty)
	{
		enemy_field[true_borders(x + 1)][true_borders(y + 1)] = cell::miss;
	}

	if (enemy_field[true_borders(x + 1)][true_borders(y - 1)] == cell::empty)
	{
		enemy_field[true_borders(x + 1)][true_borders(y - 1)] = cell::miss;
	}

	if (enemy_field[true_borders(x)][true_borders(y + 1)] == cell::empty)
	{
		enemy_field[true_borders(x)][true_borders(y + 1)] = cell::miss;
	}

	if (enemy_field[true_borders(x)][true_borders(y - 1)] == cell::empty)
	{
		enemy_field[true_borders(x)][true_borders(y - 1)] = cell::miss;
	}

	if (enemy_field[true_borders(x - 1)][true_borders(y + 1)] == cell::empty)
	{
		enemy_field[true_borders(x - 1)][true_borders(y + 1)] = cell::miss;
	}

	if (enemy_field[true_borders(x - 1)][true_borders(y - 1)] == cell::empty)
	{
		enemy_field[true_borders(x - 1)][true_borders(y - 1)] = cell::miss;
	}

	if (enemy_field[true_borders(x - 1)][true_borders(y)] == cell::empty)
	{
		enemy_field[true_borders(x - 1)][true_borders(y)] = cell::miss;
	}

	if (x < 0 || x >= board_size || y < 0 || y >= board_size) {
		return;
	}
	else {
		//check for already destroyed parts
		if (x < board_size - 1) {
			if (x + 1 != start_x || y != start_y) {
				if (enemy_field[x + 1][y] == cell::destroyed_ship) { fill_cells(x + 1, y, enemy_field, x, y); }
			}
		}
		if (x > 0) {
			if (x - 1 != start_x || y != start_y) {
				if (enemy_field[x - 1][y] == cell::destroyed_ship) { fill_cells(x - 1, y, enemy_field, x, y); }
			}
		}
		if (y < board_size - 1) {
			if (x != start_x || y + 1 != start_y) {
				if (enemy_field[x][y + 1] == cell::destroyed_ship) { fill_cells(x, y + 1, enemy_field, x, y); }
			}
		}
		if (y > 0) {
			if (x != start_x || y - 1 != start_y) {
				if (enemy_field[x][y - 1] == cell::destroyed_ship) { fill_cells(x, y - 1, enemy_field, x, y); }
			}
		}

	}
}

int Game::true_borders(int index)
{
	if (index < 0) return 0;
	if (index >= board_size) return board_size - 1;
	else return index;
}

void Game::move_ship(sf::RenderWindow & window, sf::Vector2f pos, sf::Vector2f delta, std::pair<int, int> pair,bool rotated)
{
	for (int i = 0; i < pair.first; i++) {
		_sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
		_sprite.setColor(sf::Color::Blue);
		if (!rotated) {
			_sprite.setPosition(pos - delta + sf::Vector2f(i*CELL_SIZE*x_scale - pair.second*CELL_SIZE*x_scale, 0));
		}
		else {
			_sprite.setPosition(pos - delta + sf::Vector2f(0, i*CELL_SIZE*y_scale - pair.second*CELL_SIZE*y_scale));
		}
		window.draw(_sprite);
	}
}

bool Game::place_ship(std::pair<int, int> pair, sf::Vector2f pos,cell** field,bool rotated)
{
	std::pair<int, int> pair_1(1, 0);
	if (rotated) {
		pair_1 = pair;
		pair = { 1,0 };
	}
	//check that we are on the field
	if (pos.x < pair.second*CELL_SIZE*x_scale || pos.y < CELL_SIZE+CELL_SIZE*pair_1.second*y_scale || pos.x >  CELL_SIZE * x_scale * board_size-(pair.first-pair.second-1)*CELL_SIZE*x_scale || pos.y > CELL_SIZE + CELL_SIZE * y_scale * board_size - (pair_1.first - pair_1.second - 1)*CELL_SIZE*y_scale) return false;
	//transform to index
	size_t x = pos.x  / (CELL_SIZE * x_scale), y = (pos.y - CELL_SIZE) / (CELL_SIZE * y_scale);
	for (int i = x - pair.second; i < x + (pair.first - pair.second); i++) {
		for (int j = y - pair_1.second; j < y + (pair_1.first - pair_1.second); j++) {
			if (field[true_borders(i + 1)][true_borders(j)] == cell::ship)
				return false;

			if (field[true_borders(i + 1)][true_borders(j + 1)] == cell::ship)
				return false;

			if (field[true_borders(i + 1)][true_borders(j - 1)] == cell::ship)
				return false;

			if (field[true_borders(i)][true_borders(j + 1)] == cell::ship)
				return false;

			if (field[true_borders(i)][true_borders(j - 1)] == cell::ship)
				return false;

			if (field[true_borders(i - 1)][true_borders(j + 1)] == cell::ship)
				return false;

			if (field[true_borders(i - 1)][true_borders(j - 1)] == cell::ship)
				return false;

			if (field[true_borders(i - 1)][true_borders(j)] == cell::ship)
				return false;
		}
	}
	for (int i = x-pair.second; i < x+(pair.first-pair.second); i++) {
		for (int j = y - pair_1.second; j < y + (pair_1.first - pair_1.second); j++) {
			field[i][j] = cell::ship;
		}
	}

}

std::pair<std::pair<int, int>, sf::Vector2f> Game::param_of_new_ship(sf::RenderWindow & window, sf::Vector2f pos,cell** own_field,bool& is_rotated, bool &is_ship_from_field,const std::vector<int>& ships_count)
{
	//check that we hit ship on right side of screen
	int j;
	int i;
	bool temp = false;
	for ( i = 0; i < 5; i++) {
		for ( j = 0; j < i + 1; j++) {
			if (pos.x >= CELL_SIZE * x_scale*board_size + CELL_SIZE * 2 + CELL_SIZE * x_scale*j && pos.x <= CELL_SIZE * x_scale*board_size + CELL_SIZE * 2 + CELL_SIZE * x_scale*(j + 1)) {
				temp = true;
				break;
			}
		}
		if (temp&& pos.y >= CELL_SIZE + 2 * i*CELL_SIZE*y_scale&& pos.y <= CELL_SIZE + (2 * i + 1)*CELL_SIZE*y_scale) {
			if (ships_count[i] <= 0) {
				temp = false;
			}
			break;
		}
		else {
			temp = false;
		}
	}
	std::pair<int, int> pair;
	sf::Vector2f delta;
	//we dont hit ship then check for ship on board
	if (!temp) {
		if(pos.x<0||pos.x>CELL_SIZE * x_scale*board_size||pos.y<CELL_SIZE||pos.y>CELL_SIZE+ CELL_SIZE * x_scale*board_size){ return std::pair<std::pair<int, int>, sf::Vector2f>(std::pair<int, int>(0, 0), sf::Vector2f(0.0, 0.0)); }//we dont hit ship with cursor
		size_t x = pos.x / (CELL_SIZE * x_scale);
		size_t y=(pos.y-CELL_SIZE)/ (CELL_SIZE * y_scale);
		if(own_field[x][y]!=cell::ship){ return std::pair<std::pair<int, int>, sf::Vector2f>(std::pair<int, int>(0, 0), sf::Vector2f(0.0, 0.0)); }
		if (own_field[x][y + 1] == cell::ship || own_field[x][y - 1] == cell::ship) {
			is_rotated = true;
		}
		else {
			is_rotated = false;
		}
		pair = calc_ship_coord(x, y, -1, -1, own_field);
		delta = pos - sf::Vector2f( CELL_SIZE * x_scale*x, CELL_SIZE + y*CELL_SIZE*y_scale);
		is_ship_from_field = true;
	}
	else {
		is_rotated = false;
		is_ship_from_field = false;
		pair = { i + 1, j };
		delta = pos - sf::Vector2f(CELL_SIZE * x_scale*board_size + CELL_SIZE * 2 + CELL_SIZE * x_scale*j, CELL_SIZE + 2 * i*CELL_SIZE*y_scale);
	}
	return std::pair<std::pair<int, int>, sf::Vector2f>(pair, delta);
}

bool Game::check_for_destruction(size_t x, size_t y, cell ** _field,size_t start_x,size_t start_y, size_t &size_of_ship)
{
	size_of_ship++;
	if (x < 0 || x >= board_size || y < 0 || y >= board_size) {
		return true;
	}
	else {
		//check if there is a part of ship near
		//check for already destroyed parts
		if (x < board_size - 1) {
			if (x + 1 != start_x || y != start_y) {
				if (_field[x + 1][y] == cell::ship) { return false; }
				if (_field[x + 1][y] == cell::destroyed_ship) {if (!check_for_destruction(x + 1, y, _field, x, y, size_of_ship)) return false;}
			}
		}
		if (x > 0) {
			if (x - 1 != start_x || y != start_y) {
				if (_field[x - 1][y] == cell::ship) { return false; }
				if (_field[x - 1][y] == cell::destroyed_ship) { if (!check_for_destruction(x - 1, y, _field, x, y, size_of_ship)) return false; }
			}
		}
		if (y < board_size - 1) {
			if (x != start_x || y + 1 != start_y) {
				if (_field[x][y + 1] == cell::ship) { return false; }
				if (_field[x][y + 1] == cell::destroyed_ship) { if (!check_for_destruction(x, y + 1, _field, x, y, size_of_ship)) return false; }
			}
		}
		if (y > 0) {
			if (x != start_x || y - 1 != start_y) {
				if (_field[x][y - 1] == cell::ship) { return false; }
				if (_field[x][y - 1] == cell::destroyed_ship) { if (!check_for_destruction(x, y - 1, _field, x, y, size_of_ship)) return false; }
			}
		}
		return true;
	}
}

void Game::draw_pl_field(sf::RenderWindow & window, cell ** own_field, cell ** enemy_field)
{
	for (auto i = 0; i < board_size; i++) {
		for (auto j = 0; j < board_size; j++) {
			if (own_field[i][j] == cell::empty) {
				//cut texture
				_sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
			}
			if (own_field[i][j] == cell::miss) {
				_sprite.setTextureRect(sf::IntRect(CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
			}
			if (own_field[i][j] == cell::ship) {
				_sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
				_sprite.setColor(sf::Color::Blue);
			}
			else {
				if (own_field[i][j] == cell::destroyed_ship) {
					_sprite.setTextureRect(sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));
					_sprite.setColor(sf::Color::Red);
				}
				else {
					_sprite.setColor(sf::Color::White);
				}
			}

			_sprite.setPosition(i * CELL_SIZE * x_scale, CELL_SIZE + j * CELL_SIZE * y_scale);
			window.draw(_sprite);
		}
	}
	for (auto i = 0; i < board_size; i++) {
		for (auto j = 0; j < board_size; j++) {
			if (enemy_field[i][j] == cell::empty||enemy_field[i][j]==cell::ship) {
				//cut texture
				_sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
			}
			if (enemy_field[i][j] == cell::miss) {
				_sprite.setTextureRect(sf::IntRect(CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
			}
			//ship will have blue color
			if (enemy_field[i][j] == cell::destroyed_ship) {
				_sprite.setTextureRect(sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));
				_sprite.setColor(sf::Color::Red);
			}
			else {
				_sprite.setColor(sf::Color::White);
			}
			_sprite.setPosition(CELL_SIZE * x_scale * 10 + CELL_SIZE + i * CELL_SIZE * x_scale, CELL_SIZE + j * CELL_SIZE * y_scale);
			window.draw(_sprite);
		}
	}
}
