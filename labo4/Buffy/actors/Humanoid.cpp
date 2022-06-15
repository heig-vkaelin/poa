/**
 * Classe Humanoid représentant tous les acteurs de la simulation
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Humanoid.hpp"
#include "../Field.hpp"

Humanoid::Humanoid(const Position& position)
	: alive(true), position(position), action(nullptr) {
}

Humanoid::~Humanoid() {
	delete action;
}

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

const Position& Humanoid::getPosition() const {
	return position;
}

void Humanoid::setPosition(const Position& _position) {
	position = _position;
}
