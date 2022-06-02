//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Action.hpp"
#include "../Field.hpp"

Action::Action(Humanoid& humanoid) : humanoid(&humanoid) {
}

Humanoid* Action::getHumanoid() {
	return humanoid;
}
