#include "pch.h"
#include "PackofDice.h"


PackofDice::PackofDice()
{
}
PackofDice::PackofDice(std::vector<Dice> _pack):pack(_pack)
{
}


void PackofDice::add_dice_to_chances(Dice dice) {
	if (chances.empty()) {
		chances = dice.chances;
	}
	else {
		std::vector<std::vector<double>> counting_matrix;
		counting_matrix.resize(chances.size());
		std::vector<double> result;
		result.resize(chances.size() + dice.chances.size());
		for (int i = 0; i < chances.size(); i++) {
			counting_matrix[i].resize(dice.chances.size());
			for (int j = 0; j < dice.chances.size(); j++) {
				counting_matrix[i][j] = chances[i] * dice.chances[j];
				result[i + j + 1] += counting_matrix[i][j];
			}
		}
		chances = result;
	}
}
void PackofDice::count_chances() {
	for (int i = 0; i < pack.size(); i++) {
		add_dice_to_chances(pack[i]);
	}
}


double PackofDice::count_expected_value() {
	double expected_value = 0;
	for (int i = 0; i < chances.size(); i++) {
		expected_value += chances[i] * (i + 1);
	}
	return expected_value;
}

std::ostream& operator<<(std::ostream& out,PackofDice& pack) {
	out << "{ ";
	for (int i = 0; i < pack.chances.size() - 1; i++) {
		out << pack.chances[i] << ", ";
	}
	out << pack.chances[pack.chances.size() - 1] << " }";
	out << ", [" << pack.count_expected_value() << "]";
	return out;
}

bool PackofDice::operator<(PackofDice pack) {
	return(count_expected_value() < pack.count_expected_value());
}


void PackofDice::print_chances() {
	print();
	std::cout << count_expected_value() << std::endl;
}