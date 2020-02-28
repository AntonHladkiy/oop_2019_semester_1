#pragma once
#include <vector>
#include <iostream>
#include "Interface.h"
/**
 * @brief Enum for variant of cell

 * it can be empty,contains part of ship,destoyed ship,or be hitted but be a miss

 */
enum class cell {
	empty, ship, miss, destroyed_ship
};

class Participant;
/**
 * @brief Class that draw boards, implement standart flow of the game

 * Class contains methods for checking cells after hitting ship,destroying ship,checks if the game is still going and who wins.

 */
class Game
{
public:
	friend class Player;
	friend class Participant;
	friend class Bot;
	///draw with sfml
	void draw(sf::RenderWindow &window, Participant* p_1, Participant* p_2);
	void draw_starting_screen(sf::RenderWindow &window, std::vector<int> &ships_count,cell** _field);
	///is now turn of first player?
	bool is_pl_1_turn();
	Game();
	bool are_we_still_playing();
	///who won th game?
	bool did_first_win();
	///calculating size and index of pointed part
	std::pair<int, int> calc_ship_coord(size_t x, size_t y, size_t prev_x, size_t prev_y, cell** field);
	///check ship for destruction
	bool check_for_destruction(size_t x, size_t y, cell** _field, size_t start_x, size_t start_y, size_t &size_of_ship);
	///try to place ship
	bool place_ship(std::pair<int, int> pair, sf::Vector2f pos, cell** field, bool rotated);
private:
	
	///fill empty cells after destroying ship
	void fill_cells(size_t x, size_t y, cell** enemy_field, size_t start_x, size_t start_y);
	///check for borders
	int true_borders(int index);
	
	///move ship
	void move_ship(sf::RenderWindow &window, sf::Vector2f pos, sf::Vector2f delta, std::pair<int,int> pair, bool rotated);
	///check if we get ship with mouse click 
	std::pair<std::pair<int, int>, sf::Vector2f> param_of_new_ship(sf::RenderWindow &window,sf::Vector2f pos, cell** own_field, bool& is_rotated,bool &is_ship_from_field, const std::vector<int>& ships_count);	
	///are we still playing
	bool _playing;
	///board size
	size_t board_size;
	///draw fields based on players turn
	void draw_pl_field(sf::RenderWindow &window, cell** own_field, cell** enemy_field);
	///field of first layer
	cell** pl_1_field;
	///field of second layer
	cell** pl_2_field;
	///
	///ship of first player
	std::vector<int> pl_1_ships;
	///ship of second player
	std::vector<int> pl_2_ships;
	///
	///will it be first player turn now
	bool _first_pl_turn;
	///did first player win
	bool _first_pl_won;
	///sfml stuff
	sf::Texture _texture;
	///sfml stuff
	sf::Sprite _sprite;
	///
	///scale's param
	float x_scale;
	///scale's param
	float y_scale;
	///


};