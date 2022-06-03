//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Human.hpp"
#include "../actions/Move.hpp"
#include "../Field.hpp"

using namespace std;

Human::Human(unsigned x, unsigned y) : Humanoid(x, y) {}

void Human::setAction(const Field&) {
	if (action != nullptr) {
		delete action;
	}
	// TODO: constante pas en dur
	action = new Move(1, *this);
}

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
