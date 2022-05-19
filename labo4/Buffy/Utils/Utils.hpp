//
// Created by Alexandre Jaquier on 19.05.2022.
//

#ifndef BUFFY_UTILS_HPP
#define BUFFY_UTILS_HPP

#include <random>

class Utils {
public:
	static unsigned find_random_position(unsigned min, unsigned max);

	static unsigned getDistance(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
};

#endif // BUFFY_UTILS_HPP
