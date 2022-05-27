//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Vampire.hpp"
#include "ActorType.hpp"

Vampire::Vampire(unsigned x, unsigned y) : Humanoid(x, y) {}

ActorType Vampire::getType() const {
	return ActorType::VAMPIRE;
}

void Vampire::display(const Displayer& displayer) const {
	displayer.displayVampire();
}
