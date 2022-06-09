//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Humanoid.hpp"
#include "../Field.hpp"

Humanoid::Humanoid(unsigned maxWidth, unsigned maxHeight) {
	init(Position::getRandomPosition((int)maxWidth, (int)maxHeight));
}

Humanoid::Humanoid(const Humanoid& humanoid) {
	init(humanoid.position);
}

Humanoid::~Humanoid() = default;

void Humanoid::setAction(const Field& field) {
	action = getNextAction(field);
}

void Humanoid::executeAction(Field& field) {
	if (action != nullptr) {
		action->execute(field);
		delete action;
		action = nullptr;
	}
}

bool Humanoid::isAlive() const {
	return alive;
}

void Humanoid::kill(Field&) {
	if (action != nullptr) {
		delete action;
		action = nullptr;
	}
	alive = false;
}

Position Humanoid::getPosition() const {
	return position;
}

void Humanoid::setPosition(Position _position) {
	position = _position;
}

void Humanoid::init(const Position& _position) {
	action = nullptr;
	alive = true;
	position = _position;
}
