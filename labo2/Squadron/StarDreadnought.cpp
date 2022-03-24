//
// Created by Valentin Kaelin on 17.03.22.
//

#include "StarDreadnought.hpp"

using namespace std;

StarDreadnought::StarDreadnought(double cargo) : CargoShip(cargo) {
}

const string StarDreadnought::MODEL_NAME = "Super-class";
const unsigned StarDreadnought::MAX_SPEED = 40;
const double StarDreadnought::WEIGHT = 9000000000;
const double StarDreadnought::MAX_CARGO = 250000;

unsigned StarDreadnought::getMaxSpeed() const {
	return MAX_SPEED;
}

string StarDreadnought::getModelName() const {
	return MODEL_NAME;
}

double StarDreadnought::getWeight() const {
	return WEIGHT + getCargo();
}

double StarDreadnought::getMaxCargo() const {
	return MAX_CARGO;
}
