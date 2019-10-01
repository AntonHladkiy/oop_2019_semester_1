#include "pch.h"
#include "Operator.h"


std::ostream& operator<<(std::ostream& out, const std::vector<int>& vector) {
	if (!vector.empty()) {
		out << "{ ";
		for (int i = 0; i < vector.size() - 1; i++) {
			out << vector[i] << ", ";
		}
		out << vector[vector.size() - 1] << " }";
	}
	else {
		out << "Vector is empty";
	}
	return out;
}

double generate_random() {
	static std::random_device rd;
	std::seed_seq seed{ rd(), static_cast<unsigned int>(time(nullptr)) };
	static std::mt19937_64 gen(seed);
	std::uniform_real_distribution<double> real_dis;
	return real_dis(gen);
}