//
// Created by Alexandre Jaquier on 19.05.2022.
//

#include "Random.hpp"

std::random_device Random::rand_dev;
std::mt19937 Random::generator(Random::rand_dev());

int Random::randomPosition(int min, int max) {
	std::uniform_int_distribution<int> distr(min, max);
	int tmp = distr(generator);
	return tmp;
}
