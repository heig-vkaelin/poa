//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Humanoid.hpp"
#include "../Field.hpp"
#include "../Utils/Utils.hpp"

Humanoid::Humanoid(unsigned maxWidth, unsigned maxHeight)
	: action(nullptr),
	  x(Utils::find_random_position(0, maxWidth)),
	  y(Utils::find_random_position(0, maxHeight)), alive(true) {
}

void Humanoid::setAction(const Field& field) {

}

void Humanoid::executeAction(Field& field) {

}

bool Humanoid::isAlive() const {
	return true;
}

unsigned Humanoid::getXPos() const {
	return x;
}

unsigned Humanoid::getYPos() const {
	return y;
}

Humanoid::~Humanoid() = default;
