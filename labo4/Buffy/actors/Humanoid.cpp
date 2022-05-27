//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Humanoid.hpp"
#include "../Field.hpp"
#include "../Utils/Utils.hpp"

Humanoid::Humanoid(unsigned maxWidth, unsigned maxHeight)
	: action(nullptr),
	  x(Utils::randomPosition(0, maxWidth)),
	  y(Utils::randomPosition(0, maxHeight)), alive(true) {
}

Humanoid::~Humanoid() = default;

void Humanoid::setAction(const Field& field) {

}

void Humanoid::executeAction(Field& field) {
	if (action != nullptr) {
		action->execute(field);
	}
}

bool Humanoid::isAlive() const {
	return true;
}

void Humanoid::kill() {
    alive = false;
}

unsigned Humanoid::getXPos() const {
	return x;
}

unsigned Humanoid::getYPos() const {
	return y;
}

void Humanoid::setPosition(unsigned _x, unsigned _y) {
	x = _x;
	y = _y;
}
