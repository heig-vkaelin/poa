//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Human.hpp"
#include "../actions/Move.hpp"
#include "../Field.hpp"

using namespace std;

Human::Human(unsigned x, unsigned y) : Humanoid(x, y) {}

void Human::kill(Field& field) {
	Humanoid::kill(field);
	field.humanDied();
}

char Human::getSymbol() const {
	return 'h';
}

Color Human::getColor() const {
	return Color::PINK;
}

Action* Human::getNextAction(const Field&) {
	// TODO: constante pas en dur
	return new Move(1, *this);
}
