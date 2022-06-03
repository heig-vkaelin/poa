//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Buffy.hpp"
#include "Vampire.hpp"
#include "Human.hpp"
#include "../Field.hpp"
#include "../actions/Kill.hpp"
#include "../actions/Move.hpp"

using namespace std;

Buffy::Buffy(unsigned x, unsigned y) : Humanoid(x, y) {}

void Buffy::setAction(const Field& field) {
	if (action != nullptr) {
		delete action;
	}
	Vampire* target = field.findClosestHumanoid<Vampire>(*this);
	if (target == nullptr) {
		action = new Move(2, *this);
		return;
	}

	if (getPosition().getDistance(target->getPosition()) <= 1) {
		action = new Kill(*target);
	} else {
		action = new Move(2, *this, target);
	}
}

char Buffy::getSymbol() const {
	return 'B';
}

Color Buffy::getColor() const {
	return Color::YELLOW;
}
