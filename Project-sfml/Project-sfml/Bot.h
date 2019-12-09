#pragma once
#include "Participant.h"
#include <vector>
#include <random>
#include <ctime>
class Bot :
	public Participant
{
private:
	//hited ship
	int prev_x;
	int prev_y;
	//is bot in killing stance
	bool is_killing;
	double generate_random(double second);
	//find most possible coordinates of ship
	std::pair<int, int> find_next_coord_for_attack(Game &game, cell** enemy_field,const std::vector<int>& enemy_ships);
	//modify weight if is_killing
	void modify(Game& game, cell** enemy_field,int** weight, int x,int y);
public:
	bool is_bot() override;
	//trying to make_turn
	bool make_turn(Game &game, sf::Vector2f pos) override;
	//making your field
	void make_field(Game &game, sf::RenderWindow &window, bool& restart) override;
	Bot(bool am_i_first_player);
	Bot();
	~Bot();
};

