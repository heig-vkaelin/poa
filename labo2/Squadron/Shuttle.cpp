//
// Created by Valentin Kaelin on 17.03.22.
//

#include "Shuttle.hpp"

using namespace std;

Shuttle::Shuttle(double cargo) : CargoShip(cargo) {
}

const string Shuttle::MODEL_NAME = "Lamda-class";
const unsigned Shuttle::MAX_SPEED = 54;
const double Shuttle::WEIGHT = 360;
const double Shuttle::MAX_CARGO = 80;

unsigned Shuttle::getMaxSpeed() const {
	return MAX_SPEED;
}

string Shuttle::getModelName() const {
	return MODEL_NAME;
}

double Shuttle::getWeight() const {
	return WEIGHT + getCargo();
}

double Shuttle::getMaxCargo() const {
	return MAX_CARGO;
}
