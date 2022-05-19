//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Humanoid.hpp"
#include "../Field.hpp"
#include "../Utils/Utils.hpp"

Humanoid::Humanoid(unsigned int maxWidth, unsigned int maxHeight) {
    x = Utils::find_random_position(0, maxWidth);
    y = Utils::find_random_position(0, maxHeight);
}

unsigned Humanoid::getXPos() const {
    return x;
}

unsigned Humanoid::getYPos() const {
    return y;
}