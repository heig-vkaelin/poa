//
// Created by Valentin Kaelin on 17.03.22.
//

#include "TIEFighter.hpp"

using namespace std;

const string TIEFighter::MODEL_NAME = "TIE/LN";
const unsigned TIEFighter::MAX_SPEED = 100;
const double TIEFighter::WEIGHT = 6;

unsigned TIEFighter::getMaxSpeed() const {
	return MAX_SPEED;
}

string TIEFighter::getModelName() const {
	return MODEL_NAME;
}

double TIEFighter::getWeight() const {
	return WEIGHT;
}
