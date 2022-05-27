//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Human.hpp"
#include "../actions/Move.hpp"

using namespace std;

Human::Human(unsigned x, unsigned y) : Humanoid(x, y) {}

ActorType Human::getType() const {
	return ActorType::HUMAN;
}

void Human::setAction(const Field& field) {
	if (action != nullptr) {
		delete action;
	}
	// TODO: constante pas en dur
	action = new Move(1, *this);
}

void Human::display(const Displayer& displayer) const {
	displayer.displayHuman();
}
