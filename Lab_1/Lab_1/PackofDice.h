#pragma once
#include <vector>
#include"Dice.h"
#include <iostream>

class PackofDice:public Dice
{
private:
	std::vector<Dice> pack;
	void add_dice_to_chances(Dice);
public:
	bool operator<(PackofDice);
	void count_chances();
	PackofDice();
	PackofDice(std::vector<Dice>);
	friend std::ostream& operator<< (std::ostream&, PackofDice&);
	double count_expected_value();
	void print_chances();
};

