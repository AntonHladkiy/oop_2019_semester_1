#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
/**
 * @brief This class contains virtual similar methods for Player and Bot 

 * This class is a generalization of both bot and real player type of players

 */
class Participant
{
private:

protected:
	/// check if player hit ship
	bool check_cell(Game &game, size_t x, size_t y, cell** enemy_field,bool& is_destroyed);
	///am i first player
	bool am_i_first_pl;
public:
	///am i bot?
	virtual bool is_bot() = 0;
	///trying to make_turn
	virtual bool make_turn(Game &game, sf::Vector2f pos) = 0;
	///am i won
	bool am_i_won(Game &game, bool am_i_first_pl);
	///making your field
	virtual void make_field(Game &game, sf::RenderWindow &window, bool& restart)=0;
	///constructor with determinated is player first
	Participant(bool am_i_first_pl);
	Participant();
	~Participant();
};

