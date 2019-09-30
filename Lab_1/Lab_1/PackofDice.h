#pragma once
#include <vector>
#include"Dice.h"
class PackofDice:public Dice
{
private:
	std::vector<Dice> pack;
	void add_dice_to_chances(Dice);
public:
	bool operator<(PackofDice);
	void count_chances();
	PackofDice(std::vector<Dice>);
	double count_expected_value();
	void print_chances();
};

