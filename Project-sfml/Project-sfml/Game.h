#pragma once
#include <vector>
#include <iostream>
#include "Interface.h"
enum class cell {
	empty, ship, miss, destroyed_ship
};
class Game
{
public:
	friend class Player;
	//draw with sfml
	void draw(sf::RenderWindow &window);
	void draw_starting_screen(sf::RenderWindow &window, std::vector<int> &ships_count,cell** _field);
	//reset game
	//void reset();
	//is now turn of first player?
	bool is_pl_1_turn();
	Game();
	bool are_we_still_playing();
private:
	//calculating size and index of pointed part
	std::pair<int, int> calc_ship_coord(size_t x, size_t y, size_t prev_x, size_t prev_y, cell** field);
	//fill empty cells after destroying ship
	void fill_cells(size_t x, size_t y, cell** enemy_field, size_t start_x, size_t start_y);
	//check for borders
	int true_borders(int index);
	//move ship
	void move_ship(sf::RenderWindow &window, sf::Vector2f pos, sf::Vector2f delta, std::pair<int,int> pair, bool rotated);
	//try to place ship
	bool place_ship(std::pair<int, int> pair, sf::Vector2f pos, cell** field, bool rotated);
	//check if we get ship with mouse click 
	std::pair<std::pair<int, int>, sf::Vector2f> param_of_new_ship(sf::RenderWindow &window,sf::Vector2f pos, cell** own_field, bool& is_rotated,bool &is_ship_from_field, const std::vector<int>& ships_count);
	//check ship for destruction
	bool check_for_destruction(size_t x, size_t y,cell** _field, size_t start_x, size_t start_y,size_t &size_of_ship);
	//are we still playing
	bool _playing;
	//board size
	size_t board_size;
	//draw fields based on players turn
	void draw_pl_field(sf::RenderWindow &window, cell** own_field, cell** enemy_field);
	//fields of first and second player
	cell** pl_1_field;
	cell** pl_2_field;
	//ships of both players
	std::vector<int> pl_1_ships;
	std::vector<int> pl_2_ships;
	//will it be first player turn now
	bool _first_pl_turn;
	//sfml stuff
	sf::Texture _texture;
	sf::Sprite _sprite;
	//scale's param
	float x_scale;
	float y_scale;


};