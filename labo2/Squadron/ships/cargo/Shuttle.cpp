/**
 * Classe représentant un vaisseau de type navette impériale
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "Shuttle.hpp"

using namespace std;

unsigned Shuttle::counter = 0;
const string Shuttle::MODEL_NAME = "Lamda-class shuttle";
const unsigned Shuttle::MAX_SPEED = 54;
const double Shuttle::WEIGHT = 360;
const double Shuttle::MAX_CARGO = 80;

Shuttle::Shuttle(double cargo) : CargoShip(++counter, cargo, MAX_CARGO) {
}

unsigned Shuttle::getMaxSpeed() const {
	return MAX_SPEED;
}

string Shuttle::getModelName() const {
	return MODEL_NAME;
}

double Shuttle::getWeight() const {
	return WEIGHT + getCargo();
}
