#pragma once
#include "Game.h"
#include "Interface.h"
#include <vector>
#include <iostream>

class Player
{
private:
	//am i first player
	bool am_i_first_pl;
	bool check_cell(Game &game, size_t x, size_t y, cell** enemy_field);
	Player();
public:
	//trying to make_turn
	bool make_turn(Game &game, sf::Vector2f pos);
	//am i won
	bool am_i_won(Game &game, bool am_i_first_pl);
	//making your field
	void make_field(Game &game, sf::RenderWindow &window);
	Player(bool _am_i_first_palyer);
	~Player();
};

