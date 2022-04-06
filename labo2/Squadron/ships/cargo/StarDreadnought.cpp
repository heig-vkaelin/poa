/**
 * Classe représentant un vaisseau de type Star Destroyer
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "StarDreadnought.hpp"

using namespace std;

unsigned StarDreadnought::counter = 0;
const string StarDreadnought::MODEL_NAME = "Super-class Star Destroyer";
const unsigned StarDreadnought::MAX_SPEED = 40;
const double StarDreadnought::WEIGHT = 9000000000;
const double StarDreadnought::MAX_CARGO = 250000;

StarDreadnought::StarDreadnought(double cargo)
	: CargoShip(++counter, cargo, MAX_CARGO) {
}

unsigned StarDreadnought::getMaxSpeed() const {
	return MAX_SPEED;
}

string StarDreadnought::getModelName() const {
	return MODEL_NAME;
}

double StarDreadnought::getWeight() const {
	return WEIGHT + getCargo();
}
