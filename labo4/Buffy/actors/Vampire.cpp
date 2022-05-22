//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Vampire.hpp"

Vampire::Vampire(unsigned x, unsigned y) : Humanoid(x, y) {}

char Vampire::getSymbol() const {
	return 'V';
}
