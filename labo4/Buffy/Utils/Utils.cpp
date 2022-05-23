//
// Created by Alexandre Jaquier on 19.05.2022.
//

#include "Utils.hpp"
#include <cmath>
#include <ctime>

unsigned Utils::randomPosition(unsigned min, unsigned max) {
	static bool alreadyCalled = false;
	if (!alreadyCalled) {
		srand((unsigned)time(nullptr));
		alreadyCalled = true;
	}

	// TODO: clean this cast
	return min + (rand() % max);
}

unsigned Utils::getDistance(unsigned x1, unsigned y1, unsigned x2, unsigned y2) {
	return (unsigned)(hypot(x1 - x2, y1 - y2));
}
