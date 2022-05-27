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
	// TODO: constante pas en dur
	delete action;
	action = new Move(2
		, this);
}
