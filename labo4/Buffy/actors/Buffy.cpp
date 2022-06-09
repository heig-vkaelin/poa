//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Buffy.hpp"
#include "Vampire.hpp"
#include "../Field.hpp"
#include "../actions/Kill.hpp"
#include "../actions/Move.hpp"

using namespace std;

Buffy::Buffy(unsigned x, unsigned y) : Humanoid(x, y) {}

char Buffy::getSymbol() const {
	return 'B';
}

Color Buffy::getColor() const {
	return Color::YELLOW;
}

Action* Buffy::getNextAction(const Field& field) {
	if (!field.hasVampires())
		return new Move(1, *this);

	Vampire* target = field.findClosestHumanoid<Vampire>(*this);
	if (getPosition().getDistance(target->getPosition()) <= 1)
		return new Kill(*target);

	return new Move(2, *this, target);
}
