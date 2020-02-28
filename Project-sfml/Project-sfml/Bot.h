#pragma once
#include "Participant.h"
#include <vector>
#include <random>
#include <ctime>
/**
 * @brief This class contains implementation for bot

 * Here there are methods for bot to calculate optimal cell for shooting,also changing behaviour if there is hitted but not destoyed ship on enemy`s board

 */
class Bot :
	public Participant
{
private:
	///remembered coordinates of hited ship
	int prev_x;
	///remembered coordinates of hited ship
	int prev_y;
	///is bot in killing stance(trying to  finish already damaged ship)
	bool is_killing;
	double generate_random(double second);
	///find most possible coordinates of ship
	std::pair<int, int> find_next_coord_for_attack(Game &game, cell** enemy_field,const std::vector<int>& enemy_ships);
	///modify weight of cells if bot is in killing stance
	void modify(Game& game, cell** enemy_field,int** weight, int x,int y);
public:
	bool is_bot() override;
	///trying to make_turn
	bool make_turn(Game &game, sf::Vector2f pos) override;
	///making your field(special algorithm for bot)
	void make_field(Game &game, sf::RenderWindow &window, bool& restart) override;
	Bot(bool am_i_first_player);
	Bot();
	~Bot();
};

