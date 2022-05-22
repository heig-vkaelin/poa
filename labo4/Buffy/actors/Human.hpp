//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

class Human : public Humanoid {
public:
    Human(unsigned x, unsigned y);

	char getSymbol() const override;
};

#endif // BUFFY_HUMAN_HPP
