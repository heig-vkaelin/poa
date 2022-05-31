//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Humanoid.hpp"
#include "../Field.hpp"
#include "../Utils/Random.hpp"

Humanoid::Humanoid(unsigned maxWidth, unsigned maxHeight)
	: action(nullptr), alive(true),
	  position(Position::getRandomPosition((int)maxWidth, (int)maxHeight)) {
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
	return alive;
}

void Humanoid::kill() {
	alive = false;
}

Position Humanoid::getPosition() const {
	return position;
}

void Humanoid::setPosition(Position _position) {
	position = _position;
}
