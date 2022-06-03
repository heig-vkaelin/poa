//
// Created by Alexandre Jaquier on 19.05.2022.
//

#include "Random.hpp"

using namespace std;

random_device Random::rand_dev;
mt19937 Random::generator(rand_dev());

int Random::generate(int min, int max) {
	uniform_int_distribution<int> distribution(min, max - 1);
	return distribution(generator);
}

int Random::generate(int max) {
	return generate(0, max);
}
