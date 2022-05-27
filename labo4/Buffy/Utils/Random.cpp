//
// Created by Alexandre Jaquier on 19.05.2022.
//

#include "Random.hpp"
#include <cmath>
#include <ctime>

// TODO: use a real random number generator
int Random::randomPosition(int min, int max) {
	static bool alreadyCalled = false;
	if (!alreadyCalled) {
		srand((unsigned)time(nullptr));
		alreadyCalled = true;
	}
	return min + (rand() % max);
}
