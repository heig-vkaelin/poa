//
// Created by Alexandre Jaquier on 19.05.2022.
//

#include "Utils.hpp"

unsigned int Utils::find_random_position(unsigned min, unsigned max) {
    return min + (rand() % max);
}