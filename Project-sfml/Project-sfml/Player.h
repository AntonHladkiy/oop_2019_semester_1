#pragma once
#include "Participant.h"
#include "Game.h"
#include "Interface.h"
#include <vector>
#include <iostream>

class Player: public Participant
{
private:
public:
	bool is_bot() override;
	Player();
	//trying to make_turn
	bool make_turn(Game &game, sf::Vector2f pos) override;
	//making your field
	void make_field(Game &game, sf::RenderWindow &window,bool& restart) override;
	Player(bool _am_i_first_palyer);
	~Player();
};
