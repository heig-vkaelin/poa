/**
 * Classe permettant de générer facilement des nombres aléatoires
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Random.hpp"
#include <chrono>
#include <stdexcept>

using namespace std;

mt19937 Random::generator(
	(unsigned)chrono::system_clock::now().time_since_epoch().count()
);

int Random::generate(int min, int max) {
	if (max <= min)
		throw invalid_argument("La valeur min doit etre plus grande que max.");

	uniform_int_distribution<int> distribution(min, max - 1);
	return distribution(generator);
}

int Random::generate(int max) {
	return generate(0, max);
}

bool Random::generateBool() {
	int random = generate(0, 2);
	return random == 1;
}
