// Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "Graph.h"
#include <vector>
#include "List.h"
#include <random>
#include <ctime>
#include "Tree.h"
#include "Dice.h"
#include "PackofDice.h"

double generate_random_(double second) {
	static std::random_device rd;
	std::seed_seq seed{ rd(), static_cast<unsigned int>(time(nullptr)) };
	static std::mt19937_64 gen(seed);
	static std::uniform_real_distribution<double> real_dis(0, second);
	return real_dis(gen);
}

int main()
{
	std::vector<Dice> pack;
	for (int i = 0; i < 4; i++) {
		pack.push_back(Dice(i*i+1));
		pack[i].print();
	}
	PackofDice pack_1(pack);
	pack_1.count_chances();
	pack_1.print_chances();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file