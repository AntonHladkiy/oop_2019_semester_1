#pragma once
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
class Dice
{
private:
	double generate_random(double);
	int edges_count;
public:
	std::vector<double> chances;
	Dice();
	Dice(int);
	Dice(std::vector<double>);
	void print();
};

