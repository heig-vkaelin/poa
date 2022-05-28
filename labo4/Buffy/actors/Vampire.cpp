//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Vampire.hpp"
#include "Human.hpp"
#include "Buffy.hpp"
#include "../Field.hpp"

#include "../actions/Transform.hpp"
#include "ActorType.hpp"

Vampire::Vampire(unsigned x, unsigned y) : Humanoid(x, y) {}

ActorType Vampire::getType() const {
	return ActorType::VAMPIRE;
}

void Vampire::display(const Displayer& displayer) const {
	displayer.displayVampire();
}

void Vampire::setAction(const Field& field) {
//	if (action != nullptr) {
//		delete action;
//	}
//    action = new Transform(*field.findClosestHumanoid<Human>(*this));
}

void Vampire::executeAction(Field& field) {
//	if (action != nullptr) {
//		action->execute(field);
//	}
}