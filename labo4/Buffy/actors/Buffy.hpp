//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include "Humanoid.hpp"

class Buffy : public Humanoid {
public:
	Buffy(unsigned x, unsigned y);

	char getSymbol() const override;
};

#endif // BUFFY_BUFFY_HPP
