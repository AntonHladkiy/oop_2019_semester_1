#include "pch.h"
#include "Dice.h"


double Dice::generate_random(double second) {
	static std::random_device rd;
	std::seed_seq seed{ rd(), static_cast<unsigned int>(time(nullptr)) };
	static std::mt19937_64 gen(seed);
	std::uniform_real_distribution<double> real_dis(0, second);
	return real_dis(gen);
}


Dice::Dice(int _edges_count):edges_count(_edges_count)
{
	chances.resize(edges_count);
	double second = 1;
	for (int i = 0; i < edges_count-1; i++) {
		double temp = generate_random(second);
		second -= temp;
		chances[i] = temp;
	}
	chances[edges_count - 1] = second;
}


Dice::Dice(std::vector<double> _chances) :edges_count(_chances.size()),chances(_chances)
{}
Dice::Dice()
{}

std::ostream& operator<<(std::ostream& out,const Dice& dice) {
	out << "{ ";
	for (int i = 0; i < dice.chances.size()-1; i++) {
		out << dice.chances[i] << ", ";
	}
	out << dice.chances[dice.chances.size() - 1] << " }";
	return out;
}


bool Dice::operator==(const Dice& dice) {
	if (chances.size() == dice.chances.size()) {
		for (int i = 0; i < chances.size(); i++) {
			if (chances[i] != dice.chances[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}


void Dice::print() {
	if (!chances.empty()) {
		std::cout << "{ ";
		for (int i = 0; i < chances.size() - 1; i++) {
			std::cout << chances[i] << ", ";
		}
		std::cout << chances[chances.size() - 1] << " }" << std::endl;
	}
}