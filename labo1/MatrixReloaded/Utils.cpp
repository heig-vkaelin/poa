#include "Utils.hpp"
#include <ctime>
#include <cstdlib>

unsigned Utils::getRandom(unsigned max) {
	static bool alreadyCalled = false;
	if (!alreadyCalled) {
		// TODO: add time(0) instead of hardcoded value
		srand(42);
	}
	alreadyCalled = true;
	return (unsigned)(rand()) % max;
}

long Utils::floorMod(long a, long b) {
	long res = a % b;
	return res < 0 ? res + b : res;
}
