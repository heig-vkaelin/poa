//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Vampire.hpp"
#include "Human.hpp"
#include "../Field.hpp"

#include "../actions/Transform.hpp"
#include "../actions/Move.hpp"
#include "ActorType.hpp"

Vampire::Vampire(unsigned x, unsigned y) : Humanoid(x, y) {}

Vampire::Vampire(const Humanoid& other) noexcept: Humanoid(other) {}

ActorType Vampire::getType() const {
	return ActorType::VAMPIRE;
}

void Vampire::display(const Displayer& displayer) const {
	displayer.displayVampire();
}

void Vampire::setAction(const Field& field) {
	if (action != nullptr) {
		delete action;
	}
	Human* target = field.findClosestHumanoid<Human>(*this);
	if (target == nullptr) {
		action = new Move(1, *this);
		return;
	}

	if (Position::getDistance(getPosition(), target->getPosition()) <= 2) {
		action = new Transform(*target);
	} else {
		action = new Move(1, *this, target);
	}
}

void Vampire::executeAction(Field& field) {
	if (action != nullptr) {
		action->execute(field);
	}
}

void Vampire::kill(Field& field) {
	Humanoid::kill(field);
	field.vampireDied();
}
