//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Buffy.hpp"
#include "Vampire.hpp"
#include "Human.hpp"
#include "../Field.hpp"
#include "../actions/Kill.hpp"
#include "../actions/Move.hpp"

#include <iostream>

using namespace std;

Buffy::Buffy(unsigned x, unsigned y) : Humanoid(x, y) {}

ActorType Buffy::getType() const {
	return ActorType::BUFFY;
}

void Buffy::display(const Displayer& displayer) const {
	displayer.displayBuffy();
}

void Buffy::setAction(const Field& field) {
	if (action != nullptr) {
		delete action;
	}

	Vampire* target = field.findClosestHumanoid<Vampire>(*this);
	if (target == nullptr) {
		action = new Move(2, *this);
		return;
	}

	cout << "Buffy: "
		  << getPosition().getX() << " " << getPosition().getY() << endl;
	cout << "Vampire: "
		  << target->getPosition().getX() << " " << target->getPosition().getY()
		  << endl;
	cout << "DIST: "
		  << Position::getDistance(getPosition(), target->getPosition()) << endl;

	if (Position::getDistance(getPosition(), target->getPosition()) <= 2) {
		// TODO: pk segfault quand on kill
		cout << "KILL" << endl;
		action = new Kill(*target);
	} else {
		// TODO: se rapprocher de la target et pas déplacement random
		action = new Move(2, *this);
	}
}

void Buffy::executeAction(Field& field) {
	action->execute(field);
}