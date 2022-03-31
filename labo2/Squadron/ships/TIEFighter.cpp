/**
 * Classe représentant un vaisseau de type Chasseur TIE
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "TIEFighter.hpp"

using namespace std;

unsigned TIEFighter::counter = 0;
const string TIEFighter::MODEL_NAME = "TIE/LN";
const unsigned TIEFighter::MAX_SPEED = 100;
const double TIEFighter::WEIGHT = 6;

TIEFighter::TIEFighter() : Ship(++counter) {
}

unsigned TIEFighter::getMaxSpeed() const {
	return MAX_SPEED;
}

string TIEFighter::getModelName() const {
	return MODEL_NAME;
}

double TIEFighter::getWeight() const {
	return WEIGHT;
}
