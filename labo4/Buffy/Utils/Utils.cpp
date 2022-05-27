//
// Created by Alexandre Jaquier on 19.05.2022.
//

#include "Utils.hpp"
#include <cmath>
#include <ctime>

int Utils::randomPosition(int min, int max) {
	static bool alreadyCalled = false;
	if (!alreadyCalled) {
		srand((unsigned)time(nullptr));
		alreadyCalled = true;
	}

	// TODO: clean this cast
	return min + (rand() % max);
}

double Utils::getDistance(int x1, int y1, int x2, int y2) {
	return (hypot(x1 - x2, y1 - y2));
}
