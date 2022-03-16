/**
 * Classe mettant à dispositions diverses fonctions utilitaires
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "Utils.hpp"
#include <ctime>
#include <cstdlib>

unsigned Utils::getRandom(unsigned max) {
	static bool alreadyCalled = false;
	if (!alreadyCalled) {
		srand((unsigned)time(nullptr));
	}
	alreadyCalled = true;
	return (unsigned)(rand()) % max;
}

long Utils::floorMod(long a, long b) {
	long res = a % b;
	return res < 0 ? res + b : res;
}
