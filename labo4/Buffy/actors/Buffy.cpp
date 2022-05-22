//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Buffy.hpp"

Buffy::Buffy(unsigned x, unsigned y) : Humanoid(x, y) {}

ActorType Buffy::getType() const {
	return ActorType::BUFFY;
}
