//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Humanoid.hpp"

class Vampire : public Humanoid {
public:
	Vampire(unsigned x, unsigned y);

	char getSymbol() const override;
};

#endif // BUFFY_VAMPIRE_HPP
