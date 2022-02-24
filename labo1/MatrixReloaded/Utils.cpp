#include "Utils.hpp"
#include <ctime>
#include <cstdlib>

unsigned Utils::getRandom(unsigned int max) {
	static bool alreadyCalled = false;
	if (!alreadyCalled) {
		// TODO: add time(0) instead of hardcoded value
		srand(42);
	}
	alreadyCalled = true;
	return static_cast<unsigned>(rand()) % max;
}
