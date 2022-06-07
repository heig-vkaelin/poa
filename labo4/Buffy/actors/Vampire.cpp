//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Vampire.hpp"
#include "Human.hpp"
#include "../Field.hpp"
#include "../actions/Kill.hpp"
#include "../actions/Move.hpp"
#include "../actions/Transform.hpp"

Vampire::Vampire(unsigned x, unsigned y) : Humanoid(x, y) {}

Vampire::Vampire(const Humanoid& other) : Humanoid(other) {}

void Vampire::setAction(const Field& field) {
	if (action != nullptr) {
		delete action;
	}
	Human* target = field.findClosestHumanoid<Human>(*this);
	if (target == nullptr) {
		return;
	}

	if (getPosition().getDistance(target->getPosition()) <= 1) {
		// 50% de chance de tuer, 50% de chance de transformer
		if (Random::generateBool())
			action = new Kill(*target);
		else
			action = new Transform(*target);
	} else {
		action = new Move(1, *this, target);
	}
}

void Vampire::kill(Field& field) {
	Humanoid::kill(field);
	field.vampireDied();
}

char Vampire::getSymbol() const {
	return 'V';
}

Color Vampire::getColor() const {
	return Color::BLUE;
}
