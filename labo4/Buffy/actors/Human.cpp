//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Human.hpp"

Human::Human(unsigned x, unsigned y) : Humanoid(x, y) {}

ActorType Human::getType() const {
	return ActorType::HUMAN;
}
